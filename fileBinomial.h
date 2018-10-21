#ifndef FILE_BINOMIAL_H
#define FILE_BINOMIAL_H

#include "util.h"
#include "arbreBinomial.h"

// Une file binomial.
typedef struct fileBinomiale fileBinomiale;
struct fileBinomiale {

	int nbElement;
	
	listArbreBinomial* listTree;
	// TODO
};

// Cree une file binomiale vide.
fileBinomiale* createEmptyFileBinomiale();

// Ajoute l'element a la file binomiale.
fileBinomiale* ajout(fileBinomial* file, bigInt* element);

// Supprime le plus petit element de la file binomiale.
fileBinomiale* supprMin(fileBinomiale* file);

fileBinomiale* constIter(fileBinomiale* file, bigInt* tabElement, int size);

// Fait l'union de 2 files binomiales.
fileBinomiale* unionFile(fileBinomiale* f0, fileBinomiale* f1);

#endif
