#ifndef AVL_H
#define AVL_H

#include "util.h"

typedef struct nd{
	struct nd *pere;

	struct nd *fg;
	struct nd *fd;

	int hauteur;//0, -1, 1
	bigInt *value;
	int estDoublon;
	char *hashWord;//pour la partie 6 (question optionnelle)
} noeudAvl;

typedef struct{
	noeudAvl *racine;
	int nbelem;
}AVL;

AVL *createAVL();//retourne un AVL vide
noeudAvl *createNoeud(bigInt *value, char* hasWord, noeudAvl *pere);
void setNoeud(noeudAvl **nd, bigInt* value, char *hashWord);

int AjoutAVL(AVL **avl, bigInt *value, char *hasWord);//retourne 1 ou 2 si ajout d'un mot dupliqué, 0 sinon
//int AjoutNoeud(noeudAvl **nd, bigInt *value, char *hasWord);

int Rechercher(AVL *avl, bigInt *value);

void rotationDroite(AVL **avl, noeudAvl **nd);
void rotationGauche(AVL **avl, noeudAvl **nd);

void eqAjout(AVL **avl, noeudAvl **nd);//equilibre l'AVL après un ajout

void eqNoeud(AVL **avl, noeudAvl **pere, noeudAvl **nd);//equilbre un noeudAvl

void setHauteur(noeudAvl **nd, int newhauteur);//n'a pas d'effet si (*nd) est NULL
int getHauteur(noeudAvl *nd);//retourne 0 si nd == NULL

int getDiffHauteur(noeudAvl *nd);//retourne la difference de hauteur entre le fils droit et le fils gauche de nd

int max(int x, int y);

void afficheAVLInfixe(AVL *avl);

#endif




