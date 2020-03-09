#include "binarytree.h"
#include "element.h"


binarytree_t node_del(binarytree_t a) {
  a->value=element_delete(a->value);
  free(a);
  return NULL;
}

binarytree_t  binarytree_new()  {
  return NULL;
}

int  binarytree_is_empty(binarytree_t r)  {
  return r==NULL;
}


////////////////////////////////////////////////
/*
  Fonction qui libere la memoire alloue pour un arbre
*/
binarytree_t binarytree_del(binarytree_t r) {
  //TODO

  return NULL;
}

binarytree_t binarytree_clone(binarytree_t b) {
  //TODO

  return NULL;
}

int binarytree_equal(binarytree_t r1, binarytree_t r2) {
  //TODO
  return 0;
}
