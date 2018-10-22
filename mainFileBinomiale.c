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

	printf("Creation d'un B0\n");
	printf("BigInt = %s\n", toStringBigInt(i));
	TB* b0 = createB0(i);
	printf("TB0 = %s\n", toStringTB(b0));

	return 0;
}