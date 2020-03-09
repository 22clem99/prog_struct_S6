#include <stdio.h>
#include <stdlib.h>

#include <memory.h>
#include "heap.h"
#include "heapsort.h"
#include "element.h"

#define DIM 20

/*
  Affiche les elements du tableau
*/
void afficheTab(int* tab,  int nb) {  int i;
  for (i=0; i<nb; i++)  { element_print(tab[i]); }
  puts("");
}

/*
  fonction de comparaison utilse pour le quick sort
*/
int compar( const void* ax, const void * ay) {
  return( ELEMENT_COMPARE((int *)ax,(int *)ay));
}

int main(int a, char**b) {
    /* Creation de 2 tableaux d'au plus DIM elements */
  int t1[DIM], t2[DIM];
  int i;
  int nb; // Taille reelle du tableau
  FILE* fp;

  if (a<2) {puts("Usage : testTas Nom_fichier_donnees"); exit(EXIT_FAILURE);}

    // Ouverture du fichier de donnees
  fp=fopen(b[1],"r");
  if (fp==NULL) { puts("Pas de fichier de test"); exit(EXIT_FAILURE);}

    // Lecture de nombre d'elements du tableau
  fscanf(fp,"%d ",&nb);
  if (nb<0 || nb > DIM) {printf("Erreur format fichier %s",b[1]); exit(EXIT_FAILURE);}

  // Lecture, tri, affichage et verification du tri des differents tableaux
  // contenus dnas le fichier
  do {
    // Lecture des elements d'un tableau sur une ligne
    for (i=0; i<nb; i++)
      fscanf(fp,"%d ",t1+i);
    // Copie dnas le deuxieme tableau
    memcpy(t2,t1,sizeof(t1));
    // Affichage du tableau non trie
    printf("Tableau de %d elements : ",nb);
    afficheTab(t1,nb);
    // tri du tableau par mon tri par tas
    heap_sort(t1,nb);
    // Affichage du tableau trie
    puts("resultats");
    afficheTab(t1,nb);
    // Tri par quick sort et verification du tri par tas
    qsort(t2,nb,sizeof(*t2),compar);
    printf("COmparaison avec le quick sort : ");
    if ( memcmp(t1,t2,sizeof(t1))!=0) {printf("Erreur de tri"); exit(EXIT_FAILURE);}
    else printf("Le tri est correct\n");
  } while(!feof(fp));


}
