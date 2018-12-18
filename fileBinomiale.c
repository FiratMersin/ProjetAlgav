#include "fileBinomiale.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "util.h"
#include "tournoisBinomial.h"

FB *createEmptyFileBinomiale()
{
	FB *file = (FB *)(malloc(sizeof(FB)));

	file->nbElement = 0;
	file->listTree = NULL;

	return file;
}

FB *ajout(FB *file, bigInt *element)
{

	element = copier(element);

	file->nbElement++;

	if (file->listTree == NULL)
	{
		file->listTree = createListArbreBinomial(createB0(element));
	}
	else
	{
		// L'element a ajouter.
		TB *eleToAdd = createB0(element);

		// On se place en debut de liste.
		// La liste est ordonne donc on va rencontrer TB0 en premier, puis TB1 (s'il existe),
		// puis TB2(s'il existe) et aisi de suite.
		listTB *ite = file->listTree;

		// Parcours de toute la file.
		while (ite != NULL)
		{
			// On regarde le TB.
			TB *tree = ite->data;

			if (tree->rank == eleToAdd->rank)
			{
				listTB *tmp = ite;
				// On merge les deux TB ensembles car ils ont le meme rang.
				// PB -> il ya une erreur de segmentation.
				// A cause de eleToAdd qui est cree dans la fonction ajout.
				// C'est tres bizarre.
				eleToAdd = merge(&eleToAdd, &tree);

				// On passe au suivant.
				ite = ite->next;

				if (ite != NULL)
				{
					// On supprime l'element de la liste.
					file->listTree = removeElement(&tmp);
				}
				else
				{
					// ICI ite->next est NULL donc on est en fin de liste.
					file->listTree = addAfter(&tmp, &eleToAdd);
					file->listTree = removeElement(&tmp);

					// Le break est inutil normalement car ite == NULL.
					break;
				}
			}
			else
			{
				// On ajoute le nouvelle element.
				file->listTree = addBefore(&ite, &eleToAdd);

				break;
			}
		}

		// On met a jour le pointer de la liste des tournois binomiaux.
		// Le pointeur doit toujours pointer au debut de la liste.
		if (file->listTree != NULL)
			while (file->listTree->previous != NULL)
			{
				file->listTree = file->listTree->previous;
			}
	}

	return file;
}

bigInt *supprMin(FB **file)
{

	listTB *ite = (*file)->listTree;

	listTB *min = ite;

	(*file)->nbElement--;

	// On cherche le minimum.
	while (ite != NULL)
	{
		bigInt *b = ite->data->data;

		if (inf(*b, *min->data->data))
		{
			min = ite;
		}

		ite = ite->next;
	}

	bigInt *bMin = min->data->data;
	TB *tbMin = min->data;

	// On supprime l'element de la liste des TB.
	removeElement(&min);

	// On decapite le TB.
	FB *fbDecapite = decapiteTB(&tbMin);

	// On unie les deux file.
	(*file) = unionFile(file, &fbDecapite);

	return bMin;
}

FB *constIter(bigInt *tabElement, int size)
{

	FBR *fbr = createEmptyFBR();

	int consolidation = 250;

	int i = 0;
	for (i = 0; i < size; i++)
	{
		bigInt *b = copier(&tabElement[i]);

		TB *tb0 = createB0(b);

		ajoutInFBR(&fbr, tb0);

		if (i % consolidation == 0 && i != 0)
		{
			consolider(&fbr);
		}
	}

	// On consolide une derniere fois.
	consolider(&fbr);

	return FBRToFB(&fbr);
}

FB *unionFile(FB **f0, FB **f1)
{
	return newU(f0, f1);
}

