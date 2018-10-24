#ifndef TASTREE_H
#define TASTREE_H

#include "util.h"
#include "fileReader.h"

typedef struct	tasT{
	struct tasT *pere;
	struct tasT *fg;//fils gauche
	struct tasT *fd;//fils droit
	bigInt value;
}noeud;

typedef struct{
	noeud *tas;//racine de l'arbre
	int nbmax;
	int nbelem;//nombre d'éléments dans l'arbre
}tasTree;

////fonctions fondamentales////

bigInt SupprMin_t(tasTree **t);

void Ajout_t(tasTree **t, bigInt *add);

void ConsIter_t(tasTree **t, bigInt **adds, int taille);

tasTree *Union_t(tasTree *t1, tasTree *t2);

///////////////////////////////

tasTree *getFromFile_t(FILE *f, int taille);

void initNoeud(noeud **n, noeud *pere);
void freeNode(noeud **n);
tasTree *init_t(int nbmax);

noeud **getNode(tasTree **t, int cas);
void echanger_t(noeud **n, noeud **t);
int hasPere_t(noeud *n);
int hasFilsGauche_t(noeud *n);
int hasFilsDroit_t(noeud *n);
int estFeuille_t(noeud *n);
noeud **plusPetitFils_t(noeud *n);
void monter_t(noeud **n);
void descendre_t(noeud **n);

void Ajout_sans_monter(tasTree **t, bigInt *add);//pour ConsIter et Union

void afficheArbre(noeud *n);

#endif

