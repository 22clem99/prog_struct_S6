#include "expression.h"
#include "expressionplot.h"
#include "fonctions.h"
#include "simplifie.h"

int main(int argc, char** argv) { char s[512];
  double xmin=-5, xmax=5;
  binarytree_t r=NULL;
  int dx=400,dy=200;
  SDL_PHWindow* f1;


  	/*
	   Lecture d'une expression prefixe au clavier
 	 */
  printf("Ce programme teste l'affichage, l'evaluation et le trace d'un arbre d'expression\n");
  puts("Entrer une expression en notation prefixee avec des espaces entre chaque symbole");
  puts("Exemple : + * 3 x * 7 x");
  fgets(s,511,stdin); s[strlen(s)-1]=0;
  r=expression_sscanf(s);
 	 /*
	Affichage de cette expression en notation classique
 	 */
  puts("Expression :"); expression_print_infixe(r); puts("");

  /*
  	Ouverutre d'une fenetre et affichage graphqie
  */
  if ( (f1=SDL_PH_CreateWindow(dx,dy)) !=NULL) {
    puts("Entrer les bornes du trace (xmin et xmax): attention au domaine de definition");
    scanf("%lf %lf",&xmin,&xmax);
    expression_plot_one(f1,r,dx,xmin,xmax);
    getchar(); getchar();
  }

  /*
	Liberation de la memoire de l'arbre
  */
  r=binarytree_del(r);
  if (f1) SDL_PH_DestroyWindow(f1);
  SDL_Quit();
  return 0;
}
