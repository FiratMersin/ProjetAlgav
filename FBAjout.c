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

int main(int argc, char **argv)
{
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
    if (resfile == NULL)
        return -1;

    FB **resFB = (FB **)(malloc(sizeof(FB *) * 5));

    for (i = 0; i < 5; i++)
    {
        resFB[i] = createEmptyFileBinomiale();
    }

    bigInt **a = (bigInt **)(malloc(sizeof(bigInt *) * 5));

    a[0] = (bigInt *)(malloc(sizeof(bigInt) * 250000));
    a[1] = (bigInt *)(malloc(sizeof(bigInt) * 250000));
    a[2] = (bigInt *)(malloc(sizeof(bigInt) * 250000));

    a[3] = (bigInt *)(malloc(sizeof(bigInt) * 250000));
    a[4] = (bigInt *)(malloc(sizeof(bigInt) * 250000));

    ////////////////////////////////////////////////////////////////////////////////////////

    filebi1 = fopen("cles_alea/jeu_1_nb_cles_100.txt", "r");
    if (filebi1 == NULL)
        return -1;

    filebi2 = fopen("cles_alea/jeu_2_nb_cles_100.txt", "r");
    if (filebi2 == NULL)
        return -1;

    filebi3 = fopen("cles_alea/jeu_3_nb_cles_100.txt", "r");
    if (filebi3 == NULL)
        return -1;

    filebi4 = fopen("cles_alea/jeu_4_nb_cles_100.txt", "r");
    if (filebi4 == NULL)
        return -1;

    filebi5 = fopen("cles_alea/jeu_5_nb_cles_100.txt", "r");
    if (filebi5 == NULL)
        return -1;

    taille = 100;

    for (i = 0; i < taille; ++i)
    {
        GetChaine(filebi1, 100, str);
        a[0][i] = *(creerBigInt(str));

        GetChaine(filebi2, 100, str);
        a[1][i] = *(creerBigInt(str));

        GetChaine(filebi3, 100, str);
        a[2][i] = *(creerBigInt(str));

        GetChaine(filebi4, 100, str);
        a[3][i] = *(creerBigInt(str));

        GetChaine(filebi5, 100, str);
        a[4][i] = *(creerBigInt(str));
    }

    temps_initial = clock();

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < taille; i++)
        {
            resFB[j] = ajout(resFB[j], &(a[j][i]));
        }
    }

    temps_final = clock();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    temps_cpu /= 5.0;

    fprintf(resfile, "%d %f\n", taille, temps_cpu);

    fclose(filebi1);
    fclose(filebi2);
    fclose(filebi3);
    fclose(filebi4);
    fclose(filebi5);

    ////////////////////////////////////////////////////////////////////////////////////////

    filebi1 = fopen("cles_alea/jeu_1_nb_cles_200.txt", "r");
    if (filebi1 == NULL)
        return -1;

    filebi2 = fopen("cles_alea/jeu_2_nb_cles_200.txt", "r");
    if (filebi2 == NULL)
        return -1;

    filebi3 = fopen("cles_alea/jeu_3_nb_cles_200.txt", "r");
    if (filebi3 == NULL)
        return -1;

    filebi4 = fopen("cles_alea/jeu_4_nb_cles_200.txt", "r");
    if (filebi4 == NULL)
        return -1;

    filebi5 = fopen("cles_alea/jeu_5_nb_cles_200.txt", "r");
    if (filebi5 == NULL)
        return -1;

    taille = 200;

    for (i = 0; i < taille; ++i)
    {
        GetChaine(filebi1, 100, str);
        a[0][i] = *(creerBigInt(str));

        GetChaine(filebi2, 100, str);
        a[1][i] = *(creerBigInt(str));

        GetChaine(filebi3, 100, str);
        a[2][i] = *(creerBigInt(str));

        GetChaine(filebi4, 100, str);
        a[3][i] = *(creerBigInt(str));

        GetChaine(filebi5, 100, str);
        a[4][i] = *(creerBigInt(str));
    }

    temps_initial = clock();

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < taille; i++)
        {
            resFB[j] = ajout(resFB[j], &(a[j][i]));
        }
    }

    temps_final = clock();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    temps_cpu /= 5.0;

    fprintf(resfile, "%d %f\n", taille, temps_cpu);

    fclose(filebi1);
    fclose(filebi2);
    fclose(filebi3);
    fclose(filebi4);
    fclose(filebi5);

    ////////////////////////////////////////////////////////////////////////////////////////

    filebi1 = fopen("cles_alea/jeu_1_nb_cles_500.txt", "r");
    if (filebi1 == NULL)
        return -1;

    filebi2 = fopen("cles_alea/jeu_2_nb_cles_500.txt", "r");
    if (filebi2 == NULL)
        return -1;

    filebi3 = fopen("cles_alea/jeu_3_nb_cles_500.txt", "r");
    if (filebi3 == NULL)
        return -1;

    filebi4 = fopen("cles_alea/jeu_4_nb_cles_500.txt", "r");
    if (filebi4 == NULL)
        return -1;

    filebi5 = fopen("cles_alea/jeu_5_nb_cles_500.txt", "r");
    if (filebi5 == NULL)
        return -1;

    taille = 500;

    for (i = 0; i < taille; ++i)
    {
        GetChaine(filebi1, 100, str);
        a[0][i] = *(creerBigInt(str));

        GetChaine(filebi2, 100, str);
        a[1][i] = *(creerBigInt(str));

        GetChaine(filebi3, 100, str);
        a[2][i] = *(creerBigInt(str));

        GetChaine(filebi4, 100, str);
        a[3][i] = *(creerBigInt(str));

        GetChaine(filebi5, 100, str);
        a[4][i] = *(creerBigInt(str));
    }

    temps_initial = clock();

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < taille; i++)
        {
            resFB[j] = ajout(resFB[j], &(a[j][i]));
        }
    }

    temps_final = clock();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    temps_cpu /= 5.0;

    fprintf(resfile, "%d %f\n", taille, temps_cpu);

    fclose(filebi1);
    fclose(filebi2);
    fclose(filebi3);
    fclose(filebi4);
    fclose(filebi5);

    ////////////////////////////////////////////////////////////////////////////////////////

    filebi1 = fopen("cles_alea/jeu_1_nb_cles_1000.txt", "r");
    if (filebi1 == NULL)
        return -1;

    filebi2 = fopen("cles_alea/jeu_2_nb_cles_1000.txt", "r");
    if (filebi2 == NULL)
        return -1;

    filebi3 = fopen("cles_alea/jeu_3_nb_cles_1000.txt", "r");
    if (filebi3 == NULL)
        return -1;

    filebi4 = fopen("cles_alea/jeu_4_nb_cles_1000.txt", "r");
    if (filebi4 == NULL)
        return -1;

    filebi5 = fopen("cles_alea/jeu_5_nb_cles_1000.txt", "r");
    if (filebi5 == NULL)
        return -1;

    taille = 1000;

    for (i = 0; i < taille; ++i)
    {
        GetChaine(filebi1, 100, str);
        a[0][i] = *(creerBigInt(str));

        GetChaine(filebi2, 100, str);
        a[1][i] = *(creerBigInt(str));

        GetChaine(filebi3, 100, str);
        a[2][i] = *(creerBigInt(str));

        GetChaine(filebi4, 100, str);
        a[3][i] = *(creerBigInt(str));

        GetChaine(filebi5, 100, str);
        a[4][i] = *(creerBigInt(str));
    }

    temps_initial = clock();

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < taille; i++)
        {
            resFB[j] = ajout(resFB[j], &(a[j][i]));
        }
    }

    temps_final = clock();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    temps_cpu /= 5.0;

    fprintf(resfile, "%d %f\n", taille, temps_cpu);

    fclose(filebi1);
    fclose(filebi2);
    fclose(filebi3);
    fclose(filebi4);
    fclose(filebi5);

    ////////////////////////////////////////////////////////////////////////////////////////

    filebi1 = fopen("cles_alea/jeu_1_nb_cles_10000.txt", "r");
    if (filebi1 == NULL)
        return -1;

    filebi2 = fopen("cles_alea/jeu_2_nb_cles_10000.txt", "r");
    if (filebi2 == NULL)
        return -1;

    filebi3 = fopen("cles_alea/jeu_3_nb_cles_10000.txt", "r");
    if (filebi3 == NULL)
        return -1;

    filebi4 = fopen("cles_alea/jeu_4_nb_cles_10000.txt", "r");
    if (filebi4 == NULL)
        return -1;

    filebi5 = fopen("cles_alea/jeu_5_nb_cles_10000.txt", "r");
    if (filebi5 == NULL)
        return -1;

    taille = 10000;

    for (i = 0; i < taille; ++i)
    {
        GetChaine(filebi1, 100, str);
        a[0][i] = *(creerBigInt(str));

        GetChaine(filebi2, 100, str);
        a[1][i] = *(creerBigInt(str));

        GetChaine(filebi3, 100, str);
        a[2][i] = *(creerBigInt(str));

        GetChaine(filebi4, 100, str);
        a[3][i] = *(creerBigInt(str));

        GetChaine(filebi5, 100, str);
        a[4][i] = *(creerBigInt(str));
    }

    temps_initial = clock();

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < taille; i++)
        {
            resFB[j] = ajout(resFB[j], &(a[j][i]));
        }
    }

    temps_final = clock();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    temps_cpu /= 5.0;

    fprintf(resfile, "%d %f\n", taille, temps_cpu);

    fclose(filebi1);
    fclose(filebi2);
    fclose(filebi3);
    fclose(filebi4);
    fclose(filebi5);

    ////////////////////////////////////////////////////////////////////////////////////////

    filebi1 = fopen("cles_alea/jeu_1_nb_cles_20000.txt", "r");
    if (filebi1 == NULL)
        return -1;

    filebi2 = fopen("cles_alea/jeu_2_nb_cles_20000.txt", "r");
    if (filebi2 == NULL)
        return -1;

    filebi3 = fopen("cles_alea/jeu_3_nb_cles_20000.txt", "r");
    if (filebi3 == NULL)
        return -1;

    filebi4 = fopen("cles_alea/jeu_4_nb_cles_20000.txt", "r");
    if (filebi4 == NULL)
        return -1;

    filebi5 = fopen("cles_alea/jeu_5_nb_cles_20000.txt", "r");
    if (filebi5 == NULL)
        return -1;

    taille = 20000;

    for (i = 0; i < taille; ++i)
    {
        GetChaine(filebi1, 100, str);
        a[0][i] = *(creerBigInt(str));

        GetChaine(filebi2, 100, str);
        a[1][i] = *(creerBigInt(str));

        GetChaine(filebi3, 100, str);
        a[2][i] = *(creerBigInt(str));

        GetChaine(filebi4, 100, str);
        a[3][i] = *(creerBigInt(str));

        GetChaine(filebi5, 100, str);
        a[4][i] = *(creerBigInt(str));
    }

    temps_initial = clock();

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < taille; i++)
        {
            resFB[j] = ajout(resFB[j], &(a[j][i]));
        }
    }

    temps_final = clock();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    temps_cpu /= 5.0;

    fprintf(resfile, "%d %f\n", taille, temps_cpu);

    fclose(filebi1);
    fclose(filebi2);
    fclose(filebi3);
    fclose(filebi4);
    fclose(filebi5);

    ////////////////////////////////////////////////////////////////////////////////////////

    filebi1 = fopen("cles_alea/jeu_1_nb_cles_50000.txt", "r");
    if (filebi1 == NULL)
        return -1;

    filebi2 = fopen("cles_alea/jeu_2_nb_cles_50000.txt", "r");
    if (filebi2 == NULL)
        return -1;

    filebi3 = fopen("cles_alea/jeu_3_nb_cles_50000.txt", "r");
    if (filebi3 == NULL)
        return -1;

    filebi4 = fopen("cles_alea/jeu_4_nb_cles_50000.txt", "r");
    if (filebi4 == NULL)
        return -1;

    filebi5 = fopen("cles_alea/jeu_5_nb_cles_50000.txt", "r");
    if (filebi5 == NULL)
        return -1;

    taille = 50000;

    for (i = 0; i < taille; ++i)
    {
        GetChaine(filebi1, 100, str);
        a[0][i] = *(creerBigInt(str));

        GetChaine(filebi2, 100, str);
        a[1][i] = *(creerBigInt(str));

        GetChaine(filebi3, 100, str);
        a[2][i] = *(creerBigInt(str));

        GetChaine(filebi4, 100, str);
        a[3][i] = *(creerBigInt(str));

        GetChaine(filebi5, 100, str);
        a[4][i] = *(creerBigInt(str));
    }

    temps_initial = clock();

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < taille; i++)
        {
            resFB[j] = ajout(resFB[j], &(a[j][i]));
        }
    }

    temps_final = clock();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    temps_cpu /= 5.0;

    fprintf(resfile, "%d %f\n", taille, temps_cpu);

    fclose(filebi1);
    fclose(filebi2);
    fclose(filebi3);
    fclose(filebi4);
    fclose(filebi5);

    // for (j = 0; j < 5; j++)
    // {
    //     for (i = 0; i < 250000; i++)
    //     {
    //         free(&a[j][i]);
    //     }

    //     freeFB(resFB[i]);
    // }

    return 0;
}