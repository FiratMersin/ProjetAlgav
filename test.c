#include "tasTree.h"
#include "tasTab.h"
#include "md5.h"

int main(){printf("main starts\n\n");
	int taille = 50000;
	char *filename = "cles_alea/jeu_1_nb_cles_50000.txt";
	FILE *f = fopen(filename, "r");
	tasTree *t = getFromFile_t(f, taille);
	fclose(f);
	f = fopen(filename, "r");
	tasTab *tb = getFromFile(f, taille);
	fclose(f);printf("ORDERED KEYS: \n");
	int i;//afficheArbre(t->tas, 1);
	int testFail = 0;
	for(i=0; i<taille; ++i){
		bigInt supp = SupprMin_t(&t);
		bigInt suppb = SupprMin(tb);

       // afficheBigInt( & suppb );
	   // afficheBigInt( & supp );
		if( ! eg(supp, suppb)){ perror("Valeur minimale différente entre tasTab et tasTree\n"); testFail = 1; }
	}
	printf("fin test\n");
	if(testFail) perror("Echec test\n");
	printf("elem 2, (h - 1) = %d\n",  ((int)(log10(16)/log10(2)))  );


	afficheBigInt(md5("The quick brown fox jumps over the lazy dog.", 44));
	return 0;
}
