#ifndef _EXPRESSION
#define _EXPRESSION
#include "binarytree.h"
#include "element.h"

typedef binarytree_t expression_t;

// Creation d'un noeud dans un arbre d'expression a partir d'une chaine
expression_t expression_node_new(char *c);

// Creation d'un arbre d'expression a partir d'une chaine
expression_t expression_sscanf(char *s) ;

// Affichage infixe d'une expression
void expression_print_infixe(expression_t);

// Retourne la valeur de l'arbre d'expression pour la valeur de x
double expression_eval(expression_t r, double x);

// Retourne un arbre d'expression correspondant à la derivation symbolique
// de l'arbre d'expression r
expression_t expression_derivation(expression_t r);

// Retourne 1 si les 2 expressions sont egales
// 2 expressions sont egales si les arbres sont identiques
// ou si dans le cas d'operateurs commutatifs (+ et *)
// le fils gauche de l'un est le fils droit de l'autre
int expression_equal(expression_t r1, expression_t r2) ;

// Retourne un arbre d'expression correspondant à la derivation symbolique
// de l'arbre d'expression r
// Simplifie a la construction les cas particuliers.
// Par exemple, 1+x ==> 1 et non 0 + x
expression_t expression_deriv_simplify(expression_t r);

#endif
