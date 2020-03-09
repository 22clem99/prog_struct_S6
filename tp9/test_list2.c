#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() { CARTE c; list_t l1; int n;
  l1=list_new();
  printf("----------------------------------------------\n");
  printf("Test de la suppression en position\n");
  printf("----------------------------------------------\n");
  c.rang=11; c.couleur= COEUR; l1=list_add_first(c,l1);
  c.rang=8; c.couleur= COEUR; l1=list_add_first(c,l1);
  c.rang=7; c.couleur= CARREAU; l1=list_add_first(c,l1);
  c.rang=12; c.couleur= PIQUE; l1=list_add_first(c,l1);
  c.rang=9; c.couleur= PIQUE; l1=list_add_first(c,l1);
  c.rang=10; c.couleur= CARREAU; l1=list_add_first(c,l1);
  c.rang=1; c.couleur= TREFLE; l1=list_add_first(c,l1);

  printf("Liste l1: "); list_print(l1);
  n=4;
  printf("\n\nSuppression de la position %d\n",n);
  printf("-----------------------------\n");
  l1 = list_remove_n(n,l1);
  printf("Liste l1: "); list_print(l1);

  n=1;
  printf("\n\nSuppression de la position %d\n",n);
  printf("-----------------------------\n");
  l1 = list_remove_n(n,l1);
  printf("Liste l1: "); list_print(l1);

  n=4;
  printf("\n\nSuppression de la position %d\n",n);
  printf("-----------------------------\n");
  l1 = list_remove_n(n,l1);
  printf("Liste l1: "); list_print(l1);

  n=-1;
  printf("\n\nSuppression de la position %d\n",n);
  printf("-----------------------------\n");
  l1 = list_remove_n(n,l1);
  printf("Liste l1: "); list_print(l1);

  n=10;
  printf("\n\nSuppression de la position %d\n",n);
  printf("-----------------------------\n");
  l1 = list_remove_n(n,l1);
  printf("Liste l1: "); list_print(l1);

  n=1;
  printf("\n\nSuppression de la position %d\n",n);
  printf("-----------------------------\n");
  l1 = list_remove_n(n,l1);
  printf("Liste l1: "); list_print(l1);

  n=1;
  printf("\n\nSuppression de la position %d\n",n);
  printf("-----------------------------\n");
  l1 = list_remove_n(n,l1);
  printf("Liste l1: "); list_print(l1);

  n=1;
  printf("\n\nSuppression de la position %d\n",n);
  printf("-----------------------------\n");
  l1 = list_remove_n(n,l1);
  printf("Liste l1: "); list_print(l1);

  n=1;
  printf("\n\nSuppression de la position %d\n",n);
  printf("-----------------------------\n");
  l1 = list_remove_n(n,l1);
  printf("Liste l1: "); list_print(l1);

  printf("----------------------------------------------\n");
  printf("Liberation des listes\n");
  printf("----------------------------------------------\n");
  l1=list_delete(l1);
}
