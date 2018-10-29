#include <stdlib.h>
#include <stdio.h>

#include "util.h"
#include "tournoisBinomial.h"
#include "fileBinomiale.h"
#include "fileReader.h"

int main(int argc, char **argv)
{

	char *filename = "cles_alea/jeu_1_nb_cles_50000.txt";
	FILE *f = fopen(filename, "r");
	FILE *f1 = fopen("cles_alea/jeu_2_nb_cles_50000.txt", "r");

	char line[101];

	GetChaine(f, 100, line);
	bigInt *bi0 = creerBigInt(line);

	GetChaine(f1, 100, line);
	bigInt *bi1 = creerBigInt(line);

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Creation d'un B0\n");

	printf("BigInt = %s\n", toStringBigInt(bi0));

	TB *b0 = createB0(bi0);
	printf("TB0 = %s\n", toStringTB(b0));

	TB *b01 = createB0(bi1);
	printf("TB01 = %s\n", toStringTB(b01));

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Creation d'une FB\n");

	FB *fb0 = createEmptyFileBinomiale();
	FB *fb1 = createEmptyFileBinomiale();
	displayFB(fb0);
	displayFB(fb1);

	printf("Ajout de b dans fb0\n");
	ajout(fb0, bi0);
	displayFB(fb0);

	printf("Ajout de b dans fb1\n");
	ajout(fb1, bi1);
	displayFB(fb1);

	printf("\n\n\n**************************************************************************************\n\n\n");

	int i = 0;

	for (i = 0; i < 49999; i++)
	{
		GetChaine(f, 100, line);
		bi0 = creerBigInt(line);
		fb0 = ajout(fb0, bi0);
	}

	for (i = 0; i < 49999; i++)
	{
		GetChaine(f1, 100, line);
		bi1 = creerBigInt(line);
		fb1 = ajout(fb1, bi1);
	}

	printf("Apres 49_999 ajout\n");

	printf("FB0 = ");
	displayFB(fb0);

	printf("FB1 = ");
	displayFB(fb1);

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("Union de FB0 et FB1\n");

	FB *fbUnion = unionFile(&fb0, &fb1);

	printf("FBUnion = ");
	displayFB(fbUnion);

	fclose(f);
	fclose(f1);

	printf("\n\n\n**************************************************************************************\n\n\n");

	printf("On enleve le minimum\n");

	bigInt* bMin = supprMin(&fbUnion);

	printf("bMin = %s\n", toStringBigInt(bMin));

	displayFB(fbUnion);

	return 0;
}