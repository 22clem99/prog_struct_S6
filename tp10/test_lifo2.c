#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"


int main() { CARTE c; lifo_t unepile; int i;
  unepile=lifo_new();
  /* Suite aleatoire de XX empiler de depiler */
  /* initialisation du generateur aleatoire */
  printf("--------------------------------------\n" );
  printf("On teste XX fois aleatoirement\n");
  printf("Les cartes sont generees aleatoirement et peuvent etre donc tirees plusieurs fois\n");
  printf("--------------------------------------\n" );
  srand(10);
  for (i=0; i<100; i++) {
    switch(rand()%2) {
      case 0:
          c.rang=1+rand()%13; c.couleur=rand()%4; unepile=lifo_push(c,unepile);
          printf("On empile :"); element_print(c);  puts("");
          break;
      case 1:
          printf("On depile :");
          if (!lifo_is_empty(unepile)) {
            c = lifo_pop(&unepile);
            printf("La carte defilee est : "); element_print(c);  puts("");
          }
          else
            printf("La pile est vide \n");
          break;
    }
    printf("Voici la pile :"); lifo_print(unepile);
    printf("--------------------\n" );
  }
}
