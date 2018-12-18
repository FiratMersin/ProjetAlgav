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

int main(int argc, char **argv)
{

    if (argc != 4)
    {
        printf("Erreur. Il faut 3 arguments (fichier fichier nbClefs\n");
        return -1;
    }
    else
    {

        char *nomFichier1 = argv[1];
        char *nomFichier2 = argv[2];
        int nbClef = atoi(argv[3]);

        char str[101];

        printf("Nom du fichier 1 = %s\n", nomFichier1);
        printf("Nom du fichier 2 = %s\n", nomFichier2);
        printf("Nombre de clef = %d\n", nbClef);

        FILE *f1 = fopen(nomFichier1, "r");
        if (f1 == NULL)
            return -1;

        FILE *f2 = fopen(nomFichier2, "r");
        if (f2 == NULL)
            return -2;

        FB *fb1 = createEmptyFileBinomiale();
        FB *fb2 = createEmptyFileBinomiale();

        printf("On ajoute toute les clefs dans 2 FB differentes\n");

        int i = 0;
        bigInt *b = NULL;
        for (i = 0; i < nbClef; i++)
        {
            GetChaine(f1, 100, str);
            b = creerBigInt(str);
            fb1 = ajout(fb1, b);

            GetChaine(f2, 100, str);
            b = creerBigInt(str);
            fb2 = ajout(fb2, b);
        }

        printf("Affichage de f1\n");

        displayFB(fb1);

        printf("Affichage de f2\n");

        displayFB(fb2);

        printf("On fait l'union des 2 FB\n");

        FB *uFB = unionFile(&fb1, &fb2);

        printf("Affichage uFB\n");

        displayFB(uFB);

        printf("On retire le min de uFB\n");

        bigInt* min = supprMin(&uFB);

        printf("Min = %s\n", toStringBigInt(min));

        printf("Affichage de uFB\n");

        displayFB(uFB);

        printf("FIN\n");

        fclose(f1);
        fclose(f2);
    }

    return 0;
}