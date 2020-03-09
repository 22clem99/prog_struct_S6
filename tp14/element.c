#include "element.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void element_print (element_t e) {
  printf("%s ", e.string);
}

element_t element_empty() {
  element_t e;
  e.string=NULL;
  e.type=PASDEFINI;
  return e;
}

int element_is_empty(element_t e) {
  element_t vide=element_empty();
  return element_equal(&e,&vide);
}

int element_equal(element_t* e1, element_t* e2) {
  return (strcasecmp(e1->string,e2->string)==0);
}

element_t element_clone(element_t e) {
  element_t clone;
  clone=element_new(e.string,e.type);
  return clone;
}

element_t element_new(char* s, TYPE t) {
  element_t e;
  e.string=strdup(s);
  e.type=t;
  return e;
}

element_t element_delete(element_t e) {
  if (e.string) free(e.string);
  e=element_empty();
  return e;
}

// Retourne le type de noeud correspondant a une chaine de caracteres
TYPE element_type(char* c) { double x;
  /* Est ce un nombre ? */
  if (sscanf(c,"%lf",&x)==1) {
    return VALEUR;
  }
  switch(*c) {
  /* Est ce un operateur classique? */
    case '+' : case '-': case '*': case '/' : case'^':
         return OPERATEUR_BINAIRE;
  /* Est ce une variable ? */
    case 'x': case 'y' :
          return VARIABLE;
  }
  /* Est ce une fonction connue ? */
  if (!strcasecmp(c,"sin") || !strcasecmp(c,"cos") || !strcasecmp(c,"tan") || !strcasecmp(c,"sqrt")
      || !strcasecmp(c,"exp") || !strcasecmp(c,"log")) {
        return OPERATEUR_UNAIRE;
  }
  /* moins unaire pour tester */
  if (!strcasecmp(c,"u-")){
    return OPERATEUR_UNAIRE;
  }
  return PASDEFINI;
}
