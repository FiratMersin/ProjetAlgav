#ifndef TOURNOIS_BINOMIAL_H
#define TOURNOIS_BINOMIAL_H

#define STRING_TB_SIZE 130

#include "util.h"

// Tournois binomiale.
typedef struct tournoisB
{ //on nomme la struct avant pour faire pointer des champs vers soi-meme en utilisant ce nom !

	int rank;

	struct tournoisB *parent;
	struct lTB *listChild; //ici on met un pointeur vers struct lTB car la listTB est d�finit apr�s (�tant donn� qu'un pointeur n�cessite
						   //toujours la meme quantit� de m�moire on sait ce qu'il faut allouer pour stocker *listChild)

	bigInt *data;

} TB; //on renomme la structure et on utilise ce nom l� dans les structures d�clar� par la suite

// Liste doublement chaine d'abre binomiaux
// Utile pour les fils des arbres.
typedef struct lTB
{

	struct lTB *previous;
	struct lTB *next;

	TB *data; //ici on met TB* car la on connait le type qui a ete definit juste avant

} listTB;

// Une file binomial.
// Declare ici pour plus de facilite.
typedef struct
{

	// nombre d'elements de la file.
	int nbElement;

	/*
	Liste de TB.
	Pointe toujours sur le debut de la liste.
	*/
	listTB *listTree;
} FB;

typedef struct
{
	int nbElement;

	/*
	Liste de TB.
	Point toujours sur le debut de la liste.
	Les TB peuvent avoir les memes degre.
	*/
	listTB *listTree;
} FBR;

/*
Cree un arbre B0 avec une racine ayant pour data la data entree en parametres.
*/
TB *createB0(bigInt *data);

/*
Fusione 2 arbres binomiaux entre eux.

Les deux arbres doivent avoir le meme rang sinon renvoie NULL.

Renvoie le pointeur sur la racine du nouvel arbre.
*/
TB *merge(TB **a0, TB **a1);

/*
Creer une liste vide. (tous les champs a NULL).
*/
listTB *createEmptyListTB();

/*
Cree une list d'arbre binomial en initialisant le premier element avec la data entree en parametres.
*/
listTB *createListArbreBinomial(TB *data);

/*
Ajoute l'element avant l'element entre en parametre.
Si la liste pointe au niveau du milieu d'une liste, l'ajout se fait proprement et la liste reste integre avec le nouvel element.

Renvoie le pointeur list entre en parametres.
*/
listTB *addBefore(listTB **list, TB **element);

/*
Ajoute beaucoup mieux et renvoie l'element ajouté.
*/
listTB *addBeforeB(listTB **list, TB **element);

/*
Ajoute l'element apres l'element entre en parametre.
Si la liste pointe au niveau du milieu d'une liste, l'ajout se fait proprement et la liste reste integre avec le nouvel element.

Renvoie le pointeur list entre en parametres.
*/
listTB *addAfter(listTB **list, TB **element);

/*
Ajoute beaucoup mieux et renvoie l'element ajouté.
*/
listTB *addAfterB(listTB **list, TB **element);

/*
Supprime l'element de la liste dans laquelle il etait.

Free la structure, mais pas ses elements.

Renvoie le pointeur sur l'element qui le precedait (previous). S'il n'y a pas d'element precedent,
renvoi le suivant, sinon renvoi NULL.
*/
listTB *removeElement(listTB **element);

/*
Decapite le TB. Le TB devient un TB_0 (on peut donc toujours recuperer ca racine).

Sa liste est copie puis liberee.

Renvoie la file binomiale des TB contenu sous la racine.
*/
FB *decapiteTB(TB **tb);

/*
Creer un tableau de pointeurs de listTB à partir de la listTB.

Renvoie un tableau de pointeurs de listTB.

ex: listTB contenant TB0, TB2, TB6 -> arrayTB = [&TB0, NULL, &TB2, NULL, NULL, NULL, &TB6].
*/
listTB **listTBToArray(listTB *tb);

char *toStringTB(TB *tb);

void freeElemListTB(listTB* elem);

/*Libere le tb.*/
void freeTB(TB *tb);

#endif
