#include "fileBinomial.h"

#include "util.h"
#include "arbreBinomial.h"

fileBinomiale* createEmptyFileBinomiale() {
	fileBinomiale* file = (fileBinomiale*) (malloc(sizeof(fileBinomiale));

	file->nbElement = 0;
	file->listTree = NULL;

	return file;
}

fileBinomiale* ajout(fileBinomiale* file, bigInt* element) {
	if (file->listTree == NULL) {
		file->listTree = createListArbreBinomial(createB0(element));
	} else {
		arbreBinomial* treeElement = createB0(element);
	
		listArbreBinomial* ite = file->listTree;

		// Parcours de toute la file.
		while(ite != NULL) {
			arbreBinomial* tree = ite->data;
			if (tree->rank == 0) {
				// TODO
			}
		}
	}
}

fileBinomiale* supprMin(fileBinomiale* file) {
	// TODO
}
