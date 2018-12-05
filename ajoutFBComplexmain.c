#include "util.h"
#include "AVL.h"
#include "tasTree.h"
#include "tasTab.h"
#include "fromFile.h"
#include <string.h>
#include <time.h>
#include <math.h>
#include "tournoisBinomial.h"
#include "fileBinomiale.h"
#include "fileReader.h"

int main(int argc, char** argv) {


	 //100 200 500 1000 10000 20000 50000 100000 250000
	int i, j;
	clock_t temps_initial;
	clock_t temps_final;
	double temps_cpu;
	char str[101];
	int taille;

	FILE *filebi1;
	FILE *filebi2;
	FILE *filebi3;
	FILE *filebi4;
	FILE *filebi5;
	FILE *resfile = fopen(argv[1], "w");

	FB* resFB = createEmptyFileBinomiale();

	bigInt** a = (bigInt**)(malloc(sizeof(bigInt*) * 5));

	a[0] = (bigInt *)(malloc(sizeof(bigInt) * 250000));
	a[1]= (bigInt *)(malloc(sizeof(bigInt) * 250000));
	a[2] = (bigInt *)(malloc(sizeof(bigInt) * 250000));

	a[3] = (bigInt *)(malloc(sizeof(bigInt) * 250000));
	a[4] = (bigInt *)(malloc(sizeof(bigInt) * 250000));

	////////////////////////////////////////////////////////////////////////////////////////

	filebi1 = fopen("cles_alea/jeu_1_nb_cles_100.txt", "r");
	filebi2 = fopen("cles_alea/jeu_2_nb_cles_100.txt", "r");
	filebi3 = fopen("cles_alea/jeu_3_nb_cles_100.txt", "r");
	filebi4 = fopen("cles_alea/jeu_4_nb_cles_100.txt", "r");
	filebi5 = fopen("cles_alea/jeu_5_nb_cles_100.txt", "r");

	taille = 100;

	for(i=0; i<taille; ++i){
		GetChaine(filebi1, 100, str);
		a[0][i] = * (creerBigInt(str));

		GetChaine(filebi2, 100, str);
		a[1][i] = * (creerBigInt(str));

		GetChaine(filebi3, 100, str);
		a[2][i] = * (creerBigInt(str));

		GetChaine(filebi4, 100, str);
		a[3][i] = * (creerBigInt(str));

		GetChaine(filebi5, 100, str);
		a[4][i] = * (creerBigInt(str));
	}

	temps_initial = clock();

	for (j = 0; j < 5; j++) {
	 	for (i = 0; i < taille; i++) {
	 		resFB = ajout(resFB, a[j]);
		}

		resFB = createEmptyFileBinomiale();
	}

	temps_final = clock();
	temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

	temps_cpu /= 5.0;

	fprintf(resfile, "%d %f\n", taille,temps_cpu);

	fclose(filebi1);
	fclose(filebi2);
	fclose(filebi3);
	fclose(filebi4);
	fclose(filebi5);

		////////////////////////////////////////////////////////////////////////////////////////

	filebi1 = fopen("cles_alea/jeu_1_nb_cles_200.txt", "r");
	filebi2 = fopen("cles_alea/jeu_2_nb_cles_200.txt", "r");
	filebi3 = fopen("cles_alea/jeu_3_nb_cles_200.txt", "r");
	filebi4 = fopen("cles_alea/jeu_4_nb_cles_200.txt", "r");
	filebi5 = fopen("cles_alea/jeu_5_nb_cles_200.txt", "r");

	taille = 200;

	for(i=0; i<taille; ++i){
		GetChaine(filebi1, 100, str);
		a[0][i] = * (creerBigInt(str));

		GetChaine(filebi2, 100, str);
		a[1][i] = * (creerBigInt(str));

		GetChaine(filebi3, 100, str);
		a[2][i] = * (creerBigInt(str));

		GetChaine(filebi4, 100, str);
		a[3][i] = * (creerBigInt(str));

		GetChaine(filebi5, 100, str);
		a[4][i] = * (creerBigInt(str));
	}

	temps_initial = clock();

	for (j = 0; j < 5; j++) {
	 	for (i = 0; i < taille; i++) {
	 		resFB = ajout(resFB, a[j]);
		}

		resFB = createEmptyFileBinomiale();
	}

	temps_final = clock();
	temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

	temps_cpu /= 5.0;

	fprintf(resfile, "%d %f\n", taille,temps_cpu);

	fclose(filebi1);
	fclose(filebi2);
	fclose(filebi3);
	fclose(filebi4);
	fclose(filebi5);

		////////////////////////////////////////////////////////////////////////////////////////

	filebi1 = fopen("cles_alea/jeu_1_nb_cles_500.txt", "r");
	filebi2 = fopen("cles_alea/jeu_2_nb_cles_500.txt", "r");
	filebi3 = fopen("cles_alea/jeu_3_nb_cles_500.txt", "r");
	filebi4 = fopen("cles_alea/jeu_4_nb_cles_500.txt", "r");
	filebi5 = fopen("cles_alea/jeu_5_nb_cles_500.txt", "r");

	taille = 500;

	for(i=0; i<taille; ++i){
		GetChaine(filebi1, 100, str);
		a[0][i] = * (creerBigInt(str));

		GetChaine(filebi2, 100, str);
		a[1][i] = * (creerBigInt(str));

		GetChaine(filebi3, 100, str);
		a[2][i] = * (creerBigInt(str));

		GetChaine(filebi4, 100, str);
		a[3][i] = * (creerBigInt(str));

		GetChaine(filebi5, 100, str);
		a[4][i] = * (creerBigInt(str));
	}

	temps_initial = clock();

	for (j = 0; j < 5; j++) {
	 	for (i = 0; i < taille; i++) {
	 		resFB = ajout(resFB, a[j]);
		}

		resFB = createEmptyFileBinomiale();
	}

	temps_final = clock();
	temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

	temps_cpu /= 5.0;

	fprintf(resfile, "%d %f\n", taille,temps_cpu);

	fclose(filebi1);
	fclose(filebi2);
	fclose(filebi3);
	fclose(filebi4);
	fclose(filebi5);

		////////////////////////////////////////////////////////////////////////////////////////

	filebi1 = fopen("cles_alea/jeu_1_nb_cles_1000.txt", "r");
	filebi2 = fopen("cles_alea/jeu_2_nb_cles_1000.txt", "r");
	filebi3 = fopen("cles_alea/jeu_3_nb_cles_1000.txt", "r");
	filebi4 = fopen("cles_alea/jeu_4_nb_cles_1000.txt", "r");
	filebi5 = fopen("cles_alea/jeu_5_nb_cles_1000.txt", "r");

	taille = 1000;

	for(i=0; i<taille; ++i){
		GetChaine(filebi1, 100, str);
		a[0][i] = * (creerBigInt(str));

		GetChaine(filebi2, 100, str);
		a[1][i] = * (creerBigInt(str));

		GetChaine(filebi3, 100, str);
		a[2][i] = * (creerBigInt(str));

		GetChaine(filebi4, 100, str);
		a[3][i] = * (creerBigInt(str));

		GetChaine(filebi5, 100, str);
		a[4][i] = * (creerBigInt(str));
	}

	temps_initial = clock();

	for (j = 0; j < 5; j++) {
	 	for (i = 0; i < taille; i++) {
	 		resFB = ajout(resFB, a[j]);
		}

		resFB = createEmptyFileBinomiale();
	}

	temps_final = clock();
	temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

	temps_cpu /= 5.0;

	fprintf(resfile, "%d %f\n", taille,temps_cpu);

	fclose(filebi1);
	fclose(filebi2);
	fclose(filebi3);
	fclose(filebi4);
	fclose(filebi5);

		////////////////////////////////////////////////////////////////////////////////////////

	filebi1 = fopen("cles_alea/jeu_1_nb_cles_10000.txt", "r");
	filebi2 = fopen("cles_alea/jeu_2_nb_cles_10000.txt", "r");
	filebi3 = fopen("cles_alea/jeu_3_nb_cles_10000.txt", "r");
	filebi4 = fopen("cles_alea/jeu_4_nb_cles_10000.txt", "r");
	filebi5 = fopen("cles_alea/jeu_5_nb_cles_10000.txt", "r");

	taille = 10000;

	for(i=0; i<taille; ++i){
		GetChaine(filebi1, 100, str);
		a[0][i] = * (creerBigInt(str));

		GetChaine(filebi2, 100, str);
		a[1][i] = * (creerBigInt(str));

		GetChaine(filebi3, 100, str);
		a[2][i] = * (creerBigInt(str));

		GetChaine(filebi4, 100, str);
		a[3][i] = * (creerBigInt(str));

		GetChaine(filebi5, 100, str);
		a[4][i] = * (creerBigInt(str));
	}

	temps_initial = clock();

	for (j = 0; j < 5; j++) {
	 	for (i = 0; i < taille; i++) {
	 		resFB = ajout(resFB, a[j]);
		}

		resFB = createEmptyFileBinomiale();
	}

	temps_final = clock();
	temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

	temps_cpu /= 5.0;

	fprintf(resfile, "%d %f\n", taille,temps_cpu);

	fclose(filebi1);
	fclose(filebi2);
	fclose(filebi3);
	fclose(filebi4);
	fclose(filebi5);

		////////////////////////////////////////////////////////////////////////////////////////

	filebi1 = fopen("cles_alea/jeu_1_nb_cles_20000.txt", "r");
	filebi2 = fopen("cles_alea/jeu_2_nb_cles_20000.txt", "r");
	filebi3 = fopen("cles_alea/jeu_3_nb_cles_20000.txt", "r");
	filebi4 = fopen("cles_alea/jeu_4_nb_cles_20000.txt", "r");
	filebi5 = fopen("cles_alea/jeu_5_nb_cles_20000.txt", "r");

	taille = 20000;

	for(i=0; i<taille; ++i){
		GetChaine(filebi1, 100, str);
		a[0][i] = * (creerBigInt(str));

		GetChaine(filebi2, 100, str);
		a[1][i] = * (creerBigInt(str));

		GetChaine(filebi3, 100, str);
		a[2][i] = * (creerBigInt(str));

		GetChaine(filebi4, 100, str);
		a[3][i] = * (creerBigInt(str));

		GetChaine(filebi5, 100, str);
		a[4][i] = * (creerBigInt(str));
	}

	temps_initial = clock();

	for (j = 0; j < 5; j++) {
	 	for (i = 0; i < taille; i++) {
	 		resFB = ajout(resFB, a[j]);
		}

		resFB = createEmptyFileBinomiale();
	}

	temps_final = clock();
	temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

	temps_cpu /= 5.0;

	fprintf(resfile, "%d %f\n", taille,temps_cpu);

	fclose(filebi1);
	fclose(filebi2);
	fclose(filebi3);
	fclose(filebi4);
	fclose(filebi5);

		////////////////////////////////////////////////////////////////////////////////////////

	filebi1 = fopen("cles_alea/jeu_1_nb_cles_50000.txt", "r");
	filebi2 = fopen("cles_alea/jeu_2_nb_cles_50000.txt", "r");
	filebi3 = fopen("cles_alea/jeu_3_nb_cles_50000.txt", "r");
	filebi4 = fopen("cles_alea/jeu_4_nb_cles_50000.txt", "r");
	filebi5 = fopen("cles_alea/jeu_5_nb_cles_50000.txt", "r");

	taille = 50000;

	for(i=0; i<taille; ++i){
		GetChaine(filebi1, 100, str);
		a[0][i] = * (creerBigInt(str));

		GetChaine(filebi2, 100, str);
		a[1][i] = * (creerBigInt(str));

		GetChaine(filebi3, 100, str);
		a[2][i] = * (creerBigInt(str));

		GetChaine(filebi4, 100, str);
		a[3][i] = * (creerBigInt(str));

		GetChaine(filebi5, 100, str);
		a[4][i] = * (creerBigInt(str));
	}

	temps_initial = clock();

	for (j = 0; j < 5; j++) {
	 	for (i = 0; i < taille; i++) {
	 		resFB = ajout(resFB, a[j]);
		}

		resFB = createEmptyFileBinomiale();
	}

	temps_final = clock();
	temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

	temps_cpu /= 5.0;

	fprintf(resfile, "%d %f\n", taille,temps_cpu);

	fclose(filebi1);
	fclose(filebi2);
	fclose(filebi3);
	fclose(filebi4);
	fclose(filebi5);

	return 0;
}