#include <stdio.h>
#include "lifo.h"


int main() { CARTE c; lifo_t unepile;
  unepile=lifo_new();
  /* Empiler une carte */
  printf("-----------------------------------------\n" );
  printf("Test de empiler et depiler une carte\n");
  printf("-----------------------------------------\n" );
  c.rang=1; c.couleur=TREFLE; unepile=lifo_push(c,unepile);
  printf("On enpile :"); element_print(c);  puts("");
  printf("La pile est : "); lifo_print(unepile);

  /* Depiler une carte */
  if (!lifo_is_empty(unepile)) {
    puts("On depile"); c = lifo_pop(&unepile);
    printf("La carte depilee est : "); element_print(c); puts("");
    printf("La pile est : "); lifo_print(unepile);
  }
  printf("-----------------------------------------\n" );

  /* Empiler 2 cartes */
  printf("\n-----------------------------------------\n" );
  printf("Test de empiler et depiler 2 cartes\n");
  printf("-----------------------------------------\n" );
  c.rang=1; c.couleur=CARREAU; unepile=lifo_push(c,unepile);
  printf("On enpile :"); element_print(c);  puts(""); lifo_print(unepile);
  printf("--------------------\n" );
  c.rang=1; c.couleur=PIQUE; unepile=lifo_push(c,unepile);
  printf("On enpile :"); element_print(c);  puts(""); lifo_print(unepile);
  printf("--------------------\n" );
  /* Depiler 2 cartes */
  if (!lifo_is_empty(unepile)) {
    puts("On depile"); c = lifo_pop(&unepile);
    printf("La carte depilee est : "); element_print(c); puts("");
    printf("La pile est : "); lifo_print(unepile);
  }
  printf("--------------------\n" );
  if (!lifo_is_empty(unepile)) {
    puts("On depile"); c = lifo_pop(&unepile);
    printf("La carte depilee est : "); element_print(c); puts("");
    printf("La pile est : "); lifo_print(unepile);
  }
  printf("-----------------------------------------\n" );

  printf("\n-----------------------------------------\n" );
  printf("Test de empiler 3 cartes, depiler une carte, empiler 2 cartes,");
  printf(" depiler 1 carte, empiler 1 carte\n");
  printf("-----------------------------------------\n" );
  c.rang=1; c.couleur=TREFLE; unepile=lifo_push(c,unepile);
  printf("On enpile :"); element_print(c);  puts("");
  printf("La pile est : "); lifo_print(unepile);
  printf("--------------------\n" );
  c.rang=1; c.couleur=CARREAU; unepile=lifo_push(c,unepile);
  printf("On enpile :"); element_print(c);  puts("");
  printf("La pile est : "); lifo_print(unepile);
  printf("--------------------\n" );
  c.rang=1; c.couleur=PIQUE; unepile=lifo_push(c,unepile);
  printf("On enpile :"); element_print(c);  puts("");
  printf("La pile est : "); lifo_print(unepile);
  printf("--------------------\n" );
  if (!lifo_is_empty(unepile)) {
    puts("On depile"); c = lifo_pop(&unepile);
    printf("La carte depilee est : "); element_print(c); puts("");
    printf("La pile est : "); lifo_print(unepile);
    printf("--------------------\n" );
  }
  c.rang=1; c.couleur=PIQUE; unepile=lifo_push(c,unepile);
  printf("On enpile :"); element_print(c);  puts("");
  printf("La pile est : "); lifo_print(unepile);
  printf("--------------------\n" );
  c.rang=9; c.couleur=COEUR; unepile=lifo_push(c,unepile);
  printf("On enpile :"); element_print(c);  puts("");
  printf("La pile est : "); lifo_print(unepile);
  printf("--------------------\n" );
  if (!lifo_is_empty(unepile)) {
    puts("On depile"); c = lifo_pop(&unepile);
    printf("La carte depilee est : "); element_print(c); puts("");
    printf("La pile est : "); lifo_print(unepile);
    printf("--------------------\n" );
  }
  c.rang=9; c.couleur=COEUR; unepile=lifo_push(c,unepile);
  printf("On enpile :"); element_print(c);  puts("");
  printf("La pile est : "); lifo_print(unepile);
  printf("-----------------------------------------\n" );

  /* Tester la liberation de pile */
  printf("\n-----------------------------------------\n" );
  printf("Test de la liberation complete de la pile\n" );
  printf("-----------------------------------------\n" );
  unepile=lifo_delete(unepile);
  printf("-----------------------------------------\n" );

  /* Tester la visualisation de la pile qui doit etre vide */
  printf("La pile est : "); lifo_print(unepile);
}
