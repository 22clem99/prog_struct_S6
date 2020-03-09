#include "expression.h"
#include "expressionplot.h"
#include "fonctions.h"

#ifndef MAXFLOAT
#define MAXFLOAT 3.40282347e+38F
#endif


#define MIN(x,y) ( (x)>(y)?(y):(x))
#define MAX(x,y) ( (x)<(y)?(y):(x))

void expression_min_max(binarytree_t r, int n, double xmin, double xmax, double* min, double* max) {
  int i ;               /* Variable de boucle */
  double x;

  for (*max = *min = expression_eval(r,xmin),i=1 ; i<n ; i++) {
    x=expression_eval(r,xmin+i*(xmax-xmin)/(n-1));
    if (x< *min) *min=x;
    else if (x> *max) *max=x;
  }
}

/*
	Fonction qui evalue et trace une expression entre xmin et xmax. Les ordonnees sont comprises entre ymin et ymax
*/
void expression_plot_min_max(SDL_PHWindow* f1, binarytree_t r, int NBP, double xmin, double xmax, double ymin, double ymax, int coul) {
  double *t;
  int i;
  if ( (t=calloc(NBP,sizeof(*t)))==NULL) return;
  for (i=0; i<NBP; i++) { t[i]=expression_eval(r,xmin+i*(xmax-xmin)/(NBP-1));  }
  SDL_PH_DrawTabDoubleScaleY(f1,t,NBP,ymin,ymax,coul);
  free(t);
}

/*
	Trace une courbe en rouge sur nb points entre les valeurs xmin et xmax
*/
void expression_plot_one(SDL_PHWindow* f1, binarytree_t r, int nb, double xmin, double xmax)  {
  double min, max;
  int dx=f1->w;
  int dy=f1-> h ;

  expression_min_max(r,nb,xmin,xmax,&min,&max);
  if (max>=MAXFLOAT || min <=-MAXFLOAT) { puts("Hors du domaine de definition"); exit(1); }
  if (min<0 && max>0) lineColor(f1->rendu,0,dy-(int)(dy*min/(min-max)),dx-1,dy-(int)(dy*min/(min-max)),SDL_PH_BLACK);
  if (xmin<0 && xmax>0) lineColor(f1->rendu,(int)(dx*xmin/(xmin-xmax)),0,(int)(dx*xmin/(xmin-xmax)),dy-1,SDL_PH_BLACK);
  expression_plot_min_max(f1,r,dx,xmin,xmax,min,max,SDL_PH_RED);
}

/*
        Trace 2  courbeq en rouge et vert  sur nb points entre les valeurs xmin et xmax
*/

void expression_plot_two(SDL_PHWindow* f1, binarytree_t r, binarytree_t d, int nb, double xmin, double xmax)  {
  double fmin, fmax, dmin, dmax, min, max;
  int dx=f1->w;
  int dy=f1-> h ;

  /*
	Recherche du min et du max des ordonnees du graphe de la fonction et de sa derive
  */
  expression_min_max(r,nb,xmin,xmax,&fmin,&fmax);
  expression_min_max(d,nb,xmin,xmax,&dmin,&dmax);
  min=MIN(dmin,fmin); max=MAX(dmax,fmax);
  if (max>=MAXFLOAT || min <=-MAXFLOAT) { puts("Hors du domaine de definition"); exit(1); }

  /*
	Trace des axes des abcisses et des ordonnees
  */
  if (min<0 && max>0) lineColor(f1->rendu,0,dy-(int)(dy*min/(min-max)),dx-1,dy-(int)(dy*min/(min-max)),SDL_PH_BLACK);
  if (xmin<0 && xmax>0) lineColor(f1->rendu,(int)(dx*xmin/(xmin-xmax)),0,(int)(dx*xmin/(xmin-xmax)),dy-1,SDL_PH_BLACK);
/*
  if (min<0 && max>0) Ligne(f1,0,dy-(int)(dy*min/(min-max)),dx-1,dy-(int)(dy*min/(min-max)));
  if (xmin<0 && xmax>0) Ligne(f1,(int)(dx*xmin/(xmin-xmax)),0,(int)(dx*xmin/(xmin-xmax)),dy-1);
*/

  /*
	Trace de la fonction et de sa derive.
  */
  expression_plot_min_max(f1,r,dx,xmin,xmax,min,max,SDL_PH_GREEN);
  expression_plot_min_max(f1,d,dx,xmin,xmax,min,max,SDL_PH_BLUE);
}
