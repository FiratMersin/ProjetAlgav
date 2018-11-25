#include "tasTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


bigInt SupprMin_t(tasTree **t){
	bigInt *supp = ((*t)->tas->value);
	(*t)->nbelem--;
	noeud **cible = getNode(t, 0);
	if((*t)->nbelem == 0){
		freeNode(cible);
		return *supp;
	}
	echanger_t( &((*t)->tas), cible);
	freeNode(cible);//on libère le noeud et cible = null
	descendre_t(&((*t)->tas));//on descend la racine
	return *supp;
}


void Ajout_t(tasTree **t, bigInt *add){
	noeud ** cible = getNode(t, 1);//on récupère le noeud vide le plus à gauche
	(*t)->nbelem++;
	(*cible)->value = copier(add);
	monter_t(cible);//on monte le noeud qu'on vient d'ajouter
}


void Ajout_sans_monter(tasTree **t, bigInt *add){
	noeud ** cible = getNode(t, 1);//on récupère le noeud vide le plus à gauche
	(*t)->nbelem++;
	(*cible)->value = copier(add);
}

void ConsIter_t(tasTree **t, bigInt **adds, int taille){
	int i;
	for(i = 0; i < taille; ++i){//on ajouter toutes les clés sans aucune comparaison entre clés
		Ajout_sans_monter(t, (adds[i]));
	}
	//on enregistre  nbelem
	int tmpnbelem = (*t)->nbelem;
	int nbelem = tmpnbelem;
	if(nbelem < 2){
		free(adds);
		return;
	}
	int h =  ((int)(log10(nbelem)/log10(2)));
	(*t)->nbelem = ((int)pow(2, h)) -1;
	//ensuite de hauteur-1 à la racine, pour chaque niveau
	//on applique la fonction descendre du noeud le plus a droite au noeud le plus a gauche
	while((*t)->nbelem != 0){
		(*t)->nbelem--;
		noeud **cible = getNode(t, 0);
		descendre_t(cible);
	}
	(*t)->nbelem = tmpnbelem;
	free(adds);
}

void ajouter_all_sans_monter(tasTree **t, noeud *n){
	if(n != NULL){
		Ajout_sans_monter(t , n->value);
		ajouter_all_sans_monter(t, n->fg);
		ajouter_all_sans_monter(t, n->fd);
	}
}

tasTree *Union_t(tasTree *t1, tasTree *t2){//à implémenter en O(n+m) n+m = nb de BigInt de t1 + t2
	tasTree *t = init_t(t1->nbelem + t2->nbelem);
	ajouter_all_sans_monter(&t, t1->tas);
	ajouter_all_sans_monter(&t, t2->tas);

	int tmpnbelem = t->nbelem;
	int nbelem = tmpnbelem;
	if(nbelem < 2){
		return t;
	}
	int h =  ((int)(log10(nbelem)/log10(2)));
	t->nbelem = ((int)pow(2, h)) -1;
	//ensuite de hauteur-1 à la racine, pour chaque niveau
	//on applique la fonction descendre du noeud le plus a droite au noeud le plus a gauche
	while(t->nbelem != 0){
		t->nbelem--;
		noeud **cible = getNode(&t, 0);
		descendre_t(cible);
	}
	t->nbelem = tmpnbelem;
	return t;
}



void initNoeud(noeud **n, noeud *pere){
	*n = (noeud *)malloc(sizeof(noeud));
	(*n)->fd = NULL;
	(*n)->fg = NULL;
	(*n)->value = NULL;
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

tasTree *getFromFile_t(FILE *f, int taille){//union des deux moitier du fichier
	 char str[101];
	 int  taillem2 = (int)(taille/2);
	 bigInt **tab1=(bigInt**)malloc(sizeof(bigInt*)*taillem2);
	 bigInt **tab2=(bigInt**)malloc(sizeof(bigInt*)*taillem2);
	 int i;
	 tasTree *t1 = init_t(taillem2);
	 tasTree *t2 = init_t(taillem2);
	 for(i=0; i<taillem2; ++i){
		 GetChaine(f, 100, str);
		 tab1[i] = creerBigInt(str);
	 }
	 ConsIter_t(&t1 ,tab1, taillem2);


	 for(i=0; i<taillem2; ++i){
		 GetChaine(f, 100, str);
		 tab2[i] = creerBigInt(str);
	 }
	 ConsIter_t(&t2 ,tab2, taillem2);
	 tasTree *uni = Union_t(t1, t2);
	 return uni;
}


void echanger_t(noeud **n, noeud **t){//On échange seulement la valeur des noeuds
	bigInt *tmp = (*n)->value;
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
noeud **getNode(tasTree **t, int cas){//1 = ajout 0 = suppr (ou recuperer un noeud existant) //si cas = 1 alors initialisé le noeud cible avant de le retourner.
	noeud **cur = &((*t)->tas);
	noeud **pere;
	int nbelem = (*t)->nbelem;
	if(nbelem == 0) return cur;//on retourne la racine
	int h = ((int)(log10(nbelem+1)/log10(2))) +1;
	int c = nbelem - ((int) pow(2, h -1)) + 1;//nb elements au dernier niveau de l'arbre
	int max = (int)pow(2,h-1);//nb elements max au dernier niveau de l'arbre
	while(h > 1){
		pere = cur;
		int midmax = max / 2;
		//go to fg si c < midmax, sinon go to fd
		if(c < midmax){
			cur = &((*cur)->fg);
		}else{
			cur = &((*cur)->fd);
			c = c - midmax;//on va dans le sous arbre de droit donc le dernier niveau de l'arbre contient à présent c - midmax éléments
		}
		max = midmax;
		h--;
	}
	if(c == 0){//je suis dans une feuille vide
			if(cas) initNoeud(cur, *pere);
	}else{//sinon je vais à gauche
		pere = cur;
		cur = &((*cur)->fg);
		if(cas) initNoeud(cur, *pere);
	}
	return cur;
}

void monter_t(noeud **n){//monter au père jusqu'à la racine ou stop juste avant un père plus petit
	if(hasPere_t(*n)){
		if(  (! inf( *((*n)->pere->value), *((*n)->value)) )
			  && (! eg( *((*n)->pere->value), *((*n)->value) ) )){
			echanger_t(n, &((*n)->pere));
			monter_t(&((*n)->pere));//récursion sur pere
		}
	}
}

void descendre_t(noeud **n){//descend tant que différent d'une feuille et au moins un fils plus petitS
	if(! estFeuille_t(*n)){
		noeud ** filsmin=plusPetitFils_t(*n);
		if( inf( *((*filsmin)->value) , *((*n)->value)) ){
			echanger_t(filsmin, n);
			descendre_t(filsmin);//récursion sur filsmin
		}
	}
}

int hasPere_t(noeud *n){
	return n->pere != NULL;
}

noeud **plusPetitFils_t(noeud *n){
	if(! hasFilsDroit_t(n)){
		return &(n->fg);
	}else{
		return ( inf( *(n->fg->value) , *(n->fd->value)) ) ? &(n->fg) : &(n->fd);
	}
}

int estFeuille_t(noeud *n){
	return ( ! hasFilsGauche_t(n) ) && ( ! hasFilsDroit_t(n) );
}


void afficheArbre(noeud *n){
	if(n != NULL){
		afficheBigInt(n->value);
		afficheArbre(n->fg);
		afficheArbre(n->fd);

	}
}
