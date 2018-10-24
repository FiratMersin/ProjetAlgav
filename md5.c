#include "util.h"
#include "md5.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bigInt *md5(char *data, unsigned int dataSize){

	//on utilisera par la suite la valeur ascii des chars de data

	unsigned int r[] = {7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
			              5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
						  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
						  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21};

	//sinus d'entier pour les constantes
	unsigned int k[64];
	unsigned int j;
	for(j = 0; j<64; j++){
		double s = sin(j+1);
		if(s < 0) s = -1 * s;
		k[j] = (unsigned int) (floor(s * pow(2, 32)));
	}

	//préparation des variables
	unsigned int h0 = 0x67452301;
	unsigned int h1 = 0xefcdab89;
	unsigned int h2 = 0x98badcfe;
	unsigned int h3 = 0x10325476;

	//padding:
	unsigned int paddDataSize = dataSize + 1;// + 1 pour le futur ajout du bit à 1
	unsigned int dataSizeInBits = 8 * dataSize;//Un char est codé sur 8 bits
	char *paddData = NULL;

	while( (paddDataSize % 512) != 448) paddDataSize++;

	paddDataSize = paddDataSize / 8;//Un char est codé sur 8 bits

	paddData = calloc(paddDataSize + 64, 1); //+64 pour ajouter la taille à la fin

	//calloc alloue de la mémoire initialisée à zéro
	//on copie donc le message initial au début de paddData
	//ensuite on ajoute le bit 1
	//et à la fin de la séquence de bit on ajoute le taille du message initial (data)

	memcpy(paddData, data, dataSize);// copie de data
	paddData[dataSize] = 128;//ajout du bit 1
	memcpy(paddData + paddDataSize, &dataSizeInBits, 4);//ajout taille

	int off;
	int blockSize = 128;
	unsigned int *w;
	for(off = 0; off<paddDataSize; off += blockSize ){

		w = paddData + off;// pour 0 <= i <= 15, w[i] = hexa sur 8 bits (= valeur ASCII d'un char)

		unsigned int a = h0;
		unsigned int b = h1;
		unsigned int c = h2;
		unsigned int d = h3;

		unsigned int f;
		unsigned int g;

		unsigned int i;
		for(i = 0; i < 64; i++){
			if(i < 16){
				//f = (b & c) | ((~ b) & d);//fonctionne aussi
				f = d ^ (b & (c ^ d));//pseudo-code wiki anglais
				g = i;
			}else if(i < 32){
				//f = (d & b) | ((~ d) & c);//fonctionne aussi
				f = c ^ (d & (b ^ c));//pseudo-code wiki anglais
				g = (5*i + 1) % 16;
			}else if(i < 48){
				f = b ^ c ^ d;
				g = (3*i + 5) % 16;
			}else{//i < 64
				f = c ^ (b | (~ d));
				g = (7*i) % 16;
			}

			unsigned int temp = d;
			d = c;
			c = b;
			b = (( (a + f + k[i] + w[g]) << r[i]) | ( (a + f + k[i] + w[g]) >> (32 - r[i]) )) + b;//rotation gauche de r|i] bits
			a = temp;
		}
		h0 = h0 + a;
		h1 = h1 + b;
		h2 = h2 + c;
		h3 = h3 + d;
	}

	//on récupère l'entier 128 bits et on le stocke dans un bigInt
	char str[35];
	uint8_t *p0 = (uint8_t *)&h0;
	uint8_t *p1 = (uint8_t *)&h1;
	uint8_t *p2 = (uint8_t *)&h2;
	uint8_t *p3 = (uint8_t *)&h3;
	sprintf(str, "0x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x",
			p0[0], p0[1], p0[2], p0[3], p1[0], p1[1],p1[2], p1[3],
			p2[0], p2[1], p2[2], p2[3], p3[0], p3[1], p3[2], p3[3]);

	bigInt *res = creerBigInt(str);
	return res;
}
