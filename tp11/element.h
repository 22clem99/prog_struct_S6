#ifndef _ELEMENT
#define _ELEMENT

#define AS 1
#define VALET 11
#define DAME 12
#define ROI 13

typedef enum { TREFLE,CARREAU,COEUR,PIQUE} COULEUR;

#ifdef MODEGRAPHIQUE
typedef struct { unsigned int** data; int lig, col; } ICONE;
typedef struct {
  int rang;
  char visible;
  COULEUR couleur;
  ICONE im,dos;
  }  CARTE;
#else
typedef struct {
  int rang;
  char visible;
  COULEUR couleur;
  }  CARTE;
#endif

typedef CARTE element_t;

void element_print (CARTE e);
void element_init (CARTE* e);
CARTE element_empty();
int element_is_empty(CARTE e);
int element_equal(CARTE*, CARTE*);
#endif
