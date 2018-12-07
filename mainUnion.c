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

    clock_t temps_initial;
	clock_t temps_final;
    double temps_cpu;

    char str1[101];
    char str2[101];
    char str3[101];
    char str4[101];
    char str5[101];

    FILE *resfile = fopen(argv[1], "w");

    FB *fb1_1;
    FB *container_1;

    FB *fb1_2;
    FB *container_2;

    FB *fb1_3;
    FB *container_3;

    FB *fb1_4;
    FB *container_4;

    FB *fb1_5;
    FB *container_5;


    for(int i = 1; i <= 15; i++) {
        fb1_1 = createEmptyFileBinomiale();
        container_1 = createEmptyFileBinomiale();

        fb1_2 = createEmptyFileBinomiale();
        container_2 = createEmptyFileBinomiale();

        fb1_3 = createEmptyFileBinomiale();
        container_3 = createEmptyFileBinomiale();

        fb1_4 = createEmptyFileBinomiale();
        container_4 = createEmptyFileBinomiale();

        fb1_5 = createEmptyFileBinomiale();
        container_5 = createEmptyFileBinomiale();


        FILE *file_1_50_000 = fopen("cles_alea/jeu_1_nb_cles_50000.txt", "r");
        FILE *file_2_50_000 = fopen("cles_alea/jeu_2_nb_cles_50000.txt", "r");
        FILE *file_3_50_000 = fopen("cles_alea/jeu_3_nb_cles_50000.txt", "r");
        FILE *file_4_50_000 = fopen("cles_alea/jeu_4_nb_cles_50000.txt", "r");
        FILE *file_5_50_000 = fopen("cles_alea/jeu_5_nb_cles_50000.txt", "r");

        for (int j = 0; j < pow(2, i); j++) {
            GetChaine(file_1_50_000, 100, str1);
            bigInt *b1 = creerBigInt(str1);

            GetChaine(file_2_50_000, 100, str2);
            bigInt *b2 = creerBigInt(str1);

            GetChaine(file_3_50_000, 100, str3);
            bigInt *b3 = creerBigInt(str1);

            GetChaine(file_4_50_000, 100, str4);
            bigInt *b4 = creerBigInt(str1);

            GetChaine(file_5_50_000, 100, str5);
            bigInt *b5 = creerBigInt(str1);


            if (j == 0) {
               fb1_1 = ajout(fb1_1, b1);
               fb1_2 = ajout(fb1_2, b2);
               fb1_3 = ajout(fb1_3, b3);
               fb1_4 = ajout(fb1_4, b4);
               fb1_5 = ajout(fb1_5, b5);
            } else {
                container_1 = ajout(container_1, b1);
                container_2 = ajout(container_2, b2);
                container_3 = ajout(container_3, b3);
                container_4 = ajout(container_4, b4);
                container_5 = ajout(container_5, b5);
            }
        }

        temps_initial = clock();
        unionFile(&container_1, &fb1_1);
        unionFile(&container_2, &fb1_2);
        unionFile(&container_3, &fb1_3);
        unionFile(&container_4, &fb1_4);
        unionFile(&container_5, &fb1_5);
        temps_final = clock();
        temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC; 
        temps_cpu /= 5.0;

        fprintf(resfile, "%d %f\n", i, temps_cpu);

        fclose(file_1_50_000);
        fclose(file_2_50_000);
        fclose(file_3_50_000);
        fclose(file_4_50_000);
        fclose(file_5_50_000);

    }

    fclose(resfile);

    return 0;
}