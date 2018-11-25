#include "tasTree.h"
#include "tasTab.h"
#include "md5.h"
#include "AVL.h"
#include "fromFile.h"


int main(){printf("main starts\n\n");
	int taille = 50000;
	char *filename = "cles_alea/jeu_1_nb_cles_50000.txt";
	FILE *f = fopen(filename, "r");
	tasTree *t = getFromFile_t(f, taille);
	fclose(f);
	f = fopen(filename, "r");
	tasTab *tb = getFromFile(f, taille);
	fclose(f);//printf("ORDERED KEYS: \n");
	int i;//afficheArbre(t->tas, 1);
	int testFail = 0;
	AVL *avl = createAVL();
	/*for(i=0; i<taille; ++i){
		bigInt supp = SupprMin_t(&t);
		bigInt suppb = SupprMin(tb);
		AjoutAVL(&avl, &supp, " ");
		//if(i==taille-1)  afficheBigInt( & supp );
		//printf("avl racine : ");
		//afficheBigInt(avl->racine->value);
		//if(avl->racine->fg == NULL && avl->racine->fd == NULL) printf("tout null\n");
		//afficheBigInt( & suppb );
	   // afficheBigInt( & supp );
		if( ! eg(supp, suppb)){ perror("Valeur minimale différente entre tasTab et tasTree\n"); testFail = 1; exit(0);}
	}
	printf("\n\n %d nbelem dans l'avl\n\n",avl->nbelem);
	noeudAvl* navl;
	//afficheAVLInfixe(avl);
	navl = avl->racine;
	int cpth=0;
	while(navl->fg != NULL){
		navl = navl->fg;
		cpth++;
	}
	int ress = AjoutAVL(&avl, navl->value, " ");
	if(ress == 1) printf("DOUBLON DETECTION\n");
	 ress = AjoutAVL(&avl, navl->value, " ");
		if(ress == 2) printf("DOUBLON IGNORED\n");
	printf("hauteuravl = %d\n",cpth);
	afficheBigInt(navl->value);
	printf("fin test\n");
	if(testFail) perror("Echec test\n");
	printf("elem 2, (h - 1) = %d\n",  ((int)(log10(16)/log10(2)))  );


	afficheBigInt(md5("The quick brown fox jumps over the lazy dog.", 44));*/
	int s;
	int nbWord = 0;
	char **wordList = NULL;
	filename = "Shakespeare/1henryiv.txt";
	f = fopen(filename, "r");
	AVL *avll = getAVLFromFile(f, &wordList,  &nbWord);
	fclose(f);

	if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);



	filename = "Shakespeare/1henryvi.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/2henryiv.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/2henryvi.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/3henryvi.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/allswell.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/asyoulikeit.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);


	filename = "Shakespeare/cleopatra.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/comedy_errors.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/coriolanus.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/cymbeline.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/1henryvi.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/hamlet.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/henryv.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/henryviii.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/john.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/julius_caesar.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/lear.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/lll.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);






	filename = "Shakespeare/macbeth.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/measure.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/merchant.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/merry_wives.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/midsummer.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/much_ado.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/othello.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/pericles.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/richardii.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/richardiii.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/romeo_juliet.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/taming_shrew.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/tempest.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/timon.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/titus.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/troilus_cressida.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/twelfth_night.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);

	filename = "Shakespeare/two_gentlemen.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);



	filename = "Shakespeare/winters_tale.txt";
	f = fopen(filename, "r"); avll = getAVLFromFile(f, &wordList,  &nbWord);

	fclose(f); if(wordList == NULL){
		perror("????\n");
	}
	printf("nb mots = %d\n", nbWord);




/*	AVL *avl = createAVL();
	bigInt *bi20 = creerBigInt("0x20000000000000000000000000000000");
	//AjoutAVL(&avl, bi, " ");
	bigInt *bi4 = creerBigInt("0x04000000000000000000000000000000");
	//AjoutAVL(&avl, bi, " ");
	bigInt *bi26 = creerBigInt("0x26000000000000000000000000000000");
	//AjoutAVL(&avl, bi, " ");
	bigInt *bi3 = creerBigInt("0x03000000000000000000000000000000");
	bigInt *bi9 = creerBigInt("0x09000000000000000000000000000000");
	bigInt *bi2 = creerBigInt("0x02000000000000000000000000000000");
	bigInt *bi7 = creerBigInt("0x07000000000000000000000000000000");
	bigInt *bi11 = creerBigInt("0x11000000000000000000000000000000");
	bigInt *bi21 = creerBigInt("0x21000000000000000000000000000000");
	bigInt *bi30 = creerBigInt("0x30000000000000000000000000000000");

	bigInt *bi15 = creerBigInt("0x15000000000000000000000000000000");
	bigInt *bi8 = creerBigInt("0x08000000000000000000000000000000");

	AjoutAVL(&avl, bi20, " ");
	AjoutAVL(&avl, bi4, " ");

	AjoutAVL(&avl, bi26, " ");
	AjoutAVL(&avl, bi3, " ");
	AjoutAVL(&avl, bi9, " ");

	AjoutAVL(&avl, bi21, " ");
	AjoutAVL(&avl, bi30, " ");
	AjoutAVL(&avl, bi2, " ");
	AjoutAVL(&avl, bi7, " ");
	AjoutAVL(&avl, bi11, " ");



	printf("AFFICHAGE avant:\n");
	afficheAVLInfixe(avl);

	AjoutAVL(&avl, bi15, " ");

	printf("AFFICHAGE apres:\n");
	afficheAVLInfixe(avl);
*/

	/*if(avl->racine->pere != NULL) perror("pere racine non null\n");
	if(! eg(   *bi  , *(avl->racine->fg->pere->value)  )) perror("pere fg error\n");
	if(! eg(   *bi  , *(avl->racine->fd->pere->value)  )) perror("pere fd error\n");

	if(avl->racine->fd->fd != NULL || avl->racine->fd->fg != NULL) perror("error fils non nul fd\n");
	if(avl->racine->fg->fd != NULL || avl->racine->fg->fg != NULL) perror("error fils non nul fg\n");*/



	return 0;
}
