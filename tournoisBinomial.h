#ifndef TOURNOIS_BINOMIAL_H
#define TOURNOIS_BINOMIAL_H

#define STRING_TB_SIZE 130

#include "util.h"

// Tournois binomiale.
typedef struct {

	int rank;

	struct TB* parent;
	struct listTB* listChild;

	bigInt* data;

} TB;

// Liste doublement chaine d'abre binomiaux
// Utile pour les fils des arbres.
typedef struct {

	struct listTB* previous;
	struct listTB* next;

	struct TB* data;

} listTB;

/*
Créé un arbre B0 avec une racine ayant pour data la data entree en parametres.
*/
TB* createB0(bigInt* data);

/*
Fusione 2 arbres binomiaux entre eux.

Les deux arbres doivent avoir le même rang sinon renvoie NULL.

Renvoie le pointeur sur la racine du nouvel arbre.
*/
//TB* merge(TB* a0, TB* a1);
TB* merge(TB** a0, TB** a1);

/*
Crée une list d'arbre binomial en initialisant le premier element avec la data entree en parametres.
*/
listTB* createListArbreBinomial(TB* data);

/*
Ajoute l'element avant l'element entre en parametre.
Si la liste pointe au niveau du milieu d'une liste, l'ajout se fait proprement et la liste reste integre avec le nouvel element.

Renvoie le pointeur list entre en parametres.
*/
listTB* addBefore(listTB* list, TB* element);

/*
Ajoute l'element après l'element entre en parametre.
Si la liste pointe au niveau du milieu d'une liste, l'ajout se fait proprement et la liste reste integre avec le nouvel element.

Renvoie le pointeur list entre en parametres.
*/
listTB* addAfter(listTB* list, TB* element);

/*
Supprime l'element de la liste dans laquelle il était.

Free la structure, mais pas ses elements.

Renvoie le pointeur sur l'element qui le precedait (previous). S'il n'y a pas d'element precedent,
renvoi le suivant, sinon renvoi NULL.
*/
//listTB* removeElement(listTB* element);
listTB* removeElement(listTB** element);

char* toStringTB(TB* tb);

#endif

