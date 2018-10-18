#include "fileReader.h"

/*LIT LE PROCHAIN CARACTERE NON VIDE */
char ReadChar(FILE *f){
  char c ;
  do
    c = getc(f) ;
  while (isspace(c)) ;
  return c ;
}

/* SAUT DES ESPACES LORS DE LA LECTURE DANS UN FICHIER POINTE PAR f */

void Skip(FILE *f) {

  char c ;

  while (isspace(c=getc(f))) ;
  ungetc(c,f) ;

}

/* LECTURE DES CARACTERES JUSQU'A LA FIN DU FICHIER OU DE LA LIGNE */

void SkipLine(FILE *f){
  char c ;

  do
    c = getc(f) ;
  while ((c!=EOF)&&(c!='\n')) ;

}

/* LECTURE DE CHAINE DE CARACTERES JUSQU'A UN ESPACE, LA FIN DE LA LIGNE OU LA FIN DE FICHIER */

void GetChaine(FILE *f,int taille_max,char *s)
  {
  char c ;
  int i;

  Skip(f) ;
  i=0;
  c = getc(f) ;
  while (!(isspace(c))&&(c!=EOF)&&(c!='\n')&&(i<taille_max-1)){
    s[i]=c;
    c = getc(f) ;
    i++;
  }
  s[i]='\0';
  ungetc(c,f) ;
  }
