#ifndef _DISTRIBUTION
#define _DISTRIBUTION
#include "fifo.h"
#include "lifo.h"
#include <stdlib.h>
#include <string.h>

#ifdef MODEGRAPHIQUE
#include <SDL2/SDL_phelma.h>
// Si les fichiers images des cartes sont dnas votre repertoire, decommenter cette ligne et commenter la suivante
//#define IMAGE_PATH "./cartes/"
// Si les fichiers images des cartes sont sur le serveur de phelma
#define IMAGE_PATH "/users/prog1a/C/librairie/cartes/"
#endif

CARTE take_one_card(char* tab, int nbcarterestant ) ;
int distribution(fifo_t* aj1, fifo_t *aj2, int alea, int nbcarte);
int melanger(fifo_t* aj, int alea, int nbcarte);

#endif
