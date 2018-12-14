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

int main(int argc, char **argv){

 //100 200 500 1000 10000 20000 50000 100000 250000
int i;
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
tasTree* tasUnion;
tasTab* tas1;
tasTab* tas2;
tasTab* tas3;
tasTab* tas4;
tasTab* tas5;

printf("execution de union tas pour %s\n",argv[1]);

bigInt **aB1 = (bigInt **)(malloc(sizeof(bigInt*) * 250000));
bigInt **aB2 = (bigInt **)(malloc(sizeof(bigInt*) * 250000));
bigInt **aB3 = (bigInt **)(malloc(sizeof(bigInt*) * 250000));

bigInt **aB4 = (bigInt **)(malloc(sizeof(bigInt*) * 250000));
bigInt **aB5 = (bigInt **)(malloc(sizeof(bigInt*) * 250000));


filebi1 = fopen("cles_alea/jeu_1_nb_cles_100.txt", "r");
filebi2 = fopen("cles_alea/jeu_2_nb_cles_100.txt", "r");
filebi3 = fopen("cles_alea/jeu_3_nb_cles_100.txt", "r");
filebi4 = fopen("cles_alea/jeu_4_nb_cles_100.txt", "r");
filebi5 = fopen("cles_alea/jeu_5_nb_cles_100.txt", "r");

taille = 100;

for(i=0; i<taille; ++i){
	 GetChaine(filebi1, 100, str);
	 aB1[i] = (creerBigInt(str));

	GetChaine(filebi2, 100, str);
	 aB2[i] = (creerBigInt(str));

	GetChaine(filebi3, 100, str);
	 aB3[i] = (creerBigInt(str));

	GetChaine(filebi4, 100, str);
	 aB4[i] = (creerBigInt(str));

	GetChaine(filebi5, 100, str);
	 aB5[i] = (creerBigInt(str));
 }
afficheBigInt(aB1[0]);



tas1 = init(taille);;
ConsIter(&tas1, aB1,taille);
tas2 = init(taille);
ConsIter(&tas2,aB2, taille);
tas3 = init(taille);;
ConsIter(&tas3,aB3, taille);
tas4 = init(taille);;
ConsIter(&tas4,aB4, taille);
tas5 = init(taille);;
ConsIter(&tas5,aB5, taille);

temps_initial = clock();

tasUnion = Union(tas1, tas2);//1
tasUnion = Union(tas1, tas3);//2
tasUnion = Union(tas1, tas4);//3
tasUnion = Union(tas1, tas5);//4

tasUnion = Union(tas2, tas3);//5
tasUnion = Union(tas2, tas4);//6
tasUnion = Union(tas2, tas5);//7

tasUnion = Union(tas3, tas4);//8
tasUnion = Union(tas3, tas5);//9

tasUnion = Union(tas4, tas5);//10


temps_final = clock();
temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

temps_cpu /= 10.0;


fprintf(resfile, "%d %f\n", taille,temps_cpu);

fclose(filebi1);
fclose(filebi2);
fclose(filebi3);
fclose(filebi4);
fclose(filebi5);


////////////////////////////////

filebi1 = fopen("cles_alea/jeu_1_nb_cles_200.txt", "r");
filebi2 = fopen("cles_alea/jeu_2_nb_cles_200.txt", "r");
filebi3 = fopen("cles_alea/jeu_3_nb_cles_200.txt", "r");
filebi4 = fopen("cles_alea/jeu_4_nb_cles_200.txt", "r");
filebi5 = fopen("cles_alea/jeu_5_nb_cles_200.txt", "r");

taille = 200;
printf("sltsd\n");
for(i=0; i<taille; ++i){
	 GetChaine(filebi1, 100, str);
	 aB1[i] =  (creerBigInt(str));

	GetChaine(filebi2, 100, str);
	 aB2[i] =  (creerBigInt(str));

	GetChaine(filebi3, 100, str);
	 aB3[i] =  (creerBigInt(str));

	GetChaine(filebi4, 100, str);
	 aB4[i] =  (creerBigInt(str));

	GetChaine(filebi5, 100, str);
	 aB5[i] =  (creerBigInt(str));
 }





tas1 = init(taille);;
ConsIter(&tas1, aB1,taille);
tas2 = init(taille);
ConsIter(&tas2,aB2, taille);
tas3 = init(taille);;
ConsIter(&tas3,aB3, taille);
tas4 = init(taille);;
ConsIter(&tas4,aB4, taille);
tas5 = init(taille);;
ConsIter(&tas5,aB5, taille);


temps_initial = clock();

tasUnion = Union(tas1, tas2);//1
tasUnion = Union(tas1, tas3);//2
tasUnion = Union(tas1, tas4);//3
tasUnion = Union(tas1, tas5);//4

tasUnion = Union(tas2, tas3);//5
tasUnion = Union(tas2, tas4);//6
tasUnion = Union(tas2, tas5);//7

tasUnion = Union(tas3, tas4);//8
tasUnion = Union(tas3, tas5);//9

tasUnion = Union(tas4, tas5);//10



temps_final = clock();
temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

temps_cpu /= 10.0;

fprintf(resfile, "%d %f\n", taille,temps_cpu);

fclose(filebi1);
fclose(filebi2);
fclose(filebi3);
fclose(filebi4);
fclose(filebi5);


////////////////////////////////

filebi1 = fopen("cles_alea/jeu_1_nb_cles_500.txt", "r");
filebi2 = fopen("cles_alea/jeu_2_nb_cles_500.txt", "r");
filebi3 = fopen("cles_alea/jeu_3_nb_cles_500.txt", "r");
filebi4 = fopen("cles_alea/jeu_4_nb_cles_500.txt", "r");
filebi5 = fopen("cles_alea/jeu_5_nb_cles_500.txt", "r");

taille = 500;

for(i=0; i<taille; ++i){
	 GetChaine(filebi1, 100, str);
	 aB1[i] =  (creerBigInt(str));

	GetChaine(filebi2, 100, str);
	 aB2[i] =  (creerBigInt(str));

	GetChaine(filebi3, 100, str);
	 aB3[i] =  (creerBigInt(str));

	GetChaine(filebi4, 100, str);
	 aB4[i] =  (creerBigInt(str));

	GetChaine(filebi5, 100, str);
	 aB5[i] =  (creerBigInt(str));
 }




tas1 = init(taille);;
ConsIter(&tas1, aB1,taille);
tas2 = init(taille);
ConsIter(&tas2,aB2, taille);
tas3 = init(taille);;
ConsIter(&tas3,aB3, taille);
tas4 = init(taille);;
ConsIter(&tas4,aB4, taille);
tas5 = init(taille);;
ConsIter(&tas5,aB5, taille);


temps_initial = clock();

tasUnion = Union(tas1, tas2);//1
tasUnion = Union(tas1, tas3);//2
tasUnion = Union(tas1, tas4);//3
tasUnion = Union(tas1, tas5);//4

tasUnion = Union(tas2, tas3);//5
tasUnion = Union(tas2, tas4);//6
tasUnion = Union(tas2, tas5);//7

tasUnion = Union(tas3, tas4);//8
tasUnion = Union(tas3, tas5);//9

tasUnion = Union(tas4, tas5);//10


temps_final = clock();
temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

temps_cpu /= 10.0;

fprintf(resfile, "%d %f\n", taille,temps_cpu);

fclose(filebi1);
fclose(filebi2);
fclose(filebi3);
fclose(filebi4);
fclose(filebi5);

////////////////////////////////

filebi1 = fopen("cles_alea/jeu_1_nb_cles_1000.txt", "r");
filebi2 = fopen("cles_alea/jeu_2_nb_cles_1000.txt", "r");
filebi3 = fopen("cles_alea/jeu_3_nb_cles_1000.txt", "r");
filebi4 = fopen("cles_alea/jeu_4_nb_cles_1000.txt", "r");
filebi5 = fopen("cles_alea/jeu_5_nb_cles_1000.txt", "r");

taille = 1000;

for(i=0; i<taille; ++i){
	 GetChaine(filebi1, 100, str);
	 aB1[i] =  (creerBigInt(str));

	GetChaine(filebi2, 100, str);
	 aB2[i] =  (creerBigInt(str));

	GetChaine(filebi3, 100, str);
	 aB3[i] =  (creerBigInt(str));

	GetChaine(filebi4, 100, str);
	 aB4[i] =  (creerBigInt(str));

	GetChaine(filebi5, 100, str);
	 aB5[i] =  (creerBigInt(str));
 }




tas1 = init(taille);;
ConsIter(&tas1, aB1,taille);
tas2 = init(taille);
ConsIter(&tas2,aB2, taille);
tas3 = init(taille);;
ConsIter(&tas3,aB3, taille);
tas4 = init(taille);;
ConsIter(&tas4,aB4, taille);
tas5 = init(taille);;
ConsIter(&tas5,aB5, taille);


temps_initial = clock();

tasUnion = Union(tas1, tas2);//1
tasUnion = Union(tas1, tas3);//2
tasUnion = Union(tas1, tas4);//3
tasUnion = Union(tas1, tas5);//4

tasUnion = Union(tas2, tas3);//5
tasUnion = Union(tas2, tas4);//6
tasUnion = Union(tas2, tas5);//7

tasUnion = Union(tas3, tas4);//8
tasUnion = Union(tas3, tas5);//9

tasUnion = Union(tas4, tas5);//10


temps_final = clock();
temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

temps_cpu /= 10.0;

fprintf(resfile, "%d %f\n", taille,temps_cpu);

fclose(filebi1);
fclose(filebi2);
fclose(filebi3);
fclose(filebi4);
fclose(filebi5);

////////////////////////////////

filebi1 = fopen("cles_alea/jeu_1_nb_cles_10000.txt", "r");
filebi2 = fopen("cles_alea/jeu_2_nb_cles_10000.txt", "r");
filebi3 = fopen("cles_alea/jeu_3_nb_cles_10000.txt", "r");
filebi4 = fopen("cles_alea/jeu_4_nb_cles_10000.txt", "r");
filebi5 = fopen("cles_alea/jeu_5_nb_cles_10000.txt", "r");

taille = 10000;

for(i=0; i<taille; ++i){
	 GetChaine(filebi1, 100, str);
	 aB1[i] =  (creerBigInt(str));

	GetChaine(filebi2, 100, str);
	 aB2[i] =  (creerBigInt(str));

	GetChaine(filebi3, 100, str);
	 aB3[i] =  (creerBigInt(str));

	GetChaine(filebi4, 100, str);
	 aB4[i] =  (creerBigInt(str));

	GetChaine(filebi5, 100, str);
	 aB5[i] =  (creerBigInt(str));
 }




tas1 = init(taille);;
ConsIter(&tas1, aB1,taille);
tas2 = init(taille);
ConsIter(&tas2,aB2, taille);
tas3 = init(taille);;
ConsIter(&tas3,aB3, taille);
tas4 = init(taille);;
ConsIter(&tas4,aB4, taille);
tas5 = init(taille);;
ConsIter(&tas5,aB5, taille);


temps_initial = clock();

tasUnion = Union(tas1, tas2);//1
tasUnion = Union(tas1, tas3);//2
tasUnion = Union(tas1, tas4);//3
tasUnion = Union(tas1, tas5);//4

tasUnion = Union(tas2, tas3);//5
tasUnion = Union(tas2, tas4);//6
tasUnion = Union(tas2, tas5);//7

tasUnion = Union(tas3, tas4);//8
tasUnion = Union(tas3, tas5);//9

tasUnion = Union(tas4, tas5);//10


temps_final = clock();
temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

temps_cpu /= 10.0;

fprintf(resfile, "%d %f\n", taille,temps_cpu);

fclose(filebi1);
fclose(filebi2);
fclose(filebi3);
fclose(filebi4);
fclose(filebi5);


////////////////////////////////

filebi1 = fopen("cles_alea/jeu_1_nb_cles_20000.txt", "r");
filebi2 = fopen("cles_alea/jeu_2_nb_cles_20000.txt", "r");
filebi3 = fopen("cles_alea/jeu_3_nb_cles_20000.txt", "r");
filebi4 = fopen("cles_alea/jeu_4_nb_cles_20000.txt", "r");
filebi5 = fopen("cles_alea/jeu_5_nb_cles_20000.txt", "r");

taille = 20000;

for(i=0; i<taille; ++i){
	 GetChaine(filebi1, 100, str);
	 aB1[i] =  (creerBigInt(str));

	GetChaine(filebi2, 100, str);
	 aB2[i] =  (creerBigInt(str));

	GetChaine(filebi3, 100, str);
	 aB3[i] =  (creerBigInt(str));

	GetChaine(filebi4, 100, str);
	 aB4[i] =  (creerBigInt(str));

	GetChaine(filebi5, 100, str);
	 aB5[i] =  (creerBigInt(str));
 }




tas1 = init(taille);;
ConsIter(&tas1, aB1,taille);
tas2 = init(taille);
ConsIter(&tas2,aB2, taille);
tas3 = init(taille);;
ConsIter(&tas3,aB3, taille);
tas4 = init(taille);;
ConsIter(&tas4,aB4, taille);
tas5 = init(taille);;
ConsIter(&tas5,aB5, taille);


temps_initial = clock();

tasUnion = Union(tas1, tas2);//1
tasUnion = Union(tas1, tas3);//2
tasUnion = Union(tas1, tas4);//3
tasUnion = Union(tas1, tas5);//4

tasUnion = Union(tas2, tas3);//5
tasUnion = Union(tas2, tas4);//6
tasUnion = Union(tas2, tas5);//7

tasUnion = Union(tas3, tas4);//8
tasUnion = Union(tas3, tas5);//9

tasUnion = Union(tas4, tas5);//10


temps_final = clock();
temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

temps_cpu /= 10.0;

fprintf(resfile, "%d %f\n", taille,temps_cpu);

fclose(filebi1);
fclose(filebi2);
fclose(filebi3);
fclose(filebi4);
fclose(filebi5);

////////////////////////////////

filebi1 = fopen("cles_alea/jeu_1_nb_cles_50000.txt", "r");
filebi2 = fopen("cles_alea/jeu_2_nb_cles_50000.txt", "r");
filebi3 = fopen("cles_alea/jeu_3_nb_cles_50000.txt", "r");
filebi4 = fopen("cles_alea/jeu_4_nb_cles_50000.txt", "r");
filebi5 = fopen("cles_alea/jeu_5_nb_cles_50000.txt", "r");

taille = 50000;

for(i=0; i<taille; ++i){
	 GetChaine(filebi1, 100, str);
	 aB1[i] =  (creerBigInt(str));

	GetChaine(filebi2, 100, str);
	 aB2[i] =  (creerBigInt(str));

	GetChaine(filebi3, 100, str);
	 aB3[i] =  (creerBigInt(str));

	GetChaine(filebi4, 100, str);
	 aB4[i] =  (creerBigInt(str));

	GetChaine(filebi5, 100, str);
	 aB5[i] =  (creerBigInt(str));
 }




tas1 = init(taille);;
ConsIter(&tas1, aB1,taille);
tas2 = init(taille);
ConsIter(&tas2,aB2, taille);
tas3 = init(taille);;
ConsIter(&tas3,aB3, taille);
tas4 = init(taille);;
ConsIter(&tas4,aB4, taille);
tas5 = init(taille);;
ConsIter(&tas5,aB5, taille);


temps_initial = clock();

tasUnion = Union(tas1, tas2);//1
tasUnion = Union(tas1, tas3);//2
tasUnion = Union(tas1, tas4);//3
tasUnion = Union(tas1, tas5);//4

tasUnion = Union(tas2, tas3);//5
tasUnion = Union(tas2, tas4);//6
tasUnion = Union(tas2, tas5);//7

tasUnion = Union(tas3, tas4);//8
tasUnion = Union(tas3, tas5);//9

tasUnion = Union(tas4, tas5);//10



temps_final = clock();
temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

temps_cpu /= 10.0;

fprintf(resfile, "%d %f\n", taille,temps_cpu);

fclose(filebi1);
fclose(filebi2);
fclose(filebi3);
fclose(filebi4);
fclose(filebi5);





fclose(resfile);

return 0;

}

