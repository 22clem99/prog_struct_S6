#include "expression.h"
#include <ctype.h>
#include "analyse.h"


binarytree_t  erreur(char** r) { printf("Erreur : %s \n",*r); return NULL; }

binarytree_t  Terme(char** r){
  /* TODO */
 return NULL;
}

binarytree_t Fonction(char** r){
  /* TODO */
  return NULL;
}

binarytree_t NombreOuVariable(char** r){
  if (isalnum(**r)) {
    return (expression_node_new(*r));
  }
  else return NULL;
}

binarytree_t Facteur(char** r){
  /* TODO */
  return NULL;
}

binarytree_t Expression(char** r){
    binarytree_t s1=NULL, s2, res;
    char s3[32];

    if (*r == NULL) return erreur(r);
    s1=Terme(r);
    if (s1 && *r && ( (**r == '+') || (**r == '-')) ){
        strcpy(s3,*r);
        *r=strtok(NULL," ");
        s2=Expression(r);
	      if (s2 == NULL) return erreur(r);
        res = expression_node_new(s3);
        res->left=s1; res->right=s2;
        return ( res);
    }
    return s1;
}

binarytree_t Analyse(char* r){
    char * t;
    binarytree_t s;
    t=strtok(r," ");
    s=Expression(&t);
    if (strtok(NULL," ")!=NULL)  {puts("Expression non valide"); return erreur(&t); }
    return s;
}
