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
	bigInt* i = creerBigInt(line);

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Creation d'un B0\n");

	printf("BigInt = %s\n", toStringBigInt(i));

	TB* b0 = createB0(i);
	printf("TB0 = %s\n", toStringTB(b0));

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Creation d'une FB\n");

	printf("BigInt = %s\n", toStringBigInt(i));

	FB* fb = createEmptyFileBinomiale();
	displayFB(fb);

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

	return 0;
}