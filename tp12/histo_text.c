#include "tadhash.h"
#include <ctype.h>
#include <string.h>
#include "divers.h"
#include <time.h>



int main(int a, char **b)
{ hashtable_t  histo;
  int n, nbtotal=0;
  char mot[512];
  FILE *fp;
  clock_t debut,fin;


  // Le premier parametre de la ligne de commande est le nom du fichier
  // dont on calcule l'histogramme
  // Le deuxiemme parametre est la taille de la table de hashage.
  // Elle ne doit pas etre negative, ni superieure a 10000000
  if ( a!=3) { printf("Usage : %s fichier taille_table\n",b[0]); exit(1); }
  n = atoi(b[2]);
  if (n<=0 || n>10000000) n = 1000;

  // Creation du dictionnaire
  histo=hashtable_new(n);

  // Ouverture du fichier texte dont il faut calculer l'hitogramme
  if ( (fp=fopen(b[1],"r")) == NULL) { printf("Erreur lecture fichier\n"); exit(EXIT_FAILURE); }
  printf("Nombre de mots : %8d",nbtotal);fflush(stdout);

  // Pour le calcul du temps dexecution
  debut=clock();

  // Tant qu'on peut lire un mot dnas le fichier
  while (file_read_word(fp,mot) !=0) {

    // Si le mot n'est pas vide ou un espace
    if (strcmp(mot,"")!=0 && strcmp(mot," ")!=0 ) {
      nbtotal++;
      // Affiche le nombre total de mot traites
      printf("\b\b\b\b\b\b\b\b%8d",nbtotal); fflush(stdout);

      // TODO
      //
      // Mettre a jour l'histogramme pour le nouveau mot lu
      //
      //
      //
      //

    }
  }
  // temps final passe
  fin=clock();

  // Affichage de l'histogramme et du temps passe en secondes
  printf("\nHistogramme par table de hashage\n");
  hashtable_print(histo);
  // hashtable_sort_print(histo);

  // Affichage des performances
  /*
  printf("\n\nLa duree de construction de l'histogramme est %lf\n",
    (double)(fin-debut)/CLOCKS_PER_SEC);

  hashtable_analyse(histo);
  */
  // Liberation memoire; A commenter dans un premier temps.
  hashtable_delete(histo);
  fclose(fp);
}
