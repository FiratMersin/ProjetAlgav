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

	file->nbElement++;

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
				// PB -> il ya une erreur de segmentation.
				// A cause de eleToAdd qui est cree dans la fonction ajout.
				// C'est tres bizarre.
				eleToAdd = merge(&eleToAdd, &tree);

				// On passe au suivant.
				ite = ite->next;

				if (ite != NULL) {
					// On supprime l'element de la liste.
					file->listTree = removeElement(&tmp);
				} else {
					// ICI ite->next est NULL donc on est en fin de liste.
					file->listTree = addAfter(tmp, eleToAdd);
					file->listTree = removeElement(&tmp);

					// Le break est inutil normalement car ite == NULL.
					break;
				}
			} else {
				// On ajoute le nouvelle element.
				file->listTree = addBefore(ite, eleToAdd);
				break;
			}
		}

		// On met a jour le pointer de la liste des tournois binomiaux.
		// Le pointeur doit toujours pointer au debut de la liste.
		if (file->listTree != NULL)
			while(file->listTree->previous != NULL) {
				file->listTree = file->listTree->previous;
			}
	}

	return file;
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

void displayFB(FB* fb) {
	listTB* list = fb->listTree;

	if (list != NULL) {

		printf("\n\nDEB_FB-------------------------------\n\n");

		while (list != NULL) {

			TB* data = list->data;

			printf("%s\n", toStringTB(data));

			list = list->next;
		}

		printf("\nEND_FB-------------------------------\n\n");
	} else {
		printf("FB vide\n");
	}
}
