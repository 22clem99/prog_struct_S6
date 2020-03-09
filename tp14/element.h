#ifndef _ELEMENT
#define _ELEMENT
#include <string.h>

// Type enumere pour une lecture plus simple du code
typedef enum { PASDEFINI, OPERATEUR_BINAIRE, OPERATEUR_UNAIRE, VALEUR, VARIABLE } TYPE;

/* Un neoud contient 2 informations :
     - une chaine de caracteres
     - la nature (type) de la chaine
*/
typedef
  struct {
    char* string;
    TYPE type;
  } element_t;


  // Principales fonctions utiles sur les elements
  // Afficher la valeur d'un element
void element_print (element_t e);
  // Tester l'egalite de 2 elements
int element_equal(element_t*, element_t*);
  // Cloner et copier un element
element_t element_clone(element_t e);
  // Creer un nouvel element a partir d'une chaine et d'un type
element_t element_new(char*, TYPE );
  // Detruire et liberer la memoire allouee a un element
element_t element_delete(element_t e);
  // Definit le type de x selon OPERATEUR_BINAIRE, OPERATEUR_UNAIRE, VALEUR, VARIABLE
TYPE element_type(char* x);

#endif
