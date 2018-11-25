#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


AVL *createAVL(){//retourne un AVL vide
	AVL *avl = (AVL*)malloc(sizeof(AVL));
	avl->nbelem = 0;
	avl->racine = NULL;
	return avl;
}
noeudAvl *createNoeud(bigInt *value, char* hashWord, noeudAvl *pere){
	noeudAvl *nd = (noeudAvl*)malloc(sizeof(noeudAvl));
	nd->pere = pere;
	nd->value = copier(value);
	nd->hashWord = hashWord;
	nd->fd = NULL;
	nd->fg = NULL;
	nd->estDoublon = 0;
	nd->hauteur = 1;
	return nd;
}
void setNoeud(noeudAvl **nd, bigInt* value, char *hashWord){
	(*nd)->value = copier(value);
	(*nd)->hashWord = hashWord;
}

int AjoutNoeud(AVL **avl, noeudAvl **nd, bigInt *value, char *hashWord){
	if(*nd == NULL){//ajout a la racine
        (*nd) = createNoeud(value, hashWord, NULL);
		return 0;
	}else{
		int cmp = cmpBigInt(*value, *((*nd)->value));
		if(cmp == -1){
			noeudAvl *filsG = (*nd)->fg;
			if(filsG == NULL){
				filsG = createNoeud(value, hashWord, (*nd));
				(*nd)->fg = filsG;
				eqAjout(avl, &filsG);
				return 0;
			}else{
				return AjoutNoeud(avl, &filsG, value, hashWord);
			}
		}else if (cmp == 1){
			noeudAvl *filsD = (*nd)->fd;
			if(filsD == NULL){
				filsD = createNoeud(value, hashWord, (*nd));
				(*nd)->fd = filsD;
				eqAjout(avl, &filsD);
				return 0;
			}else{
				return AjoutNoeud(avl, &filsD, value, hashWord);
			}
		}else{//gestion d'une clef deja presente dans l'arbre
			//on test si deux mots differents ont le meme hash md5
			//cependant le cas ou deux mots differents ont le meme hash md5 n'est pas géré et retourne une erreur
			if(strcmp((*nd)->hashWord, hashWord) == 0){
				if((*nd)->estDoublon == 1){
					return 2;//doublon deja detecte
				}else{
					(*nd)->estDoublon = 1;
					return 1;
				}
			}else{
				perror("MOTS DIFFERENTS AVEC LE MEME MD5\n");
				exit(0);
			}
		}
	}
}


int AjoutAVL(AVL **avl, bigInt *value, char *hashWord){//retourne 1 ou 2 si ajout d'un mot dupliqué, 0 sinon
	int res = AjoutNoeud(avl, &((*avl)->racine), value, hashWord);
	if(res == 0){
		(*avl)->nbelem++;
	}
	return res;
}

int Rechercher(AVL *avl, bigInt *value){
	noeudAvl *cur = avl->racine;
	while(cur != NULL){
		int cmp = cmpBigInt(*value, *(cur->value));
		if(cmp == 1){//valeur à trouver > noeud cur : on va à droite
			cur = cur->fd;
		}else if(cmp == -1){//valeur à trouver < noeud cur : on va à gauche
			cur = cur->fg;
		}else{//valeur deja présente !
			return 1;
		}
	}
	return 0;
}


void rotationDroite(AVL **avl, noeudAvl **nd){
	noeudAvl *filsG = ((*nd)->fg);
	noeudAvl *pere = ((*nd)->pere);
	if(pere != NULL){//si nd different de la racine
		if((*nd) == (pere)->fg){
			(pere)->fg = filsG;
		}else{
			(pere)->fd = filsG;
		}
	}
	(filsG)->pere = pere;
	(*nd)->pere = filsG;
	(*nd)->fg = (filsG)->fd;


	if(filsG->fd != NULL) filsG->fd->pere = *nd;

	(filsG)->fd = *nd;

	setHauteur(nd, max(getHauteur((*nd)->fg), getHauteur((*nd)->fd)) +1);
	setHauteur(&filsG, max(getHauteur((filsG)->fg), getHauteur((filsG)->fd)) +1);

	if(filsG->pere == NULL) (*avl)->racine = filsG;
}

