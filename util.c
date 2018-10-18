#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bigInt *creerBigInt(char *initBint){//crée un bigInt à partir d'un String
	bigInt * bi = (bigInt *) malloc(sizeof(bigInt));
	if(bi == NULL){
		printf("error malloc BigInt\n");
		return NULL;
	}
	bi->entier1 = getEntier(initBint, 2, 10);
	bi->entier2 = getEntier(initBint, 10, 18);
	bi->entier3 = getEntier(initBint, 18, 26);
	bi->entier4 = getEntier(initBint, 26, 34);
	return bi;
}

bigInt *copier(bigInt bi){//crée une copie d'un bigInt
	bigInt * c = (bigInt *) malloc(sizeof(bigInt));
	if(c == NULL){
		printf("error malloc copie BigInt\n");
		return NULL;
	}
	c->entier1 = bi.entier1;
	c->entier2 = bi.entier2;
	c->entier3 = bi.entier3;
	c->entier4 = bi.entier4;
	return c;
}

void freeBigInt(bigInt *bi){//libère la mémoire d'un bigInt
	if(bi != NULL){
		free(bi);
	}
	bi = NULL;
}

void afficheBigInt(bigInt *bi){
	printf("0x%08x%08x%08x%08x\n",bi->entier1, bi->entier2, bi->entier3, bi->entier4);
}



unsigned int getEntier(char *hex, int start, int end){//retourne un unsigned int en hexa correspondant aux chiffres hexa dans hex allant de start à (end - 1)
	char h[10] = "0x";
	int i,j;
	for(i = start, j = 2; i<end; ++i, ++j) h[j] = hex[i];//à la fin du for hex = "0xiiiiiiii" (i un chiffre hexa)
	unsigned int res;
	sscanf(h, "%x", &res);//res = iiiiiiii (i un chiffre hexa)
	return res;
}

int inf(bigInt cle1, bigInt cle2){
//si b1.entieri < b2.entieri retourne true sinon si b1.entieri > b2.entieri alors retourne false 
	
	//test sur entier 1
	if(cle1.entier1 < cle2.entier1) return 1;
	else if(cle1.entier1 > cle2.entier1) return 0;
	//test sur entier 2
	if(cle1.entier2 < cle2.entier2) return 1;
	else if(cle1.entier2 > cle2.entier2) return 0;
	//test sur entier 3
	if(cle1.entier3 < cle2.entier3) return 1;
	else if(cle1.entier3 > cle2.entier3) return 0;
	//test sur entier 4
	if(cle1.entier4 < cle2.entier4) return 1;
	return 0;
}

int eg(bigInt cle1, bigInt cle2){
	if( (cle1.entier1 == cle2.entier1) 
		&& (cle1.entier2 == cle2.entier2) 
		&& (cle1.entier3 == cle2.entier3) 
		&& (cle1.entier4 == cle2.entier4) ) 
		return 1;
	return 0;
}
