#include "expression.h"
#include <ctype.h>

/* cette grammaire est recursicve à droite et ne prend en cimpte correctemetn que les
+ et les *
*/

binarytree_t  Expression(char** r);
binarytree_t Terme(char** r);
binarytree_t Facteur(char** r);
binarytree_t  erreur(char** r);
binarytree_t Fonction(char** r);
binarytree_t NombreOuVariable(char** r);
binarytree_t Analyse(char* r);
binarytree_t Puissance(char** r);
