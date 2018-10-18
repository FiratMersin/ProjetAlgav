#include "tasTab.h"
#include <stdio.h>
#include <stdlib.h>

bigInt SupprMin(tasTab *t){
	echanger(t, racine(), t->nbelem);
	bigInt suppr = t->tab[t->nbelem];
	t->nbelem--;
	int indDesc;
	int tmp = racine();
	do{
		indDesc = tmp;
		tmp = descendre(t, indDesc);
	}while(tmp != indDesc);
	return suppr;
}

void Ajout(tasTab *t, bigInt add){
	if(t->nbelem == t->nbmax){
		printf("Erreur : insertion dans un tasTab plein !");
		exit(0);
	}
	t->nbelem++;//augmente le nombre d'élément dans le tas
	t->tab[t->nbelem] = *(copier(add));//on place le nouvel élément dans la première feuille vide
	int indAdd;
	int tmp = t->nbelem;
	do{
		indAdd = tmp;
		tmp = monter(t, indAdd);
	}while(tmp != indAdd);//on monte tant que monter change l'indice de add
}

tasTab * ConsIter(bigInt *adds, int taille){//a modifier
	tasTab *t = init(taille);
	int i;
	for(i = 0; i < taille; ++i){
		Ajout(t, adds[i]);
	}
	return t;
}

tasTab *Union(tasTab *t1, tasTab *t2){
	tasTab *tu = init(t1->nbmax + t2->nbmax);
	tasTab *u1, *u2;
	if(t1->nbmax > t2->nbmax){
		u1 = t1;
		u2 = t2;
	}else{
		u1 = t2;
		u2 = t1;
	}
	//on copie les éléments de u1 dans tu puis on ajoute les éléments de u2 dans tu
	int i;
	for(i = 1; i <= u1->nbelem; ++i){
		tu->tab[i] = *(copier(u1->tab[i]));
	}
	for(i = 1; i <= u2->nbelem; i++){
		Ajout(tu, u2->tab[i]);
	}
	return tu;
}

//////////////////////////////////////


tasTab *init(int nbmax){
	tasTab *t = (tasTab*)malloc(sizeof(tasTab));
	t->nbmax = nbmax;
	t->nbelem = 0;
	t->tab = (bigInt *)malloc(sizeof(bigInt) * (nbmax +1));
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
	bigInt tmp = t->tab[j];
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
			return ( inf(t->tab[fg] , t->tab[fd]) ) ? fg : fd;
		}
}

int pere(int i){
	if(i==racine()){
			printf("Appel de la fonction pere pour la racine\n");
			return 0;
		}
		return i/2;
}

int monter(tasTab *t, int j){//retourne le nouvelle indice de l'élément à la position j
	if(! hasPere(j)) return j;
	int p=pere(j);// p = indice
	if(  (! inf(t->tab[p],t->tab[j]) )
	  && (! eg(t->tab[p],t->tab[j]) )){
		echanger(t,j,p);
		return p;
	}
	return j;
}

int descendre(tasTab *t, int j){//retourne le nouvelle indice de l'élément à la position j
	if(estFeuille(t,j))return j;
	int filsmin=plusPetitFils(t,j);// filsmin = indice
	if( inf(t->tab[filsmin] , t->tab[j]) ){
		echanger(t,filsmin,j);
		return filsmin;
	}
	return j;
}

tasTab *getFromFile(FILE *f, int taille){
	 char str[101];
	 int i;
	 tasTab *t = init(taille);
	 for(i=0; i<taille; ++i){
		 GetChaine(f, 100, str);
		 Ajout(t, *(creerBigInt(str)));
	 }
	 return t;
}


