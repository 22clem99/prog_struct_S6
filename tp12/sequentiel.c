#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "divers.h"
#include <ctype.h>
#include "list.h"

int main(int a, char **b)
{ list_t  histo;
  int nbtotal=0;
  char mot[512];
  FILE *fp;
  clock_t debutrecherche,finrecherche;

  if ( a!=2) { printf("Usage : %s fichier \n",b[0]); exit(1); }

  // Creation du dictionnaire
  histo=list_new();

  // Ouverture du fichier texte dont il faut calculer l'hitogramme
  if ( (fp=fopen(b[1],"r")) == NULL) { printf("Erreur lecture fichier\n"); exit(EXIT_FAILURE); }
  printf("Nombre de mots : %6d",nbtotal);fflush(stdout);

  debutrecherche=clock();
  while (file_read_word(fp,mot) !=0) {
    if (strcmp(mot,"")!=0 && strcmp(mot," ")!=0 ) {
      nbtotal++;
      printf("\b\b\b\b\b\b%6d",nbtotal); fflush(stdout);
      list_t plist = list_find_key(mot,histo);
      if (plist==NULL) { element_t e;
        e=element_new(mot,1);
        histo=list_add_first(e,histo);
      }
      else {
        plist->val.value++;
      }
    }
  }
  puts("");
  finrecherche=clock();

  // Affichage de l'histogramme
  printf("\nHistogramme par liste chainee\n");
  //list_print(histo);
  histo=list_sort_value(histo);
  list_print(histo);
  printf("\n\nLa duree de construction de l'histogramme est %lf\n",
    (double)(finrecherche-debutrecherche)/CLOCKS_PER_SEC);
  printf("\nHistogramme trie par liste chainee\n");

  // Liberation memoire
  list_delete(histo);
  fclose(fp);
}
