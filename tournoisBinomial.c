#include "tournoisBinomial.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "util.h"
#include "fileBinomiale.h"

TB *createB0(bigInt *data)
{

	TB *a = (TB *)(malloc(sizeof(TB)));

	a->rank = 0;

	a->parent = NULL;
	a->listChild = NULL;

	a->data = data;

	return a;
}

TB *merge(TB **a0, TB **a1)
{
	TB *root = NULL;
	TB *child = NULL;

	// On regarde si les deux arbres on bien le m�me rang.
	if ((*a0)->rank == (*a1)->rank)
	{

		// On regarde qui sera la nouvelle racine.
		if (inf((*(*a0)->data), (*(*a1)->data)))
		{
			root = (*a0);
			child = (*a1);
		}
		else
		{
			root = (*a1);
			child = (*a0);
		}

		// Assemblage.
		if (root->listChild == NULL)
		{
			root->listChild = createListArbreBinomial(child);
		}
		else
		{
			root->listChild = addAfter(&root->listChild, &child);
		}

		root->rank++;

		child->parent = root;

		return root;
	}
	else
	{
		return NULL;
	}
}

listTB *createEmptyListTB()
{
	listTB *l = (listTB *)(malloc(sizeof(listTB)));

	l->previous = NULL;
	l->next = NULL;
	l->data = NULL;

	return l;
}

listTB *createListArbreBinomial(TB *data)
{
	listTB *list = (listTB *)(malloc(sizeof(listTB)));

	list->previous = NULL;
	list->next = NULL;

	list->data = data;

	return list;
}

listTB *addBefore(listTB **list, TB **element)
{
	listTB *ele = createListArbreBinomial((*element));

	ele->next = (*list);

	if ((*list)->previous != NULL)
	{
		listTB *previous = (*list)->previous;
		previous->next = ele;
	}

	ele->previous = (*list)->previous;

	(*list)->previous = ele;

	return (*list);
}

listTB *addAfter(listTB **list, TB **element)
{
	listTB *ele = createListArbreBinomial((*element));

	ele->previous = (*list);

	if ((*list)->next != NULL)
	{
		listTB *next = (*list)->next;
		next->previous = ele;
	}

	ele->next = (*list)->next;

	(*list)->next = ele;

	return (*list);
}

listTB *removeElement(listTB **element)
{

	listTB *tmpP = (*element)->previous;
	listTB *tmpN = (*element)->next;

	if ((*element)->previous != NULL)
	{
		listTB *previous = (*element)->previous;
		previous->next = (*element)->next;
	}

	if ((*element)->next != NULL)
	{
		listTB *next = (*element)->next;
		next->previous = (*element)->previous;
	}

	(*element)->previous = NULL;
	(*element)->next = NULL;

	free((*element));

	if (tmpP != NULL)
		return tmpP;
	else if (tmpN != NULL)
		return tmpN;
	else
		return NULL;
}

FB *decapiteTB(TB **tb)
{
	// La file qui va contenir les sous tournois binomaux.
	FB *fb = createEmptyFileBinomiale();

	// On regarde s'il le tournoiis n'est pas compose que d'une racine.
	if ((*tb)->rank > 0)
	{

		fb->nbElement = (int)(pow(2, (*tb)->rank));

		// La file du tournois.
		listTB *ltb = (*tb)->listChild;

		int i = 0;
		listTB *tmp = NULL;
		while (ltb != NULL)
		{
			listTB *l = createEmptyListTB();

			if (i == 0)
			{

				l->previous = NULL;

				// Pas de copie de data.
				l->data = ltb->data;

				fb->listTree = l;

				tmp = l;
			}
			else
			{

				// On fait le double chainage.
				l->previous = tmp;
				tmp->next = l;

				l->data = ltb->data;

				tmp = l;
			}

			ltb = ltb->next;

			i++;
		}

		// Transformation en TB_0
		(*tb)->rank = 0;
		(*tb)->listChild = NULL;
	}

	return fb;
}

listTB **listTBToArray(listTB *tb)
{

	listTB *current = tb;

	// On cherche le rang maximal.
	int maxRank = -1;

	while (current != NULL)
	{
		if (current->data->rank > maxRank)
			maxRank = current->data->rank;

		current = current->next;
	}

	// On cree notre tableau de listTB.

	listTB **arrayListTB = (listTB **)(malloc(sizeof(listTB *) * maxRank));

	for (listTB **ite = arrayListTB; ite != arrayListTB + maxRank; ite++)
	{
		*ite = NULL;
	}

	// On renmpli notre tableau.
	current = tb;

	while (current != NULL)
	{

		arrayListTB[current->data->rank] = current;

		current = current->next;
	}

	return arrayListTB;
}

char *toStringTB(TB *tb)
{
	char *array = (char *)(malloc(sizeof(char) * STRING_TB_SIZE));

	sprintf(array, "[TB_%d, root_data = %s]", tb->rank, toStringBigInt(tb->data));

	return array;
}
