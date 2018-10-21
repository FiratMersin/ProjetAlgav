#include "arbreBinomial.h"

#include "util.h"

#include <stdio.h>
#include <stdlib.h>

arbreBinomial* createB0(bigInt* data) {

	arbreBinomial* a = (arbreBinomial*)(malloc(sizeof(arbreBinomial)));

	a->rank = 0;

	a->parent = NULL;
	a->listChild = NULL;
	
	a->data = data;

	return a;
}

arbreBinomial* merge(arbreBinomial* a0, arbreBinomial* a1) {

	arbreBinomial* root = NULL;
	arbreBinomial* child = NULL;

	// On regarde si les deux arbres on bien le même rang.
	if (a0->rank == a1->rank) {
		// On regarde qui sera la nouvelle racine.
		if (inf(*(a0->data), *(a1->data))) {
			root = a0;
			child = a1;
		}
		else {
			root = a1;
			child = a0;
		}

		// Assemblage.
		if (root->listChild == NULL) {
			root->listChild = createListArbreBinomial(child);
		}
		else {
			root->listChild = addElementToListBegin(root->listChild, child);
		}

		return root;
	}
	else
		return NULL;
}

listArbreBinomial* createListArbreBinomial(arbreBinomial* data) {
	listArbreBinomial* list = (listArbreBinomial*)(malloc(sizeof(listArbreBinomial)));

	list->previous = NULL;
	list->next = NULL;

	list->data = data;

	return list;
}

listArbreBinomial* addElementToListBegin(listArbreBinomial* list, arbreBinomial* element) {
	listArbreBinomial* ele = createListArbreBinomial(element);

	ele->previous = list->previous;

	if (list->previous != NULL) {
		listArbreBinomial* previous = ele->previous;
		previous->next = ele;
		// ele->previous->next = ele;
	}

	ele->next = list;

	list->previous = ele;

	return ele;
}
