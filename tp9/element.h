#ifndef _ELEMENT
#define _ELEMENT

typedef enum { TREFLE,CARREAU,COEUR,PIQUE} COULEUR;

typedef struct { int rang; char visible; COULEUR couleur; } CARTE;

typedef CARTE element_t;

#define AS 1
#define VALET 11
#define DAME 12
#define ROI 13


void element_print (CARTE e);
void element_init (CARTE* e);
CARTE element_empty();
int element_is_empty(CARTE e);
int element_equal(CARTE*, CARTE*);
#endif
