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

        FBR *fbr = createEmptyFBR();
        FB* fb = createEmptyFileBinomiale();

        GetChaine(f, 100, str);
        bigInt *b = creerBigInt(str);

        fbr = ajoutInFBRStatic(&fbr, createB0(b));
        fb = ajout(fb, b);

        printf("1er bigInt = %s\n", toStringBigInt(b));

        printf("Apres ajout du bigInt:\n");

        displayFBR(fbr);

        int i = 0;

        for (i = 1; i < nbClef; i++)
        {
            GetChaine(f, 100, str);
            b = creerBigInt(str);

            fbr = ajoutInFBRStatic(&fbr, createB0(b));
            fb = ajout(fb, b);
        }

        printf("Apres les %d ajouts\n", nbClef);

        displayFBR(fbr);

        printf("Apres consolidation\n");

        consolider(&fbr);

        displayFBR(fbr);

        printf("Comparaison avec un FB normal\n");

        displayFB(fb);

        printf("On retire le premier min pour voir s'ils correspondent\n");

        FB* fbFBR = FBRToFB(&fbr);

        bigInt* minFBR = supprMin(&fbFBR);

        bigInt* minFB = supprMin(&fb);

        printf("Min fbr = %s\n", toStringBigInt(minFBR));
        printf("Min fb = %s\n", toStringBigInt(minFB));

        printf("Les file apres la suppression\n");

        displayFB(fbFBR);
        displayFB(fb);

        printf("FIN\n");

        fclose(f);
    }

    return 0;
}