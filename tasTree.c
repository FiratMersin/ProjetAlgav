#include "tasTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


////////////////////////////////////////

bigInt SupprMin_t(tasTree **t){//OK
	bigInt supp = ((*t)->tas->value);
	(*t)->nbelem--;
	noeud **cible = getNode(t, 0);
	if((*t)->nbelem == 0){
		freeNode(cible);
		return supp;
	}
	echanger_t( &((*t)->tas), cible);
	freeNode(cible);
	noeud **n;
	noeud **tmp = &((*t)->tas);
	do{
		n = tmp;
		tmp = descendre_t(n);
	}while(tmp != n);
	return supp;
}


void Ajout_t(tasTree **t, bigInt *add){//OK
	noeud ** cible = getNode(t, 1);
	(*t)->nbelem++;
	(*cible)->value = *add;
	noeud **tmp = cible;
	do{
		cible = tmp;
		tmp = monter_t(cible);
	}while(tmp != cible);
}


tasTree * ConsIter_t(bigInt *adds, int taille){//à implémenter en O(n), n = nb de BigInt a ajouter
	tasTree *t = init_t(taille);
	int i;
	for(i = 0; i < taille; ++i){
		Ajout_t(&t, &(adds[i]));
	}
	return t;
}



tasTree *Union_t(tasTree *t1, tasTree *t2){//à implémenter en O(n+m) n+m = nb de BigInt de t1 + t2
	tasTree *t = init_t(1);
	return t;
}

//////////////////////////////////////


void initNoeud(noeud **n, noeud *pere){
	*n = (noeud *)malloc(sizeof(noeud));
	(*n)->fd = NULL;
	(*n)->fg = NULL;
	(*n)->pere = pere;
}

void freeNode(noeud **n){
	free(*n);
	*n = NULL;
}

tasTree *init_t(int taillemax){
	tasTree *t = (tasTree *)malloc(sizeof(tasTree));
	t->nbelem = 0;
	t->nbmax = taillemax;
	initNoeud(&(t->tas), NULL);
	return t;
}

tasTree *getFromFile_t(FILE *f, int taille){//initialise un tasTree à partir d'un fichier
	 char str[101];
	 int i;
	 tasTree *t = init_t(taille);
	 for(i=0; i<taille; ++i){
		 GetChaine(f, 100, str);
		 Ajout_t(&t, creerBigInt(str));
	 }
	 return t;
}

void echanger_t(noeud **n, noeud **t){//On échange seulement la valeur des noeuds
	bigInt tmp = (*n)->value;
	(*n)->value = (*t)->value;
	(*t)->value = tmp;
}

int hasFilsGauche_t(noeud *n){
	return n->fg != NULL;
}

int hasFilsDroit_t(noeud *n){
	return n->fd != NULL;
}

//faire nbelem-- avant d'appeler dans supprimerMin pour récupérer le noeud plein le plus à gauche
//sinon retourne le noeud vide le plus à gauche dans l'arbre
noeud **getNode(tasTree **t, int cas){//1 = ajout 0 = suppr //si cas = 1 alors initialisé le noeud cible avec de le retourner.
	noeud **cur = &((*t)->tas);
	noeud **pere;
	int nbelem = (*t)->nbelem;
	if(nbelem == 0) return cur;//on retourne la racine
	int h = ((int)(log10(nbelem+1)/log10(2))) +1;
	int c = nbelem - ((int) pow(2, h -1)) + 1;//nb elements au dernier niveau de l'arbre
	int max = (int)pow(2,h-1);//nb elements max au dernier niveau de l'arbre
	while(h > 1){//CONDITION DARRET A CHANGER POUR TOUT CORRIGER
		pere = cur;
		int midmax = max / 2;
		//go to fg si c < midmax, sinon go to fd
		if(c < midmax){
			cur = &((*cur)->fg);
		}else{
			cur = &((*cur)->fd);
			c = c - midmax;
		}
		max = midmax;
		h--;
	}if(c == 0){
			if(cas) initNoeud(cur, *pere);
	}else{
		pere = cur;
		cur = &((*cur)->fg);
		if(cas) initNoeud(cur, *pere);
	}
	return cur;
}

noeud ** monter_t(noeud **n){
	if(! hasPere_t(*n)) return n;
	if(  (! inf( ((*n)->pere->value), ((*n)->value)) )
		  && (! eg( ((*n)->pere->value), ((*n)->value) ) )){
		echanger_t(n, &((*n)->pere));
		return &((*n)->pere);
	}
	return n;
}

noeud ** descendre_t(noeud **n){
	if(estFeuille_t(*n))return n;
	noeud ** filsmin=plusPetitFils_t(*n);
	if( inf( ((*filsmin)->value) , ((*n)->value)) ){
		echanger_t(filsmin, n);
		return filsmin;
	}
	return n;
}

int hasPere_t(noeud *n){
	return n->pere != NULL;
}

noeud **plusPetitFils_t(noeud *n){
	if(! hasFilsDroit_t(n)){
		return &(n->fg);
	}else{
		return ( inf( (n->fg->value) , (n->fd->value)) ) ? &(n->fg) : &(n->fd);
	}
}

int estFeuille_t(noeud *n){
	return ( ! hasFilsGauche_t(n) ) && ( ! hasFilsDroit_t(n) );
}


void afficheArbre(noeud *n, int h){
	if(n != NULL){
		afficheBigInt(&(n->value));
		afficheArbre(n->fg,h+1);
		afficheArbre(n->fd, h+1);

	}
}
