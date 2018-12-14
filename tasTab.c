#include "tasTab.h"
#include <stdio.h>
#include <stdlib.h>

bigInt SupprMin(tasTab *t){
	echanger(t, racine(), t->nbelem);
	bigInt *suppr = t->tab[t->nbelem];
	t->nbelem--;
	descendre(t, racine());
	return *suppr;
}

void Ajout(tasTab *t, bigInt *add){
	if(t->nbelem == t->nbmax){
		printf("Erreur : insertion dans un tasTab plein !");
		exit(0);
	}
	t->nbelem++;//augmente le nombre d'élément dans le tas
	t->tab[t->nbelem] = copier(add);//on place le nouvel élément dans la première feuille vide
	monter(t, t->nbelem);
}

void Ajoutsans_monter(tasTab *t, bigInt *add){
	if(t->nbelem == t->nbmax){
			printf("Erreur : insertion dans un tasTab plein !");
			exit(0);
	}
	t->nbelem++;
	t->tab[t->nbelem] = copier(add);
}

void ConsIter(tasTab **t, bigInt **adds, int taille){
	int i;
	for(i = 0; i < taille; ++i){
		Ajoutsans_monter(*t, adds[i]);
	}
	if((*t)->nbelem < 2){
		return;
	}
	int h =  ((int)(log10((*t)->nbelem)/log10(2)));
	int nbelem = ((int)pow(2, h)) -1;
	for(i = nbelem; i >0; i--){
		descendre(*t, i);
	}
}

tasTab *Union(tasTab *t1, tasTab *t2){
	tasTab *tu = init(t1->nbmax + t2->nbmax);
	int i;
	if(t1->nbelem == t2->nbelem){
		for(i = 1; i<=t1->nbelem; i++){
			Ajoutsans_monter(tu, t1->tab[i]);
			Ajoutsans_monter(tu, t2->tab[i]);
		}
	}else{
		for(i = 1; i<=t1->nbelem; i++){
			Ajoutsans_monter(tu, t1->tab[i]);
		}
		for(i = 1; i<=t2->nbelem; i++){
			Ajoutsans_monter(tu, t2->tab[i]);
		}
	}
	int h =  ((int)(log10(tu->nbelem)/log10(2)));
	int nbelem = ((int)pow(2, h)) -1;
	for(i = nbelem; i >=0; i--){
		descendre(tu, i);
	}
	return tu;
}



tasTab *init(int nbmax){
	tasTab *t = (tasTab*)malloc(sizeof(tasTab));
	t->nbmax = nbmax;
	t->nbelem = 0;
	t->tab = (bigInt **)malloc(sizeof(bigInt*) * (nbmax +1));
	return t;

}

void freeTasTab(tasTab *t){
	if(t != NULL){
		free(t->tab);
		free(t);
	}
}

int racine(){
	return 1;
}

void echanger(tasTab *t, int j, int k){
	bigInt *tmp = t->tab[j];
	t->tab[j] = t->tab[k];
	t->tab[k] = tmp;
}

int hasPere(int i){
	return i != racine();
}

int filsGauche(int i){
	return 2*i;
}

int filsDroit(int i){
	return 2*i+1;
}

int isNoeud(tasTab *t, int i){
	if(i > 0 && i <= t->nbelem)
			return 1;
		return 0;
}

int hasFilsGauche(tasTab *t, int i){
	return isNoeud(t,filsGauche(i));
}

int hasFilsDroit(tasTab *t, int i){
	return isNoeud(t,filsDroit(i));
}

int estFeuille(tasTab *t, int i){
	return ! hasFilsGauche(t,i);
}

int plusPetitFils(tasTab *t, int i){// avant d'utiliser cette fonction tester si on n'est pas sur une feuille !
	if(! hasFilsDroit(t,i)){
			return filsGauche(i);
		}else{
			int fg=filsGauche(i);// fg = indice
			int fd=filsDroit(i);// fd = indice
			return ( inf( *(t->tab[fg]) , *(t->tab[fd])) ) ? fg : fd;
		}
}

int pere(int i){
	if(i==racine()){
			printf("Appel de la fonction pere pour la racine\n");
			return 0;
		}
		return i/2;
}

void monter(tasTab *t, int j){//retourne le nouvelle indice de l'élément à la position j
	if(hasPere(j)){
		int p=pere(j);// p = indice
		if(  (! inf( *(t->tab[p]), *(t->tab[j])) )
		  && (! eg( *(t->tab[p]), *(t->tab[j])) )){
			echanger(t,j,p);
			monter(t, p);
		}
	}
}

void descendre(tasTab *t, int j){//retourne le nouvelle indice de l'élément à la position j
	if(! estFeuille(t,j)){
		int filsmin=plusPetitFils(t,j);// filsmin = indice
		if( inf( *(t->tab[filsmin]) , *(t->tab[j])) ){
			echanger(t,filsmin,j);
			descendre(t, filsmin);
		}
	}
}
/*
tasTab *getFromFile(FILE *f, int taille){
	 char str[101];
	 bigInt **tab=(bigInt**)malloc(sizeof(bigInt*)*taille);
	 int i;
	 tasTab *t= init(taille);
	 for(i=0; i<taille; ++i){
		 GetChaine(f, 100, str);
		 tab[i] = creerBigInt(str);
		 //Ajout(t, *(creerBigInt(str)));
	 }
	 ConsIter(&t, tab, taille);
	 return t;
}
*/

tasTab *getFromFile(FILE *f, int taille){
	 char str[101];
	 int  taillem2 = (int)(taille/2);
	 bigInt **tab1=(bigInt**)malloc(sizeof(bigInt*)*taillem2);
	 bigInt **tab2=(bigInt**)malloc(sizeof(bigInt*)*taillem2);
	 int i;
	 tasTab *t1 = init(taillem2);
	 tasTab *t2 = init(taillem2);
	 for(i=0; i<taillem2; ++i){
		 GetChaine(f, 100, str);
		 tab1[i] = creerBigInt(str);
	 }
	 ConsIter(&t1 ,tab1, taillem2);


	 for(i=0; i<taillem2; ++i){
		 GetChaine(f, 100, str);
		 tab2[i] = creerBigInt(str);
	 }
	 ConsIter(&t2 ,tab2, taillem2);
	 tasTab *uni = Union(t1, t2);
	 return uni;
}

