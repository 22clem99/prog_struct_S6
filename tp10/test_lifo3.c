#include <stdio.h>
#include "lifo.h"


int main() { CARTE c; lifo_t l;
  char rep;
  l=lifo_new();
  do {
    printf("quitter(0); Empiler(1); Depiler(2); Visualiser(3); "); fflush(stdout);
    rep=getchar();
    switch(rep) {
      case '1':
        printf("Valeur(1..13) et couleur (0..3) \n"); scanf("%d %d",&(c.rang),&(c.couleur));
        if (c.rang>=1 && c.rang<=13 && c.couleur>=TREFLE && c.couleur<=PIQUE) {
          printf("On empile : ");
          element_print(c); puts("");
          l=lifo_push(c,l);
        }
        break;
      case '2':
        if (!lifo_is_empty(l)) {
          c=lifo_pop(&l);
          printf("La carte depilee est :");
          element_print(c); puts("");
        }
        else
          printf("La pile est vide\n");
        break;
      case '3': lifo_print(l);
        break;
    }
    getchar();
  } while (rep !='0');
}
