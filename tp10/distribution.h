#ifndef _DISTRIBUTION
#define _DISTRIBUTION
#include "fifo.h"
#include "lifo.h"
#include <stdlib.h>
#include <string.h>


CARTE prend_une_carte(char* tab, int nbcarterestant ) ;
int distribution(fifo_t* aj1, fifo_t *aj2, int alea, int nbcarte); 

#endif
