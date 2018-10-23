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

/*
	fb = ajout(fb, i);
	displayFB(fb);

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Ajout d'un autre element dans la FB\n");

	GetChaine(f, 100, line);
	i = creerBigInt(line);

	printf("New BigInt = %s\n", toStringBigInt(i));

	printf("\nFB avant ajout d'un autre element:\n");
	displayFB(fb);

	printf("\nFB apres ajout d'un autre element:\n");
	// BEUG (voir explication dans fileBinomiale.c -> ajout)
	fb = ajout(fb, i);
	displayFB(fb);

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Ajout d'un autre element dans la FB\n");

	GetChaine(f, 100, line);
	i = creerBigInt(line);

	printf("New BigInt = %s\n", toStringBigInt(i));

	printf("\nFB avant ajout d'un autre element:\n");
	displayFB(fb);

	printf("\nFB apres ajout d'un autre element:\n");
	// BEUG (voir explication dans fileBinomiale.c -> ajout)
	fb = ajout(fb, i);
	displayFB(fb);

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Ajout d'un autre element dans la FB\n");

	GetChaine(f, 100, line);
	i = creerBigInt(line);

	printf("New BigInt = %s\n", toStringBigInt(i));

	printf("\nFB avant ajout d'un autre element:\n");
	displayFB(fb);

	printf("\nFB apres ajout d'un autre element:\n");
	// BEUG (voir explication dans fileBinomiale.c -> ajout)
	fb = ajout(fb, i);
	displayFB(fb);

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Ajout d'un autre element dans la FB\n");

	GetChaine(f, 100, line);
	i = creerBigInt(line);

	printf("New BigInt = %s\n", toStringBigInt(i));

	printf("\nFB avant ajout d'un autre element:\n");
	displayFB(fb);

	printf("\nFB apres ajout d'un autre element:\n");
	// BEUG (voir explication dans fileBinomiale.c -> ajout)
	fb = ajout(fb, i);
	displayFB(fb);
*/

	return 0;
}