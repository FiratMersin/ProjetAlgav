#include <stdlib.h>
#include <stdio.h>

#include "util.h"
#include "tournoisBinomial.h"
#include "fileBinomiale.h"
#include "fileReader.h"

int main(int argc, char** argv) {

	char *filename = "cles_alea/jeu_1_nb_cles_50000.txt";
	FILE *f = fopen(filename, "r");

	char line[101];

	GetChaine(f, 100, line);
	bigInt* b = creerBigInt(line);

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Creation d'un B0\n");

	printf("BigInt = %s\n", toStringBigInt(b));

	TB* b0 = createB0(b);
	printf("TB0 = %s\n", toStringTB(b0));


	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Creation d'une FB\n");

	printf("BigInt = %s\n", toStringBigInt(b));

	FB* fb = createEmptyFileBinomiale();
	displayFB(fb);

	printf("Ajout de b dans fb\n");
	ajout(fb, b);

	displayFB(fb);

	printf("\n\n\n**************************************************************************************\n\n\n");

	for (int i = 0; i < 49999; i++) {
		GetChaine(f, 100, line);
		b = creerBigInt(line);
		fb = ajout(fb, b);
	}

	printf("Apres 49_999 ajout\n");
	displayFB(fb);

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Test de decapitation de TB_15 \n");

	listTB* current = fb->listTree;

	// On va jusqu'au dernier element.
	while (current->next != NULL) {
		current = current->next;
	}

	printf("TB sur lequel on est = %s\n", toStringTB(current->data));

	// Va defonce la FB
	FB* file = decapiteTB(&(current->data));

	printf("file = \n");
	displayFB(file);

	printf("\n\n\ncurrent = %s\n", toStringTB(current->data));

	printf("fb = \n");
	displayFB(fb);

	return 0;
}