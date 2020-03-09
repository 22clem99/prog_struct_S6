#include "expressionplot.h"
#include "expression.h"
#include "simplifie.h"
#include "fonctions.h"



int main(int argc, char** argv) { char s[512];
  double xmin=-5, xmax=5;
  binarytree_t r=NULL, d=NULL;
  int dx=300,dy=200;
  SDL_PHWindow* f1;

  /*
	Lecture d'une expression prefixe au clavier
  */
  printf("Ce programme teste la derivation d'un arbre d'expression\n");
  puts("Entrer une expression en notation prefixee avec des espaces entre chaque symbole");
  puts("Exemple : + * 3 x * 7 x");
  fgets(s,511,stdin); s[strlen(s)-1]=0;
  r=expression_sscanf(s);

  /*
	Affichage de cette expression en notation classique
  */
  puts("Expression :"); expression_print_infixe(r); puts("");

  /*
	Derivation et Affichage de cette derivee en notation classique
        Simplification et Affichage de cette derivee en notation classique
  */
  puts(""); puts("Derivee");
  expression_print_infixe(d=expression_derivation(r));
  puts("");

  // Version ou on ne construit pas les arbres inutilement
  binarytree_t ds;
  puts(""); puts("Derivee sinplifiee"); expression_print_infixe(ds=(expression_deriv_simplify(r))); puts("");

  if ( (f1=SDL_PH_CreateWindow(dx,dy)) != NULL) {
    puts("Entrer les bornes du trace (xmin et xmax): attention au domaine de definition");
    scanf("%lf %lf",&xmin,&xmax);
        /*	       Trace des 2 courbes          */
    expression_plot_two(f1,r,d,dx,xmin,xmax);
    getchar(); getchar();
  }
  r=binarytree_del(r);
  d=binarytree_del(d);
  if (f1) SDL_PH_DestroyWindow(f1);
  SDL_Quit();
  return 0;
}
