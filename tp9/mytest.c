#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main (void)
{
  CARTE c;
  list_t l1=NULL;

  l1 = list_new ( l1 );

  c.rang = AS; 
  c.visible = 1;
  c.couleur = COEUR;

  l1 = list_add_first( c, l1);

  c.rang = 3;
  c.visible = 1;
  c.couleur = PIQUE;

  l1 = list_add_first( c, l1);

  list_print(l1);

  return(0);
}
