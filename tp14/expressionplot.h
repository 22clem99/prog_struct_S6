#include "expression.h"
#include <SDL2/SDL_phelma.h>

SDL_PHWindow* SDL_PH_CreateWindow(int,int);
void expression_plot_one(SDL_PHWindow*  f1, binarytree_t r, int nb, double xmin, double xmax);
void expression_plot_two(SDL_PHWindow*  f1, binarytree_t r, binarytree_t d, int nb, double xmin, double xmax);
void expression_min_max(binarytree_t r, int n, double xmin, double xmax, double* min, double* max) ;
void expression_plot_min_max(SDL_PHWindow* f1, binarytree_t r, int NBP, double xmin, double xmax, double ymin, double ymax, int coul) ;
