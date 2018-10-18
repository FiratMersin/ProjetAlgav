//les clés entières 128 bits en hexa seront stockées sous format String

#ifndef UTIL_H
#define UTIL_H
typedef struct	{
	unsigned int entier1;
	unsigned int entier2;
	unsigned int entier3;
	unsigned int entier4;
}bigInt;

bigInt *creerBigInt();

bigInt *copier(bigInt bi);

void freeBigInt(bigInt *bi);

void afficheBigInt(bigInt *bi);

unsigned int getEntier(char *hex, int start, int end);

int inf(bigInt cle1, bigInt cle2);//retourne 1 si cle1 < cle2 et 0 sinon

int eg(bigInt cle1, bigInt cle2);//retourne 1 si cle1 == cle2 et 0 sinon

#endif

