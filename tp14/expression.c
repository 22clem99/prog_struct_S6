#include "expression.h"
/*
  Fonction de creation d'un noeud a partir d'une chaine de caracteres contenant:
  Role :
     - alloue un espace memoire necessaire a un oeoud
     - alloue et copie la chaine dans le noeud (champ val)
     - met a jour le type du noeud en fonction de la chaine
          - variable
          - constante
          - operateur unaire (sin, cos, tan, sqrt, ...)
          - operateur binaire (+,-,*,/,^^)
*/
expression_t expression_node_new(char *c) {
  expression_t r=NULL;

  if (c==NULL || *c=='\0') { puts("Erreur de syntaxe"); exit(1); }
  TYPE t = element_type(c);

  if (t==PASDEFINI) {
    printf("%s : fonction non implantee\n",c);
    exit(EXIT_FAILURE);
  }
  /* Allocation memoire d'un noeud */
  r=calloc(1,sizeof(*r));
  if (r==NULL) { puts("Plus assez de memoire "); exit(EXIT_FAILURE); }

  r->value=element_new(c,t);
  return r;
}

/*
   Focntion construisant un arbre a partir d'une chaine decoupee en mots

   Algo :
     recupere le premier mot de la chaine par la fonction strtok(NULL," ")
     si ce mot est
       - une constante ou une variable : construit et retourne le noued contenant cette constante ou cette variable
       - un operateur unaire :
               construit le noued contenant cet operateur;
               Le fils droit de ce noeud est vide.
               le fils gauche de ce noeud est le sous arbre obtenu par le reste de l'expression en cours d'analyse
               retourne le noued ainsi obtenu
       - un operateur binaire :
               construit le noued contenant cet operateur;
               le fils gauche de ce noeud est le sous arbre obtenu par le reste de l'expression en cours d'analyse. Cette analyse s'arrete a la fin de l'expression contenant le fils gauche car les expressions sont bien construites
               Le fils droit de ce noeud est le sous arbre obtenu par le reste de l'expression en cours d'analyse
               retourne le noued ainsi obtenu
*/
static expression_t expression_new(char *c) {
  expression_t r=NULL;
  r=expression_node_new(c);
  switch(r->value.type) {
    case OPERATEUR_BINAIRE:
         r->left=expression_new(strtok(NULL," "));
         r->right=expression_new(strtok(NULL," "));
         return r;
    case OPERATEUR_UNAIRE :
         r->right=expression_new(strtok(NULL," ")); return r;
    case VARIABLE: case VALEUR:
         return r;
    default : node_del(r); return NULL;
  }
  return NULL;
}

/*
  Fonction qui construit un arbre a partir d'une expression.
  Elle decoupe la chaine en suite de mot (fonction strtok). Les appels suivants a strtok permettront de recuperer les mots les uns apres les autres.
  Elle appelle ensuite la creation d'un arbre a partir d'une suite de mots
*/
expression_t expression_sscanf(char *s) {
  char *c = strtok(s," ");
  return expression_new(c);
}


////////////////////////////////////////////
void expression_print_infixe(expression_t r) 
{
  switch (r->value.type)
  {
  case OPERATEUR_UNAIRE:
    break;

  case OPERATEUR_BINAIRE:

    if (0==strcasecmp(r->value.string,"+"))
    {
      expression_print_infixe(r->left);
      printf("+");
      expression_print_infixe(r->right);
    }
    if (0==strcasecmp(r->value.string,"-"))
    {
      expression_print_infixe(r->left);
      printf("-");
      expression_print_infixe(r->right);
    }
    if (0==strcasecmp(r->value.string,"*"))
    {
      if ((0==strcasecmp(r->left.string,"+"))||(0==strcasecmp(r->left.string,"-"))) { printf("("); }
      expression_print_infixe(r->left);
      printf("*");
      expression_print_infixe(r->right);
      if((0==strcasecmp(r->right.string,"+"))||(0==strcasecmp(r->right.string,"-"))) { printf(")"); }
    }
    if (0==strcasecmp(r->value.string,"/"))
    {
      if ((0==strcasecmp(r->left.string,"+"))||(0==strcasecmp(r->left.string,"-"))) { printf("("); }
      expression_print_infixe(r->left);
      printf("/");
      expression_print_infixe(r->right);
      if((0==strcasecmp(r->right.string,"+"))||(0==strcasecmp(r->right.string,"-"))) { printf(")");}
    }
    if (0==strcasecmp(r->value.string,"^"))
    {
      expression_print_infixe(r->left);
      printf("^");
      expression_print_infixe(r->right);
    }
    break;

  case VALEUR:
    element_print(r->value);
    break;
  case VARIABLE:
    element_print(r->value);
    break;
  
  default:
  printf("erreur")
    break;
  }
 
}

double expression_eval(expression_t r, double x) {
  //TODO

  return 0;
}


expression_t expression_derivation(expression_t r) {
  //TODO
   return NULL;
}


int expression_equal(expression_t r1, expression_t r2) {
  return 0;
}
