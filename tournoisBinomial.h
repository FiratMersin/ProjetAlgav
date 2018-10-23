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

// Une file binomial.
// Declare ici pour plus de facilite.
typedef struct {

	// nombre d'elements de la file.
	int nbElement;
	
	/*
	Liste de TB.
	Pointe toujours sur le debut de la liste.
	*/
	listTB* listTree;
	
	// TODO
} FB;

/*
Cr�� un arbre B0 avec une racine ayant pour data la data entree en parametres.
*/
TB* createB0(bigInt* data);

/*
Fusione 2 arbres binomiaux entre eux.

Les deux arbres doivent avoir le m�me rang sinon renvoie NULL.

Renvoie le pointeur sur la racine du nouvel arbre.
*/
//TB* merge(TB* a0, TB* a1);
TB* merge(TB** a0, TB** a1);

/*
Creer une liste vide. (tous les champs a NULL).
*/
listTB* createEmptyListTB();

/*
Cr�e une list d'arbre binomial en initialisant le premier element avec la data entree en parametres.
*/
listTB* createListArbreBinomial(TB* data);

/*
Ajoute l'element avant l'element entre en parametre.
Si la liste pointe au niveau du milieu d'une liste, l'ajout se fait proprement et la liste reste integre avec le nouvel element.

Renvoie le pointeur list entre en parametres.
*/
listTB* addBefore(listTB* list, TB* element);

/*
Ajoute l'element apr�s l'element entre en parametre.
Si la liste pointe au niveau du milieu d'une liste, l'ajout se fait proprement et la liste reste integre avec le nouvel element.

Renvoie le pointeur list entre en parametres.
*/
listTB* addAfter(listTB* list, TB* element);

/*
Supprime l'element de la liste dans laquelle il �tait.

Free la structure, mais pas ses elements.

Renvoie le pointeur sur l'element qui le precedait (previous). S'il n'y a pas d'element precedent,
renvoi le suivant, sinon renvoi NULL.
*/
//listTB* removeElement(listTB* element);
listTB* removeElement(listTB** element);

/*
Decapite le TB. Le TB devient un TB_0 (on peut donc toujours recuperer ca racine).

Sa liste est copi� puis liberee.

Renvoie la file binomiale des TB contenu sous la racine.
*/
FB* decapiteTB(TB** tb);

char* toStringTB(TB* tb);

#endif

