#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() { CARTE c; list_t l1;
  char rep; int n;
  l1=list_new();
  do {
    printf("quitter(0); Ajouter en tete(1); Ajouter en queu(2); Supprimer en tete(3); visualiser_liste(4); Supprimer en n (5)"); fflush(stdout);
    rep=getchar();
    switch(rep) {
      case '1': printf("Valeur(1..13) et couleur (0..3) \n"); scanf("%d %d",&(c.rang),&(c.couleur));
                if (c.rang>=1 && c.rang<=13 && c.couleur>=TREFLE && c.couleur<=PIQUE) l1=list_add_first(c,l1);
		else printf("Erreur de saisie %d %d\n",c.rang,c.couleur);
                break;
      case '2': printf("Valeur(1..13) et couleur (0..3) \n"); scanf("%d %d",&(c.rang),&(c.couleur));
                if (c.rang>=1 && c.rang<=13 && c.couleur>=TREFLE && c.couleur<=PIQUE) l1=list_add_last(c,l1);
		else printf("Erreur de saisie %d %d\n",c.rang,c.couleur);
                break;
      case '3': l1=list_del_first(l1); break;
      case '4': list_print(l1); break;
      case '5': printf("Quelle est la position a supprimer ? \n");
            scanf("%d",&n);
            if (n>=0)
                l1=list_remove_n(n,l1);
            break;
    }
    getchar();
  } while (rep !='0');
  printf("Liberation des listes\n");
  l1=list_delete(l1);
}
