#include "distribution.h"
#include <stdlib.h>
#include <string.h>


CARTE take_one_card(char* tab, int nbcarterestant ) { CARTE c;
  int i,j, r;
  j=nbcarterestant!=0 ? random()%nbcarterestant : 0;
  r=tab[j];
  i=tab[j]; tab[j]=tab[nbcarterestant-1]; tab[nbcarterestant-1]=i;
  c.rang=1+r/4; c.couleur=r%4; c.visible=0;
  return c;
}

int distribution(fifo_t* aj1, fifo_t* aj2, int alea, int nbcarte) { int i;
  CARTE c;
  char* tab=calloc(nbcarte*4,1); /* Indique les cartes restantes  */
  for(i=0; i<nbcarte*4; i++) tab[i]=i;
  srandom(alea);        /* initialisation du generateur aleatoire */
  for (i=0; i<nbcarte*4/2; i++) {
    c=take_one_card(tab,nbcarte*4-2*i); *aj1=fifo_enqueue(c,*aj1);
    c=take_one_card(tab,nbcarte*4-2*i-1); *aj2=fifo_enqueue(c,*aj2);
  }
  free(tab); tab=NULL;
  return 1;
}
