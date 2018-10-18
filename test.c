#include "tasTree.h"
#include "tasTab.h"


int main(){printf("main starts\n\n");

	char *filename = "cles_alea/jeu_1_nb_cles_50000.txt";
	FILE *f = fopen(filename, "r");
	tasTree *t = getFromFile_t(f, 50000);
	fclose(f);
	f = fopen(filename, "r");
	tasTab *tb = getFromFile(f, 50000);
	fclose(f);printf("ORDERED KEYS: \n");
	int i;//afficheArbre(t->tas, 1);
	for(i=0; i<50000; ++i){
		bigInt supp = SupprMin_t(&t);
		bigInt suppb = SupprMin(tb);

        afficheBigInt( & suppb );
	    afficheBigInt( & supp );
		if( ! eg(supp, suppb)){ perror("Valeur minimale différente entre tasTab et tasTree\n"); }
	}
	return 0;
}
