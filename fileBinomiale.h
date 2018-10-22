#ifndef FILE_BINOMIALE_H
#define FILE_BINOMIALE_H

#include "util.h"
#include "tournoisBinomial.h"

// Une file binomial.
typedef struct {

	int nbElement;
	
	/*
	Liste de TB.
	Pointe toujours sur le debut de la liste.
	*/
	listTB* listTree;
	
	// TODO
} FB;

// Cree une file binomiale vide.
FB* createEmptyFileBinomiale();

// Ajoute l'element a la file binomiale.
FB* ajout(FB* file, bigInt* element);

// Supprime le plus petit element de la file binomiale.
FB* supprMin(FB* file);

FB* constIter(FB* file, bigInt* tabElement, int size);

// Fait l'union de 2 files binomiales.
FB* unionFile(FB* f0, FB* f1);

#endif
