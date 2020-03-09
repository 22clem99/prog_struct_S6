#ifndef _GRAPH_PRINT
#define _GRAPH_PRINT

#include "fifo.h"
#include "lifo.h"
#include <SDL2/SDL_phelma.h>

  /* Decalage entre 2 cartes d'une pile ou file
  lors de l'affichage de celles-ci
  x est la position en abcisse de la pile ou file
  y est la position en ordonnée de la pile ou file
  le point de coordonnees 0,0 est eb haut à gauche
  */
#define DECALAGE 10

	/* Affichage graphique d'une carte */
void card_draw(CARTE* e, SDL_PHWindow*  f1,int x, int y);

	/* Efface une carte */
void card_erase(CARTE* e, SDL_PHWindow*  f1,int x, int y);

	/* Affiche une pile */
void lifo_draw(lifo_t p, SDL_PHWindow*  f1, int x, int y) ;

	/* Efface une pile */
void lifo_erase(lifo_t p, SDL_PHWindow*  f1, int x, int y);

	/* Affiche une file implemente par une liste circulaire */
void fifo_draw(fifo_t L, SDL_PHWindow*  f1, int x, int y) ;

	/* Efface toute une file */
void fifo_erase(fifo_t L, SDL_PHWindow*  f1, int x, int y) ;

void lifo_draw_dec(lifo_t p, SDL_PHWindow*  f1, int x, int y, int decalage) ;

void lifo_erase_dec(lifo_t p, SDL_PHWindow*  f1, int x, int y, int decalage);

void fifo_draw_dec(fifo_t L, SDL_PHWindow*  f1, int x, int y, int decalage);

void fifo_erase_dec(fifo_t L, SDL_PHWindow*  f1, int x, int y, int decalage);

#endif
