#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() { CARTE c; list_t l1,l2,l3,l4,l5,l6,l7;
  l1=list_new(); l2=list_new();
  l3=list_new(); l4=list_new();
  l5=list_new(); l6=list_new();
  l7=list_new();

  printf("\n----------------------------------------------\n");
  printf("Test des copies et concatenations\n");
  printf("----------------------------------------------\n");

  c.rang=11; c.couleur= COEUR; l1=list_add_first(c,l1);
  c.rang=8; c.couleur= COEUR; l1=list_add_first(c,l1);
  c.rang=7; c.couleur= CARREAU; l1=list_add_first(c,l1);
  c.rang=12; c.couleur= PIQUE; l1=list_add_first(c,l1);
  c.rang=9; c.couleur= PIQUE; l1=list_add_first(c,l1);
  printf("Liste l1: "); list_print(l1);
  printf("-------------------------------\n");

  c.rang=10; c.couleur= CARREAU; l2=list_add_first(c,l2);
  c.rang=1; c.couleur= TREFLE; l2=list_add_first(c,l2);
  c.rang=3; c.couleur= CARREAU; l2=list_add_first(c,l2);
  c.rang=5; c.couleur= PIQUE; l2=list_add_first(c,l2);
  printf("Liste l2: "); list_print(l2);
  printf("-------------------------------\n");

  l4=list_copy(l1);
  printf("\n----------------------------------------------\n");
  printf("Copie de l1 dans l4\n");
  printf("l1 et l4 ont des maillons differents\n");
  printf("----------------------------------------------\n");
  printf("Liste l1: "); list_print(l1);
  printf("Liste l4: "); list_print(l4);

  l5=l1;
  printf("\nAffectation de la liste l1 dans l5\n");
  printf("l1 et l5 partagent les memes maillons\n");
  printf("-------------------------------\n");
  printf("Liste l5: "); list_print(l5);
  printf("Liste l1: "); list_print(l1);

  printf("\n----------------------------------------------\n");
  printf("Concatenation de l2 a la suite de l1 dans l3 \n");
  printf("l3 partage ses maillons avec l1 et l2\n");
  printf("----------------------------------------------\n");
  l3=list_concat(l1,l2);
  printf("Liste l1: "); list_print(l1);
  printf("Liste l2: "); list_print(l2);
  printf("Liste l3: "); list_print(l3);
  printf("Liste l4: "); list_print(l4);
  printf("Liste l5: "); list_print(l5);

  printf("\n----------------------------------------------\n");
  printf("Concatenation d'une liste vide avec une autre liste \n");
  printf("----------------------------------------------\n");
  l7=list_concat(l6,l2);
  printf("Liste l6: "); list_print(l6);
  printf("Liste l2: "); list_print(l2);
  printf("Liste l7: "); list_print(l7);

  printf("\n----------------------------------------------\n");
  printf("Liberation de toutes les listes\n");
  printf("----------------------------------------------\n");
  printf("Liberation de l1\n");
  l1=list_delete(l1);
  printf("Ne pas liberer l2 car l1 est maintenant chainee avec l2 : l3=list_concat(l1,l2)\n");
  printf("Ne pas liberer l3 car elle est deja liberee a travers l1 \n");
  printf("Liberation de l4\n");
  l4=list_delete(l4);
  printf("Ne pas liberer l5 car elle est deja liberee a travers l1\n");
  printf("Ne pas liberer l6 car elle est vide\n");
  printf("Ne pas liberer l7 car elle est deja liberee a travers l2\n");
  exit(EXIT_SUCCESS);
}
