#ifndef FILE_BINOMIALE_H
#define FILE_BINOMIALE_H

#include "util.h"
#include "tournoisBinomial.h"

// Cree une file binomiale vide.
FB *createEmptyFileBinomiale();

// Ajoute l'element a la file binomiale.
FB *ajout(FB *file, bigInt *element);

/* 
Supprime le plus petit element de la file binomiale.

Renvoie le minimum.
*/
bigInt *supprMin(FB **file);

FB *constIter(bigInt *tabElement, int size);

/*
Fait l'union de 2 files binomiales.

Renvoie la file binomiale resultante. 
(f0 et f1 en sortent inutilisables, f0 sera la file resultante, f1 sera vide).
*/
FB *unionFile(FB **f0, FB **f1);

void displayFB(FB *fb);

// FBR

FBR *createEmptyFBR();

FBR *ajoutInFBR(FBR **fbr, TB *tb);

FBR *ajoutInFBRNoTouchNBElement(FBR **fbr, TB *tb);

FBR *consolider(FBR **fbr);

/* 
Transforme la FBR en FB.
La FBR devient inutilisable.
*/
FB *FBRToFB(FBR **fbr);

void displayFBR(FBR *fbr);

#endif
