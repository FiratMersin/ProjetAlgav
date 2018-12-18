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
    if (argc != 3)
    {
        printf("Erreur. Il faut 2 arguments (fichier nbClefs\n");
        return -1;
    }
    else
    {

        char *nomFichier = argv[1];
        int nbClef = atoi(argv[2]);

        char str[101];

        printf("Nom du fichier = %s\n", nomFichier);
        printf("Nombre de clef = %d\n", nbClef);

        FILE *f = fopen(nomFichier, "r");

        if (f == NULL)
            return -1;

        FB *fb = createEmptyFileBinomiale();

        GetChaine(f, 100, str);
        bigInt *b = creerBigInt(str);

        fb = ajout(fb, b);

        printf("1er bigInt = %s\n", toStringBigInt(b));

        printf("Apres ajout du bigInt:\n");

        displayFB(fb);

        int i = 0;

        for (i = 1; i < nbClef; i++)
        {
            GetChaine(f, 100, str);
            b = creerBigInt(str);

            fb = ajout(fb, b);
        }

        printf("Apres les %d ajouts\n", nbClef);

        displayFB(fb);

        printf("On retire les 3 premiers min un a un\n\n");

        bigInt* min = supprMin(&fb);

        printf("1er min = %s\n", toStringBigInt(min));

        displayFB(fb);

        min = supprMin(&fb);

        printf("2eme min = %s\n", toStringBigInt(min));

        displayFB(fb);

        min = supprMin(&fb);

        printf("3eme min = %s\n", toStringBigInt(min));

        displayFB(fb);

        printf("FIN\n");

        fclose(f);
    }

    return 0;
}