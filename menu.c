#include "util.h"
#include "AVL.h"
#include "tasTree.h"
#include "tasTab.h"
#include "fromFile.h"
#include <string.h>


char shp[37][101]= { "1henryiv", "1henryvi", "2henryiv", "2henryvi", "3henryvi",
		"allswell", "asyoulikeit", "cleopatra", "comedy_errors", "coriolanus", "cymbeline",
		"hamlet", "henryv", "henryviii", "john", "julius_caesar", "lear", "lll",
		"macbeth", "measure", "merchant", "merry_wives", "midsummer", "much_ado",
		"othello", "pericles", "richardii", "richardiii", "romeo_juliet", "taming_shrew", "tempest",
		"timon", "titus", "troilus_cressida", "twelfth_night", "two_gentlemen", "winters_tale"};


void printShp(){
	int i;
	for(int i = 0; i <37; i++){
		int len = strlen(shp[i]);
		int fill = 25 - len;
		if(i % 2 == 0)
			printf("%d-%s%*s\t",i,shp[i], fill, "");
		else
			printf("%d-%s\n",i, shp[i]);
	}
	printf("\n");
}

void menu(){
	printf("1- Créer un tas (tableau) à partir d'un fichier\n");
	printf("2- Créer un tas (arbre) à partir d'un fichier\n");
	printf("3- Obtenir l'union de deux tas (tableau)\n");
	printf("4- Obtenir l'union de deux tas (arbre)\n");
	printf("5- Afficher un tas (tableau)\n");
	printf("6- Afficher un tas (arbre)\n");
	printf("7- Obtenir le haché md5 d'un mot\n");
	printf("8- Créer un AVL à partir d'une oeuvre de Shakespeare\n");
	printf("9- Afficher les mots uniques de la dernière oeuvre lue\n");
	printf("10- Afficher les ensembles de mots en collision pour la dernière oeuvre lue\n");
	printf("11- Exit\n");
}

int main(int argc, char **argv){
	int choix;
	int choixshp;

	do{
		menu();
		do{
			scanf("%d",&choix);
		}while(choix<1 || choix > 11);
		switch(choix){
			case 1:
				printShp();
				do{
					scanf("%d",&choixshp);
				}while(choixshp<0 || choixshp > 36);


				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			default:
				break;
		}



	}while(choix != 11);

	return 0;
}


