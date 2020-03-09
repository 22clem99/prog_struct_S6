#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"


int main() { CARTE c; fifo_t unefile; int i;
  unefile=fifo_new();
  /* Suite aleatoire de XX enfiler de defiler */
  /* initialisation du generateur aleatoire */
  printf("On teste XX fois aleatoirement\n");
  printf("Les cartes sont generees aleatoirement et peuvent etre donc tirees plusieurs fois\n");
  srand(10);
  for (i=0; i<100; i++) {
    switch(rand()%2) {
      case 0:
          c.rang=1+rand()%13; c.couleur=rand()%4; unefile=fifo_enqueue(c,unefile);
          printf("On enfile :");
          break;
      case 1:
          if (!fifo_is_empty(unefile)) {
            c = fifo_dequeue(&unefile);
            printf("La carte defilee est : ");
            element_print(c);  puts("");
          }
          else
            printf("La file est vide \n");
          break;

    }
    printf("Voici la file :"); fifo_print(unefile);
  }
  exit(EXIT_SUCCESS);
}
