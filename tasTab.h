#ifndef TASTAB_H
#define TASTAB_H

#include "util.h" 
#include "fileReader.h"

typedef struct	{
	int nbmax;
	int nbelem;	
	bigInt *tab;//tab est de taille nbmax+1, la racine est à l'indice 1
}tasTab;	


////fonctions fondamentales////

bigInt SupprMin(tasTab *t);

void Ajout(tasTab *t, bigInt add);

tasTab * ConsIter(bigInt *adds, int taille);

tasTab *Union(tasTab *t1, tasTab *t2);

///////////////////////////////

tasTab *getFromFile(FILE *f, int taille);

tasTab *init(int nbmax);
void freeTasTab(tasTab *t);
int racine();//retourne 1
void echanger(tasTab *t, int j, int k);
int hasPere(int i);
int filsGauche(int i);
int filsDroit(int i);
int isNoeud(tasTab *t, int i);
int hasFilsGauche(tasTab *t, int i);
int hasFilsDroit(tasTab *t, int i);
int estFeuille(tasTab *t, int i);
int plusPetitFils(tasTab *t, int i);
int pere(int i);
int monter(tasTab *t, int j);
int descendre(tasTab *t, int j);



#endif