FB *oldU(FB **f0, FB **f1)
{
	// FB *fb = createEmptyFileBinomiale();

	listTB *iteF1 = (*f1)->listTree;

	// On ajoute chaque TB de f1
	// Que l'on supprime de f1 apres chaque ajout.
	while (iteF1 != NULL)
	{

		TB *elemToAdd = iteF1->data;

		listTB *iteF0 = (*f0)->listTree;

		while (iteF0 != NULL)
		{
			TB *currentElemF0 = iteF0->data;
			listTB *tempoAdd = NULL;

			if (elemToAdd->rank == currentElemF0->rank)
			{

				listTB *tmp = iteF0;

				// On doit passer au suivant avant de remove l'element.
				tempoAdd = iteF0;
				iteF0 = iteF0->next;

				// On se met sur le previous car iteF0 va etre remove.
				if (iteF0 == NULL)
				{

					tempoAdd = tempoAdd->previous;
				}

				elemToAdd = merge(&elemToAdd, &tmp->data);

				removeElement(&tmp);
			}
			else if (elemToAdd->rank < currentElemF0->rank)
			{

				// On a une place pour ajouter, aucun TB n'a le meme rang que nous dans la file F0.
				addBefore(&iteF0, &elemToAdd);

				break;
			}
			else
			{

				tempoAdd = iteF0;
				iteF0 = iteF0->next;
			}

			// Si on a pas pu s'ajoute alors qu'on est en fin de liste.
			if (iteF0 == NULL)
			{

				if (!tempoAdd)
				{

					(*f0)->listTree = createEmptyListTB();
					(*f0)->listTree->data = elemToAdd;
				}
				else
				{
					addAfter(&tempoAdd, &elemToAdd);
				}
			}
		}

		// On met a jour le pointer de la liste de f0.
		// Le pointeur doit toujours pointer au debut de la liste.
		if ((*f0)->listTree != NULL)
			while ((*f0)->listTree->previous != NULL)
			{
				(*f0)->listTree = (*f0)->listTree->previous;
			}

		// On a ajoute l'element de f1 on le supprime
		listTB *elemToDel = iteF1;
		iteF1 = iteF1->next;

		// On fait pas removeElement(iteF1->previous) car iteF1 peut etre NULL. (fin de liste).
		removeElement(&elemToDel);
	}

	(*f1)->nbElement = 0;
	(*f1)->listTree = NULL;

	return *f0;
}

FB *newU(FB **f0, FB **f1)
{

	int nb = (*f0)->nbElement + (*f1)->nbElement + 1;
	int nbEArray = (int)(log2(nb)) + 1;

	TB **array = (TB **)(malloc(sizeof(TB *) * nbEArray));

	int i = 0;
	for (i = 0; i < nbEArray; i++)
	{
		array[i] = NULL;
	}

	// On rempli le tableau de f0

	listTB *ite = (*f0)->listTree;

	if (ite != NULL)
	{

		TB *w = NULL;
		while (ite)
		{

			w = ite->data;

			// Comme c'est de FB on a pas plusieurs rank pareil.
			array[w->rank] = w;

			ite = ite->next;
		}

		// Ici le tableau est remplie.

		ite = (*f1)->listTree;

		w = NULL;
		while (ite)
		{

			w = ite->data;

			TB *t = array[w->rank];

			for (i = w->rank; i < nbEArray && array[i]; i++)
			{

				w = merge(&w, &array[i]);

				array[i] = NULL;
			}

			array[i] = w;

			ite = ite->next;
		}

		// Ici le array continet toute les valeurs merge.

		FB *res = createEmptyFileBinomiale();
		int nbE = 0;
		for (i = 0; i < nbEArray; i++)
		{
			if (array[i] != NULL)
			{
				nbE += (int)(pow(2, array[i]->rank));
				res->listTree = addAfterB(&res->listTree, &array[i]);
			}
		}

		while (res->listTree->previous)
		{
			res->listTree = res->listTree->previous;
		}

		res->nbElement = nbE;

		(*f0)->nbElement = 0;
		(*f0)->listTree = NULL;

		(*f1)->nbElement = 0;
		(*f1)->listTree = NULL;

		return res;
	}
	else
	{
		return (*f1);
	}

	return NULL;
}

void displayFB(FB *fb)
{
	listTB *list = fb->listTree;

	if (list != NULL)
	{

		printf("DEB_FB-------------------------------\n\n");

		printf("NBElement = %d\n", fb->nbElement);

		while (list != NULL)
		{

			TB *data = list->data;

			printf("%s\n", toStringTB(data));

			list = list->next;
		}

		printf("\nEND_FB-------------------------------\n\n");
	}
	else
	{
		printf("FB vide\n");
	}
}

// FBR