void rotationGauche(AVL **avl, noeudAvl **nd){
	noeudAvl *filsD = ((*nd)->fd);
	noeudAvl *pere = ((*nd)->pere);

	if(pere != NULL){
		if((*nd) == (pere)->fg){
			(pere)->fg = filsD;
		}else{
			(pere)->fd = filsD;
		}
	}

	(filsD)->pere = pere;
	(*nd)->pere = filsD;
	(*nd)->fd = (filsD)->fg;

	if(filsD->fg != NULL) filsD->fg->pere = *nd;

	(filsD)->fg = *nd;

	setHauteur(nd, max(getHauteur((*nd)->fg), getHauteur((*nd)->fd)) +1);
	setHauteur(&filsD, max(getHauteur((filsD)->fg), getHauteur((filsD)->fd)) +1);
	if(filsD->pere == NULL) (*avl)->racine = filsD;

}

void eqAjout(AVL **avl, noeudAvl **st){
	int diffHauteur = 0;
	noeudAvl *pere = *st;int i = 1;
	noeudAvl *nd;

	while(pere->pere != NULL && diffHauteur != -2 && diffHauteur != 2){
		nd = pere;
		pere = pere->pere;
		setHauteur(&pere, max(getHauteur(pere->fg), getHauteur(pere->fd)) +1);
		diffHauteur = getDiffHauteur(pere);
		i = 0;
	}
	if(diffHauteur == 2 || diffHauteur == -2){
		eqNoeud(avl, &pere, &nd);
	}
}

void eqNoeud(AVL **avl, noeudAvl **pere, noeudAvl **nd){
	if(*nd == (*pere)->fg){
		if(getDiffHauteur(*pere) == -2){
			if(getDiffHauteur(*nd) < 1){
				rotationDroite(avl, pere);
			}else{
				rotationGauche(avl, nd);
				rotationDroite(avl, pere);
			}
		}
	}else{
		if(getDiffHauteur(*pere) == 2){
			if(getDiffHauteur(*nd) > -1){
				rotationGauche(avl, pere);
			}else{
				rotationDroite(avl, nd);
				rotationGauche(avl, pere);
			}
		}
	}
}


void setHauteur(noeudAvl **nd, int newhauteur){
	if(*nd != NULL){
		(*nd)->hauteur = newhauteur;
	}
}

int getHauteur(noeudAvl *nd){
	if(nd == NULL){
		return 0;
	}
	return nd->hauteur;
}

int getDiffHauteur(noeudAvl *nd){
	return getHauteur(nd->fd) - getHauteur(nd->fg);
}



int max(int x, int y){
	if(x<y) return y;
	return x;
}

void afficheInfixe(noeudAvl *nd, int hauteur, bigInt *pereValue){//test aussi la cohérence de l'arbre
	if(nd != NULL){
		afficheInfixe(nd->fg, hauteur+1, nd->value);
		printf("h : %d :", hauteur);
		afficheBigInt(nd->value);
		afficheInfixe(nd->fd, hauteur+1, nd->value);
		if(nd->pere != NULL && pereValue == NULL){perror("erreur pere\n");exit(0);}
		if(nd->pere != NULL && pereValue != NULL && (! eg(*pereValue, *(nd->pere->value)))){perror("error pointeur pere pour fils:");afficheBigInt(nd->value);
		printf("pere : "); afficheBigInt(nd->pere->value); printf("expected : "); afficheBigInt(pereValue);exit(0);}

	}
}

void afficheAVLInfixe(AVL *avl){
	printf("Affichage de l'avl, (clefs croissantes) : \n\n");
	afficheInfixe(avl->racine, 1, NULL);
}
