#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"


int main() { CARTE c; fifo_t unefile;
  unefile=fifo_new();

  /* Enfiler et defiler une carte */
  printf("-----------------------------------------\n" );
  printf("Test de enfiler et defiler 1 cartes\n");
  printf("-----------------------------------------\n" );
  c.rang=1; c.couleur=TREFLE; unefile=fifo_enqueue(c,unefile);
  printf("On enfile :"); element_print(c);  puts("");
  printf("Voici la file :"); fifo_print(unefile);
  if (!fifo_is_empty(unefile)) {
    c = fifo_dequeue(&unefile);
    printf("La carte defilee est : "); element_print(c); puts("");
    printf("Voici la file :"); fifo_print(unefile);
  }
  printf("-----------------------------------------\n" );

  /* Enfiler et defiler 2 cartes */
  printf("\n-----------------------------------------\n" );
  printf("Test de enfiler et defiler 2 cartes\n");
  printf("-----------------------------------------\n" );
  c.rang=1; c.couleur=CARREAU; unefile=fifo_enqueue(c,unefile);
  printf("On enfile :"); element_print(c);  puts("");
  printf("Voici la file :"); fifo_print(unefile);
  printf("-------------------\n" );
  c.rang=1; c.couleur=PIQUE; unefile=fifo_enqueue(c,unefile);
  printf("On enfile :"); element_print(c);  puts("");
  printf("Voici la file :"); fifo_print(unefile);
  printf("-------------------\n" );
  if (!fifo_is_empty(unefile)) {
    c = fifo_dequeue(&unefile);
    printf("La carte defilee est : "); element_print(c); puts("");
    printf("Voici la file :"); fifo_print(unefile);
    printf("-------------------\n" );
  }
  if (!fifo_is_empty(unefile)) {
    c = fifo_dequeue(&unefile);
    printf("La carte defilee est : "); element_print(c); puts("");
    printf("Voici la file :"); fifo_print(unefile);
    printf("-------------------\n" );
  }
  printf("-----------------------------------------\n" );

  /* Enfiler et defiler 2 cartes */
  printf("\n-----------------------------------------\n" );
  printf("Test de enfiler et defiler 3 cartes\n");
  printf("-----------------------------------------\n" );
  c.rang=1; c.couleur=TREFLE; unefile=fifo_enqueue(c,unefile);
  printf("On enfile :"); element_print(c);  puts("");
  printf("Voici la file :"); fifo_print(unefile);
  printf("-------------------\n" );
  c.rang=1; c.couleur=CARREAU; unefile=fifo_enqueue(c,unefile);
  printf("On enfile :"); element_print(c);  puts("");
  printf("Voici la file :"); fifo_print(unefile);
  printf("-------------------\n" );
  c.rang=1; c.couleur=PIQUE; unefile=fifo_enqueue(c,unefile);
  printf("On enfile :"); element_print(c);  puts("");
  printf("Voici la file :"); fifo_print(unefile);
  printf("-------------------\n" );
  if (!fifo_is_empty(unefile)) {
    c = fifo_dequeue(&unefile);
    printf("La carte defilee est : "); element_print(c); puts("");
    printf("Voici la file :"); fifo_print(unefile);
    printf("-------------------\n" );
  }
  if (!fifo_is_empty(unefile)) {
    c = fifo_dequeue(&unefile);
    printf("La carte defilee est : "); element_print(c); puts("");
    printf("Voici la file :"); fifo_print(unefile);
    printf("-------------------\n" );
  }
  if (!fifo_is_empty(unefile)) {
    c = fifo_dequeue(&unefile);
    printf("La carte defilee est : "); element_print(c); puts("");
    printf("Voici la file :"); fifo_print(unefile);
  }
  printf("-----------------------------------------\n" );


  /* Enfiler et defiler 4 cartes */
  printf("\n-----------------------------------------\n" );
  printf("Test de enfiler et defiler 3 cartes\n");
  printf("-----------------------------------------\n" );
  c.rang=1; c.couleur=TREFLE; unefile=fifo_enqueue(c,unefile);
  printf("On enfile :"); element_print(c);  puts("");
  printf("Voici la file :"); fifo_print(unefile);
  printf("-------------------\n" );
  c.rang=11; c.couleur=CARREAU; unefile=fifo_enqueue(c,unefile);
  printf("On enfile :"); element_print(c);  puts("");
  printf("Voici la file :"); fifo_print(unefile);
  printf("-------------------\n" );
  c.rang=5; c.couleur=PIQUE; unefile=fifo_enqueue(c,unefile);
  printf("On enfile :"); element_print(c);  puts("");
  printf("Voici la file :"); fifo_print(unefile);
  printf("-------------------\n" );
  c.rang=9; c.couleur=COEUR; unefile=fifo_enqueue(c,unefile);
  printf("On enfile :"); element_print(c);  puts("");
  printf("Voici la file :"); fifo_print(unefile);
  printf("-------------------\n" );
  if (!fifo_is_empty(unefile)) {
    c = fifo_dequeue(&unefile);
    printf("La carte defilee est : "); element_print(c); puts("");
    printf("Voici la file :"); fifo_print(unefile);
    printf("-------------------\n" );
  }
  if (!fifo_is_empty(unefile)) {
    c = fifo_dequeue(&unefile);
    printf("La carte defilee est : "); element_print(c); puts("");
    printf("Voici la file :"); fifo_print(unefile);
    printf("-------------------\n" );
  }
  if (!fifo_is_empty(unefile)) {
    c = fifo_dequeue(&unefile);
    printf("La carte defilee est : "); element_print(c); puts("");
    printf("Voici la file :"); fifo_print(unefile);
    printf("-------------------\n" );
  }
  if (!fifo_is_empty(unefile)) {
    c = fifo_dequeue(&unefile);
    printf("La carte defilee est : "); element_print(c); puts("");
    printf("Voici la file :"); fifo_print(unefile);
    printf("-------------------\n" );
  }

  /* Defiler une file vide */
  printf("\n-----------------------------------------\n" );
  printf("Test de Defiler une file vide\n");
  printf("-----------------------------------------\n" );
  if (!fifo_is_empty(unefile)) {
    c = fifo_dequeue(&unefile);
    printf("La carte defilee est : "); element_print(c); puts("");
  }
  else
    printf("La file est vide\n");
  printf("Voici la file :"); fifo_print(unefile);

  printf("\n-----------------------------------------\n" );
  printf("Liberation memoire\n");
  printf("-----------------------------------------\n" );
  unefile=fifo_delete(unefile);
  exit(EXIT_SUCCESS);
}
