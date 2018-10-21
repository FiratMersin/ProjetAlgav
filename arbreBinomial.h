#ifndef ARBRE_BINOMIAL_H
#define ARBRE_BINOMIAL_H

#include "util.h"

// Arbre binomial.
typedef struct arbreBinomial arbreBinomial;
struct {

	int rank;

	arbreBinomial* parent;
	struct listArbreBinomial* listChild;

	bigInt* data;

};

// Liste doublement chaine d'abre binomiaux
// Utile pour les fils des arbres.
typedef struct listArbreBinomial listArbreBinomial;
struct {

	listArbreBinomial* previous;
	listArbreBinomial* next;

	arbreBinomial* data;

};

/*
Créé un arbre B0 avec une racine ayant pour data la data entree en parametres.
*/
arbreBinomial* createB0(bigInt* data);

/*
Fusione 2 arbres binomiaux entre eux.

Les deux arbres doivent avoir le même rang sinon renvoie NULL.

Renvoie le pointeur sur la racine du nouvel arbre.
*/
arbreBinomial* merge(arbreBinomial* a0, arbreBinomial* a1);

/*
Crée une list d'arbre binomial en initialisant le premier element avec la data entree en parametres.
*/
listArbreBinomial* createListArbreBinomial(arbreBinomial* data);

/*
Ajoute l'element devant la liste.
Si la liste pointe au niveau du milieu d'une liste, l'ajout se fait proprement et la liste reste integre avec le nouvel element.

Renvoie le pointeur sur le bloque contenant le nouvel element.
*/
listArbreBinomial* addElementToListBegin(listArbreBinomial* list, arbreBinomial* element);

#endif // !ARBRE_BINOMIAL_H

