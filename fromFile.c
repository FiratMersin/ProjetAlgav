#include "fromFile.h"
#include "md5.h"
#include <string.h>
#include "util.h"


tasTab *getTasTabFromFile(FILE *f, int taille){
	 char str[101];
	 int  taillem2 = (int)(taille/2);
	 bigInt **tab1=(bigInt**)malloc(sizeof(bigInt*)*taillem2);
	 bigInt **tab2=(bigInt**)malloc(sizeof(bigInt*)*taillem2);
	 int i;
	 tasTab *t1 = init(taillem2);
	 tasTab *t2 = init(taillem2);
	 for(i=0; i<taillem2; ++i){
		 GetChaine(f, 100, str);
		 tab1[i] = creerBigInt(str);
	 }
	 ConsIter(&t1 ,tab1, taillem2);

	 for(i=0; i<taillem2; ++i){
		 GetChaine(f, 100, str);
		 tab2[i] = creerBigInt(str);
	 }
	 ConsIter(&t2 ,tab2, taillem2);
	 tasTab *uni = Union(t1, t2);
	 return uni;
}


tasTree *getTasTreeFromFile(FILE *f, int taille){//union des deux moitier du fichier
	 char str[101];
	 int  taillem2 = (int)(taille/2);
	 bigInt **tab1=(bigInt**)malloc(sizeof(bigInt*)*taillem2);
	 bigInt **tab2=(bigInt**)malloc(sizeof(bigInt*)*taillem2);
	 int i;
	 tasTree *t1 = init_t(taillem2);
	 tasTree *t2 = init_t(taillem2);
	 for(i=0; i<taillem2; ++i){
		 GetChaine(f, 100, str);
		 tab1[i] = creerBigInt(str);
	 }
	 ConsIter_t(&t1 ,tab1, taillem2);


	 for(i=0; i<taillem2; ++i){
		 GetChaine(f, 100, str);
		 tab2[i] = creerBigInt(str);
	 }
	 ConsIter_t(&t2 ,tab2, taillem2);
	 tasTree *uni = Union_t(t1, t2);
	 return uni;
}

AVL *getAVLFromFile(FILE *f, char ***wordList, int *nbWord){
	AVL *avl = createAVL();
	char *str=(char*)malloc(sizeof(char)*101);
	*nbWord = 0;
	if(*wordList != NULL) free(*wordList);
	int i;
	*wordList = (char**)malloc(sizeof(char*)*50000);
	for(i = 0;i < 50000; i++){
		(*wordList)[i] = (char*)malloc(sizeof(char)*101);
	}
	GetChaine(f, 100, str);
	do{

		bigInt *hash = md5(str, strlen(str));
		int res = AjoutAVL(&avl, hash, str);

		if(res == 0){//nouveau mot
			strcpy( (*wordList)[*nbWord],  str);
			(*nbWord)++;
		}
		GetChaine(f, 100, str);
	}while(strcmp(str, "") != 0);
	free(str);
	return avl;

}



