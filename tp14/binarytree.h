#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifndef _BINARYTREE
#define _BINARYTREE
#include "element.h"

typedef struct noeud {
  element_t value;
  struct noeud* left, *right; } node_t,* binarytree_t;

// Detruit et libere tous les noeuds d'un arbre
binarytree_t binarytree_del(binarytree_t r) ;
// Detruit et libere le neoud r uniquement
binarytree_t node_del(binarytree_t r) ;
// Retourne 1 si l'arbre est vide, 0 sinon
int binarytree_is_empty(binarytree_t);
// Creer un arbre vide
binarytree_t binarytree_new();
// Clone et copie tous les noeuds d'un arbre
binarytree_t binarytree_clone(binarytree_t b);
// Retourne 1 si tous les noeuds de l'arbre sont egaux
// au sens de la fonction element_equal
int binarytree_equal(binarytree_t r1, binarytree_t r2) ;

// Transforme un double en chaine de caractres en supprimant
// les zeros inutiles
char* double2string(double x, char* s) ;

/*
  Chaine resultat d'operation binaire de 2 noeuds
  contenant des VALEURS
*/
char* string_operation(char* a1,char* sv, char op);

#endif
