#include "fileBinomiale.h"

#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "tournoisBinomial.h"

FB* createEmptyFileBinomiale() {
	FB* file = (FB*) (malloc(sizeof(FB)));

	file->nbElement = 0;
	file->listTree = NULL;

	return file;
}

FB* ajout(FB* file, bigInt* element) {
	if (file->listTree == NULL) {
		file->listTree = createListArbreBinomial(createB0(element));
	} else {
		// L'element a ajouter.
		TB* eleToAdd = createB0(element);
	
		// On se place en debut de liste.
		// La liste est ordonne donc on va rencontrer TB0 en premier, puis TB1 (s'il existe), 
		// puis TB2(s'il existe) et aisi de suite.
		listTB* ite = file->listTree;

		// Parcours de toute la file.
		while(ite != NULL) {
			// On regarde le TB.
			TB* tree = ite->data;

			if (tree->rank == eleToAdd->rank) {
				listTB* tmp = ite;

				// On merge les deux TB ensembles car ils ont le meme rang.
				TB* eleToAdd = merge(eleToAdd, tree);

				ite = ite->next;

				// On supprime l'element de la liste.
				removeElement(tmp);
			} else {
				// On ajoute le nouvelle element.
				addBefore(ite, eleToAdd);
				break;
			}
		}

		// On met a jour le pointer de la liste des tournois binomiaux.
		// Le pointeur doit toujours pointer au debut de la liste.
		while(file->listTree->previous != NULL)
			file->listTree = file->listTree->previous;
	}

	return file->listTree;
}

FB* supprMin(FB* file) {
	// TODO
	return NULL;
}

FB* constIter(FB* file, bigInt* tabElement, int size) {
	// TODO
	return NULL;
}

FB* unionFile(FB* f0, FB* f1) {
	// TODO
	return NULL;
}
