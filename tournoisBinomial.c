#include "tournoisBinomial.h"

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

TB* createB0(bigInt* data) {

	TB* a = (TB*)(malloc(sizeof(TB)));

	a->rank = 0;

	a->parent = NULL;
	a->listChild = NULL;
	
	a->data = data;

	return a;
}

TB* merge(TB* a0, TB* a1) {
	TB* root = NULL;
	TB* child = NULL;

	printf("a0 = %p\n", a0);
	printf("a1 = %p\n", a1);

	printf("a0->rank = %d\n", a0->rank);
	printf("a1->rank = %d\n", a1->rank);

	// On regarde si les deux arbres on bien le même rang.
	if (a0->rank == a1->rank) {

		printf("LADEDANS\n");

		// On regarde qui sera la nouvelle racine.
		if (inf(*a0->data, *a1->data)) {
			root = a0;
			child = a1;
		}
		else {
			root = a1;
			child = a0;
		}

		// Assemblage.
		if (root->listChild == NULL) {
			printf("OOPS\n");
			root->listChild = createListArbreBinomial(child);
		}
		else {
			printf("LA\n");
			root->listChild = addAfter(root->listChild, child);
		}

		root->rank++;

		child->parent = root;

		return root;
	}
	else {
		printf("DANS LA MOUISE\n");
		return NULL;
	}
}

listTB* createListArbreBinomial(TB* data) {
	listTB* list = (listTB*)(malloc(sizeof(listTB)));

	list->previous = NULL;
	list->next = NULL;

	list->data = data;

	return list;
}

listTB* addBefore(listTB* list, TB* element) {
	listTB* ele = createListArbreBinomial(element);

	ele->next = list;

	if (list->previous != NULL) {
		listTB* previous = list->previous;
		previous->next = ele;
	}

	ele->previous = list->previous;

	list->previous = ele;

	return list;
}

listTB* addAfter(listTB* list, TB* element) {
	listTB* ele = createListArbreBinomial(element);

	ele->previous = list;

	if (list->next != NULL) {
		listTB* next = list->next;
		next->previous = ele;
	}

	ele->next = list->next;

	list->next = ele;

	return list;
}

listTB* removeElement(listTB* element) {

	listTB* tmpP = element->previous;
	listTB* tmpN = element->next;

	if (element->previous != NULL) {
		listTB* previous = element->previous;
		previous->next = element->next;
	}

	if (element->next != NULL) {
		listTB* next = element->next;
		next->previous = element->previous;
	}

	element->previous = NULL;
	element->next = NULL;

	free(element);

	if (tmpP != NULL)
		return tmpP;
	else if (tmpN != NULL)
		return tmpN;
	else
		return NULL;
}

char* toStringTB(TB* tb) {
	char* array = (char*)(malloc(sizeof(char) * STRING_TB_SIZE));

	sprintf(array, "[TB_%d, data = %s]", tb->rank, toStringBigInt(tb->data));

	return array;
}
