#ifndef FROMFILE_H
#define FROMFILE_H

#include "util.h"
#include "AVL.h"
#include "tasTree.h"
#include "tasTab.h"

//fonction de construction à partir d'un fichier

tasTree *getTasTreeFromFile(FILE *f, int taille);//construit un tastree a partir d'un fichier contenant des entier hexa
tasTab *getTasTabFromFile(FILE *f, int taille);//construit un tastab a partir d'un fichier contenant des entier hexa


// *worldList contient les mots uniques du texte (dans leur ordre d'apparition)
// *nbWord représente le nombre de mots uniques ( == taille de *wordList)
AVL *getAVLFromFile(FILE *f, char ***wordList, int *nbWord);//construit un AVL a partir d'un fichier contenant des chaines de caracteres


#endif