FBR *createEmptyFBR()
{
	FBR *file = (FBR *)(malloc(sizeof(FBR)));

	file->nbElement = 0;
	file->listTree = NULL;

	return file;
}

FBR *ajoutInFBRStatic(FBR **fbr, TB *tb)
{

	static int conso = 0;

	(*fbr) = ajoutInFBR(fbr, tb);

	conso++;

	if (conso % 250)
	{
		consolider(fbr);
	}

	return (*fbr);
}

FBR *ajoutInFBR(FBR **file, TB *tb)
{
	(*file)->nbElement += (int)pow(2, tb->rank);

	if ((*file)->listTree == NULL)
	{
		(*file)->listTree = createListArbreBinomial(tb);
	}
	else
	{
		(*file)->listTree = addAfter(&(*file)->listTree, &tb);
	}

	listTB *ite = (*file)->listTree;

	while (ite->previous)
	{
		ite = ite->previous;
	}

	(*file)->listTree = ite;

	return (*file);
}

FBR *ajoutInFBRNoTouchNBElement(FBR **file, TB *tb)
{
	if ((*file)->listTree == NULL)
	{
		(*file)->listTree = createListArbreBinomial(tb);
	}
	else
	{
		(*file)->listTree = addAfter(&(*file)->listTree, &tb);
	}

	listTB *ite = (*file)->listTree;

	while (ite->previous)
	{
		ite = ite->previous;
	}

	(*file)->listTree = ite;

	return (*file);
}

FBR *consolider(FBR **file)
{

	int nbTB = (int)(log2((*file)->nbElement) + 1);

	TB **arrayTB = (TB **)(malloc(sizeof(TB *) * (nbTB)));

	int i = 0;
	for (i = 0; i < nbTB; i++)
	{
		arrayTB[i] = NULL;
	}

	listTB *ite = (*file)->listTree;

	int j = 0;

	while (ite)
	{
		TB *w = ite->data;
		int rank = w->rank;

		TB *t = arrayTB[rank];

		for (i = rank; i < nbTB && arrayTB[i]; i++)
		{
			w = merge(&w, &arrayTB[i]);

			arrayTB[i] = NULL;
		}

		arrayTB[i] = w;

		listTB *next = ite->next;

		int element = (int)(pow(2, rank));

		(*file)->nbElement -= element;

		removeElement(&ite);

		ite = next;

		j++;
	}

	(*file)->listTree = NULL;

	for (i = 0; i < nbTB; i++)
	{
		if (arrayTB[i])
		{

			ajoutInFBR(file, arrayTB[i]);
		}
	}

	return *file;
}

FB *FBRToFB(FBR **fbr)
{
	FB *fb = createEmptyFileBinomiale();

	fb->nbElement = (*fbr)->nbElement;
	fb->listTree = (*fbr)->listTree;

	free(*fbr);

	return fb;
}

void displayFBR(FBR *fbr)
{
	listTB *list = fbr->listTree;

	if (list != NULL)
	{

		printf("\n\nDEB_FBR-------------------------------\n\n");

		while (list != NULL)
		{

			TB *data = list->data;

			printf("%s\n", toStringTB(data));

			list = list->next;
		}

		printf("\nEND_FBR-------------------------------\n\n");
	}
	else
	{
		printf("FBR vide\n");
	}
}

void freeFB(FB *fb)
{

	listTB *ite = fb->listTree;

	if (ite != NULL)
	{

		listTB *last = NULL;

		while (ite != NULL)
		{

			listTB *tmp = ite;

			if (tmp == NULL)
				last = ite;

			if (ite->previous != NULL)
				free(ite->previous);

			freeTB(ite->data);

			ite = tmp;
		}

		free(last);

		free(fb);
	}
	else
	{
		free(fb);
	}
}

void freeFBR(FBR *fbr)
{
	listTB *ite = fbr->listTree;

	if (ite != NULL)
	{

		listTB *last = NULL;

		while (ite != NULL)
		{

			listTB *tmp = ite;

			if (tmp == NULL)
				last = ite;

			if (ite->previous != NULL)
				free(ite->previous);

			freeTB(ite->data);

			ite = tmp;
		}

		free(last);

		free(fbr);
	}
	else
	{
		free(fbr);
	}
}
