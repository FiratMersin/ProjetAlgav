#include "util.h"
#include "tasTab.h"
#include <stdio.h>
#include "fileReader.h"

int main(int argc, char **argv){
	if(argc != 3){
		printf("2 arguments nécessaires: ./tabTabAjout cles_alea/fichier tailleFichier\n");
		exit(1);
	}
	char str[101];
	int taille = atoi(argv[2]);
	FILE *file;
	file = fopen(argv[1], "r");
	if(file == NULL){
		printf("fichier introuvable\n");
		exit(1);
	}

	tasTab *tas;
	tas = init(taille);
	int i;
	bigInt **aB1 = (bigInt **)(malloc(sizeof(bigInt*) * taille));
	for(i = 0; i < taille; i++){
		GetChaine(file, 100, str);
		aB1[i] = (creerBigInt(str));
	}

	for(i = 0; i < taille; i++){
		Ajout(tas, aB1[i]);
	}

	for(i = 0; i < taille; i++){
		bigInt *sup = SupprMin(tas);
		afficheBigInt(sup);
		free(sup);
	}

	freeTasTab(tas);

	for(i = 0; i < taille; i++){
			free(aB1[i]);
	}
	free(aB1);

	return 0;
}
