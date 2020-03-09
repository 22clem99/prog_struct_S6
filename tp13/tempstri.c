#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <sys/times.h>

#include "element.h"
#include "heap.h"
#include "heapsort.h"

#define MAX_DIM_SELECTION 10000

/* fonction de comparaison utilse pour le quick sort */
int compar( const void* ax, const void * ay) {
  return(ELEMENT_COMPARE((int*)ax,(int*)ay));
}

/* Tri par selection a titre de comparaison */
void selection_sort(element_t* t, int size) { int i,j,imax;
  for (i=0; i<size; i++) {
    imax=0;
      /* Recherche du maximum de la partie non triee du tableau*/
    for(j=1; j<size-i; j++)
      if (ELEMENT_COMPARE(t+imax,t+j)<0)
        imax=j;
        /* Echange du maxima et du dernier element non encore trie */
    element_t tmp=t[imax];
    t[imax]=t[size-i-1];
    t[size-i-1]=tmp;
  }
}

/*
  Ce programme affiche le temps d'execution du tri qsort de la bilbiotheque C et
  de votre tri par tas en fonction du nombre d'element a trier
*/

int  main(){
  int total_number; 			/* Nombre de reels a trier : */
  clock_t avant, apres;
  double temps1, temps2, temps3;
  FILE* fp;
  int *t1, *t2, *t3;
  int j,k,l;

	/*  Nombre maximal d'elements  */
  printf("Affichage et comparaison de votre heap_sort, du quick sort du C et du tri par selection\n");
  printf("Au dela de %d elements, le tri par selection ne sera pas teste\n",MAX_DIM_SELECTION);
  printf("Quel est le nombre maximal d'element a trie (0..100000000) ?"); fflush(stdout);
  scanf("%d", &total_number);
  if (total_number<=0) total_number = 1E5;

	/* Creation des tableaux a trier : un avec le qsort, un avec votre tri */
  if ( (t1=calloc(total_number,sizeof(*t1))) == NULL
      || (t2=calloc(total_number,sizeof(*t1))) == NULL
      || (t3=calloc(total_number,sizeof(*t1))) == NULL) {
    printf("Allocation impossible\n");
    exit(EXIT_FAILURE);
  }

  /* Ouverture d'un fichier contenant les resultats */
  fp =fopen("tempstri.dat","w");

	/* Initialisation du generateur aleatoire */
  srandom(getpid());

	/* Premiere boucle sur le nombre d'element a trier */
  /* k est le nombre d’elements a trier */
  for (k=1; k<=total_number; k*=10) {
    /* On moyenne les temps de chaque tri sur 10 realisations */
    temps1=temps2=0;
    if (k<=MAX_DIM_SELECTION) temps3=0;
    for (j=1; j<10; j++) {
		     /* Tirage aleatoire des nombres a trier */
      for (l=0; l<k; l++) t1[l]=random();
		      /* Copie dans le deuxieme et troisieme  tableau */
      memcpy(t2,t1,k*sizeof(*t1));
      memcpy(t3,t1,k*sizeof(*t1));

          /* Tri par quick sort */
      avant=clock();	    qsort(t1,k,sizeof(*t1),compar);      apres=clock();
      temps1+=((double)apres - avant)/CLOCKS_PER_SEC;

 	      /* Tri par ma fonction heap_sort*/
      avant = clock();      heap_sort(t2,k);      apres = clock();
      temps2+=((double)apres - avant)/CLOCKS_PER_SEC;
      if (memcmp(t1,t2,k*sizeof(*t1))!=0) fprintf(stderr,"Erreur de tri ..................................\n");

      /* Tri par selection s'il n'y a pas trop d'element */
      if (k<=MAX_DIM_SELECTION) {
        avant = clock();        selection_sort(t3,k);        apres = clock();
        temps3+=((double)apres - avant)/CLOCKS_PER_SEC;
      }
    }

	     /* Affichage des temps des 3 tris dans le fichier */
    if (k<=MAX_DIM_SELECTION) printf("%d\t%lf\t%lf\t%lf\n", k, temps1/10, temps2/10, temps3/10);
    else printf("%d\t%lf\t%lf\n", k, temps1/10, temps2/10);
    if (fp) {
      if (k<=MAX_DIM_SELECTION) fprintf(fp,"%d\t%lf\t%lf\t%lf\n", k, temps1/10, temps2/10, temps3/10);
      else fprintf(fp,"%d\t%lf\t%lf\n", k, temps1/10, temps2/10);
    }
        /* Verification des tris */
    if (memcmp(t1,t2,k*sizeof(*t1))!=0) fprintf(stderr,"Erreur de tri ..................................\n");
  }

  if (fp) {
    fclose(fp);
    system("gnuplot -p -e \"set logscale x; plot 'tempstri.dat' u 1:2 with line lt 4 title 'quickSort', '' u 1:3 with line lt 2 title 'MonTriHeap',  '' u 1:4 with line lt 6 title 'Tri selection'; quit\"");
  }

	/* Liberation memoire */
  free(t1); free(t2); free(t3);
  return EXIT_SUCCESS;
}
