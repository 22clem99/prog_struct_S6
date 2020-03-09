//
//  simplifie.c
//
//
//  Created by Michel Desvignes on 09/03/2017.
//
//
#include "expression.h"
#include "fonctions.h"
#include "simplifie.h"
binarytree_t simplifie1(binarytree_t r);
binarytree_t simpl2(binarytree_t r);
binarytree_t distribution( binarytree_t r) ;
binarytree_t ajouteSousArbre(binarytree_t a, char* r, char typea, char typer) ;



char antiOp(char op) {
  switch(op) {
    case '+': return '-';
    case '-': return '+';
    case '*': return '/';
    case '/': return '*';
  }
  /* Ne seert a rien */
  return '=';
}

int memeCatOp(char op1, char op2) {
  if (op1==op2 || op1==antiOp(op2)) return 1;
  else return 0;
}

char typeOp(char op) {
  switch(op) {
    case '+':case '-': return '+';
    case '*':case '/': return '*';
  }
  // Ne sert a rien
  return ' ';
}

char typeOpBrancheGauche(binarytree_t a) {
  return typeOp(a->value.string[0]);
}

char typeOpBrancheDroite(binarytree_t a) {
  return a->value.string[0]=='+'|| a->value.string[0]=='*' ? a->value.string[0] : antiOp(typeOp(a->value.string[0]));
}

char typeOp2Noeud(char c1, char c2) {
  if(c1==c2) return typeOp(c1);
  else return antiOp(typeOp(c1));
}

/* a est la feuille doirte de 0 - x */
/* Return NULL si pas simplifie , l'arbre simplifie sinon
 si x=a-b, retourne b-a
 si x=a+b, retourne simplMoinsUnaire(a) - b ou simplMoinsUnaire(b) - a
 si x=a*b, retourne simplMoinsUnaire(a) * b ou simplMoinsUnaire(b) * a
 si x=a/b, retourne simplMoinsUnaire(a) / b ou simplMoinsUnaire(b) / a */
binarytree_t simplMoinsUnaire(binarytree_t a) { binarytree_t c;
  if (a==NULL || a->value.type==VARIABLE) return NULL;
  if (a->value.type==VALEUR) { char s[512];
    double2string(-1*atof(a->value.string),s);
    free(a->value.string); a->value.string=strdup(s);
    return a;
  }
  if (a->value.type==OPERATEUR_BINAIRE){
    switch (a->value.string[0]) {
      case '-': c=a->left; a->left=a->right; a->right=c; return a;
      case '+':
        if ( (c=simplMoinsUnaire(a->left))!=NULL) { a->left=c; a->value.string[0]='-';  return a;}
        else if ( (c=simplMoinsUnaire(a->right))!=NULL) { a->right=a->left; a->left=c; a->value.string[0]='-'; return a;}
            else return NULL;
      case '*': case '/':
        if ( (c=simplMoinsUnaire(a->left))!=NULL) { a->left=c;  return a;}
        else if ( (c=simplMoinsUnaire(a->right))!=NULL) { a->right=c;  return a;}
          else return NULL;
      default: return NULL;
    }
  }
  if (a->value.type==OPERATEUR_UNAIRE )  {
    if (a->value.string[0]=='-') { binarytree_t b=a->right; node_del(a); return b; }
    else
      //if ( (c=simplMoinsUnaire(a->right))!=NULL) { a->right=c;  return a;}
      //else
        return NULL;
    }
  return NULL;
}

/* retournze l'arbre modife avec ajout de r (qui est une constnnat) dans une constante de l'arbre, NULL si on ne peut ajoute v a l'arbre
A est l'arbre dnas lequel on ajoute
r est le chaine contenant la constnante a ajouter
typea = '+' poour une addition qui se proepage '-' pour une soustraction : arbre a addirif ou multiplicatif
typer = idem, mais pour le neoud r
Exemple :
ajout de 5 a  + 2 + x x retourne + 7 + x x
ajout de 5 a  + x + x x retourne NULL
*/

binarytree_t ajouteSousArbre(binarytree_t a, char* r, char  typea, char typer) {
  char type;
  if (a==NULL || a->value.type==VARIABLE) return NULL;
  if (a->value.type==VALEUR ) { type = typeOp2Noeud(typea,typer);
    char* tmp=a->value.string;
    type = typeOp2Noeud(typea,typer);
    a->value.string=string_operation(r,a->value.string,type);
    free(tmp);
    return a;
  }
  if (a->value.type==OPERATEUR_BINAIRE && a->value.string[0]!='^') {binarytree_t c1,c2,c; c=c1=c2=NULL;
    switch (a->value.string[0]) {
      case '+': case '-': case'*': case '/':
      type = typeOp2Noeud(typea,typer);
      /* cas d'un arbre avec un noued + dans un arbre multiplication ou 'inverse */
        if (  ((a->value.string[0]=='+'||a->value.string[0]=='-')&& (type!='+' && type!='-')) ||
              ((a->value.string[0]=='*'||a->value.string[0]=='/')&& (type!='*' && type!='/')) )
                {  return NULL;}
                /* le neoud est une valeur, on fai tl'operation et on retrouen */
          if (a->left->value.type==VALEUR){ type = typeOp2Noeud(typea,typer);
            char* tmp=a->left->value.string;
            a->left->value.string=typea=='-'||typea=='/' ? string_operation(a->left->value.string,r,type) : string_operation(a->left->value.string,r,type);
            free(tmp);
            return a;
          }
          else if (a->right->value.type==VALEUR){ type = typeOp2Noeud(typea,typer);
            char* tmp=a->right->value.string;
            char op;
            if (a->value.string[0]==type) op=(type=='+'||type=='-')?'+':'*';
            else op=(type=='+'||type=='-')?'-':'/';
            a->right->value.string=string_operation(a->right->value.string,r, op);
            free(tmp);
            return a;
          }
          else { char op; type = typeOp2Noeud(typea,typer);
            if (a->value.string[0]==type) op=(type=='+'||type=='-')?'+':'*';
            else op=(type=='+'||type=='-')?'-':'/';
            if ( (c= ajouteSousArbre(a->left,r,typea,typer))!=NULL ||
              (c= ajouteSousArbre(a->right,r,op,typer))!=NULL) {
               return a;
            }
            else return NULL;
          }
      }
    }
    return NULL;
  }

/* Recherche un noued portant une constante et indique s'i lest dnas une branche +,-,* ou/ */
binarytree_t rechCte(binarytree_t a,char* ptype) {
  if (a==NULL)return a;
  else {
    if (a->value.type==OPERATEUR_BINAIRE)
      if (memeCatOp(*ptype,a->value.string[0])) {
        binarytree_t c=rechCte(a->left,ptype);
        if (c)return c;
        else { if (a->value.string[0]=='-'||a->value.string[0]=='/') *ptype= antiOp(*ptype);
          return rechCte(a->right,ptype);
        }
      }
      else return NULL;
    else
      if (a->value.type==OPERATEUR_UNAIRE && a->value.string[0]=='-') {
          *ptype= antiOp(*ptype);
          return rechCte(a->right,ptype);
      }
      else
        if(a->value.type==VALEUR) return a;
        else return NULL;
  }
}

/*
  Recherche les constantes dans les sous branches pour remonter les operations entre constantes
  dans un arbre.
  Pour chaque constante trouvee, cherche une autre constante de meme type (additive ou multiplicative)
  grace a la fonction ajouteSousArbre
  */
binarytree_t simpl2(binarytree_t a) { binarytree_t c,c1,c2,c3;
  if (a==NULL) return NULL;
  if (a->value.type==OPERATEUR_UNAIRE) {
    a->right=simpl2(a->right); return a;
  }
  if (a->value.type==VALEUR || a->value.type==VARIABLE ) return a;
  a->left=simpl2(a->left);
  a->right=simpl2(a->right);

  if (a->value.type==OPERATEUR_BINAIRE && a->value.string[0]!='^') {
    if (a->left->value.type==VALEUR){  c1=a->right; c2=a->left; c=ajouteSousArbre(c1,c2->value.string,a->value.string[0],typeOp(a->value.string[0])); }
    else if (a->right->value.type==VALEUR){  c1=a->left; c2=a->right; c=ajouteSousArbre(c1,c2->value.string,typeOp(a->value.string[0]),a->value.string[0]);}
    else {c1=c2=NULL;}
    if (c1 || c2) {
      if (c==NULL) return a;
      else { /* on a trouve une constante dans a et dnas le sousarbre a->left ou a->right et fait l'operation
               cette constante et a; le resultat est dnas la constnante, donc on supprime a indirectement
               en mettant 0 pour une addition et 1 pour une multiplication qui seront supprimes
               par la prochaine Simplification
               */
          free(c2->value.string);
          if (a->value.string[0]=='+' || a->value.string[0]=='-') { c2->value.string=strdup("0");}
          else {  c2->value.string=strdup("1"); }
          return a;
      }
    }
    else { char typebranche=typeOp(a->value.string[0]);
      c3=rechCte(a->left,&typebranche);
      if (c3) { c=ajouteSousArbre(a->right,c3->value.string,a->value.string[0],typebranche);
        if (c!=NULL) {
          free(c3->value.string);
          if (a->value.string[0]=='+' || a->value.string[0]=='-') { c3->value.string=strdup("0");}
          else { c3->value.string=strdup("1");}
          a->right=simpl2(a->right);
        }
      }
      typebranche=typeOp(a->value.string[0]);
      c3=rechCte(a->right,&typebranche);
      if (c3) { c=ajouteSousArbre(a->left,c3->value.string,a->value.string[0],typebranche);
        if (c!=NULL) {
          free(c3->value.string);
          if (a->value.string[0]=='+' || a->value.string[0]=='-') { c3->value.string=strdup("0");}
          else { c3->value.string=strdup("1"); }
          a->left=simpl2(a->left);
          return (a);
        }
      }
      else return a;
    }
  }
  return a;
}



#define SWAP(x,y,type) { type inter; inter=(x); (x)=(y); (y)=inter; }

binarytree_t simplifie1(binarytree_t r) {
    //r = distribution(r);
    if (r!=NULL) {
        switch(r->value.type) {
            case PASDEFINI: printf("Valeur non coherente : %s \n",r->value.string); exit(0);
            case VALEUR: case VARIABLE : return r;
            case OPERATEUR_UNAIRE:
              r->right=simplifie1(r->right);
              if (r->right && r->right->value.type==VALEUR) {char s[512];
                double2string(expression_eval(r,0),s);
                binarytree_del(r);
                return expression_node_new(s);
              }
              return r;
            case OPERATEUR_BINAIRE :
              r->left=simplifie1(r->left);
              r->right=simplifie1(r->right);

                  /* Cas de constante operator constante */
                if (r->right && r->right->value.type==VALEUR && r->left && r->left->value.type==VALEUR) { char s[512];
                    double2string(expression_eval(r,0),s);
                    binarytree_del(r);
                    return expression_node_new(s);
                }
                if(r->value.string[0]=='+') { binarytree_t right=r->right, left=r->left, c=NULL;
                      /* Cas du x+0 ou 0+x */
                    if((right->value.type==VALEUR && atof(right->value.string)==0 && (c=right)!=NULL) || (left->value.type==VALEUR && atof(left->value.string)==0&& (c=left)!=NULL)){
                        node_del(r); node_del(c);
                        return simplifie1(c==left? right : left);
                    } /* Cas du x + -y unaire ==> x - y*/
		                if (right->value.type==OPERATEUR_UNAIRE && right->value.string[0]=='-') {
		                  r->value.string[0]='-'; r->right=right->right; node_del(right); return r;
		                } /* Cas du -unaire x + y ==> y - x */
    		            if (left->value.type==OPERATEUR_UNAIRE && left->value.string[0]=='-') {
		                  r->value.string[0]='-'; r->left=right; r->right=left->right; node_del(left); return r;
		                }
                      /* cas de + - b a a ==> b */
                    if (left->value.type==OPERATEUR_BINAIRE && left->value.string[0]=='-' && binarytree_equal(left->right,right)) { binarytree_t s=NULL;
                        s=left->left; binarytree_del(left->right); node_del(left); binarytree_del(right); node_del(r); return s;
                    }
                    /* cas de + a - b a  ==> b */
                    if (right->value.type==OPERATEUR_BINAIRE && right->value.string[0]=='-' && binarytree_equal(right->right,left)) {binarytree_t s=NULL;
                        s=right->left; binarytree_del(right->right); node_del(right); binarytree_del(left); node_del(r); return s;
                    }

                    if(right->value.type==VALEUR || left->value.type==VALEUR)  return r;
                    else  return (r);
                }
                else /* Cas du x - 0*/
                  if(r->value.string[0]=='-') { binarytree_t right=r->right, left=r->left, c=NULL;
                    if(right->value.type==VALEUR && atof(right->value.string)==0) { node_del(r); node_del(right); return simplifie1(left); }
                    else { /* Cas du expression - expression */
                      if (binarytree_equal(r->right,r->left)) {
                        binarytree_del(r); return expression_node_new("0");
                      } /* Cas du 0 -x */
                      else  /* On cherche si on peu tsuppirmer le - par transformation de 0 -(a-b) en (b-a) et autres*/
		                    if (left->value.type==VALEUR && atof(left->value.string)==0) {
		                      if ( (c=simplMoinsUnaire(r->right))!=NULL) {
                            node_del(r->left); node_del(r);
                            return c;
                          }
                          else  /* cas du 0 - Variable ==> -unaire Variable */
			                      if (right->value.type==VARIABLE) {
			                           r->left=node_del(r->left); r->value.type=OPERATEUR_UNAIRE;
			                           return r;
			                       }
                             else return r;
                        }
                        else { /* cas du x - -unairey ==> x + y */
                                if (right->value.type==OPERATEUR_UNAIRE && right->value.string[0]=='-') {
                                    r->value.string[0]='+'; r->right=right->right; node_del(right); return r;
                                }
                                if (left->value.type==OPERATEUR_BINAIRE && left->value.string[0]=='+') {
                                    /* cas de - + a b a ==> b */
                                  if (binarytree_equal(left->left,right)) { binarytree_t s=NULL;
                                    s=left->right; node_del(r); binarytree_del(left->left); node_del(left); binarytree_del(right); return s;
                                  }
                                  else /* cas de - + b a a ==> b */
                                    if (binarytree_equal(left->right,right)) {binarytree_t s=NULL;
                                      s=left->left; node_del(r);binarytree_del(left->right); node_del(left); binarytree_del(right); return s;
                                    }
                                }
                                else
                                  if (right->value.type==OPERATEUR_BINAIRE && right->value.string[0]=='-') {
                                    /* cas de - a - a b ==>  b */
                                    if (binarytree_equal(left,right->left)) {binarytree_t s=NULL;
                                      s=right->right; node_del(r);binarytree_del(right->left); node_del(right); binarytree_del(left); return s;
                                    }
                                  }
                                return (r);
                        }
                        //else return (r);
                    }
                }
                else if (r->value.string[0]=='*') { binarytree_t right=r->right, left=r->left;
                    if(right->value.type==VALEUR && atof(right->value.string)==0) { binarytree_del(r); return expression_node_new("0"); }
                    if(left->value.type==VALEUR && atof(left->value.string)==0) { binarytree_del(r); return expression_node_new("0"); }
                    if(right->value.type==VALEUR && atof(right->value.string)==1) { node_del(r); node_del(right); return simplifie1(left); }
                    if(left->value.type==VALEUR && atof(left->value.string)==1) { node_del(r); node_del(left); return simplifie1(right); }
                    /* cas de * / b a a ==> b */
                    if (left->value.type==OPERATEUR_BINAIRE && left->value.string[0]=='/' && binarytree_equal(left->right,right)) { binarytree_t s=NULL;
                      s=left->left; binarytree_del(left->right); node_del(left); binarytree_del(right); node_del(r); return s;
                    }
                    /* cas de * a / b a  ==> b */
                    if (right->value.type==OPERATEUR_BINAIRE && right->value.string[0]=='/' && binarytree_equal(right->right,left)) {binarytree_t s=NULL;
                      s=right->left; binarytree_del(right->right); node_del(right); binarytree_del(left); node_del(r); return s;
                    }
                    return (r);
                }
                else
                  if (r->value.string[0]=='/') { binarytree_t right=r->right, left=r->left, c=NULL;
                    if(left->value.type==VALEUR) {
                      if (atof(left->value.string)==0) {binarytree_del(r); return expression_node_new("0");}
                      /* cas du 1/ (x/y) */
                      if (atof(left->value.string)==1 && right->value.type==OPERATEUR_BINAIRE && right->value.string[0]=='/') {
                        node_del(left); node_del(r); c=right->left; right->left=right->right; right->right=c;
                        return right;
                      }
                      else return r;
                    }
                    else /* Cas de x / 1 */
                      if(right->value.type==VALEUR && atof(right->value.string)==1) { free(r->value.string); free(r);; free(right->value.string); free(right); return simplifie1(left); }
                      else   {/* Cas du expr / expr */
                        if (binarytree_equal(r->right,r->left)) {
                          binarytree_del(r); return expression_node_new("1");
                        }
                        /* cas de / * a b a ==> b */
                        if (left->value.type==OPERATEUR_BINAIRE && left->value.string[0]=='*') {
                          if (binarytree_equal(left->left,right)) { binarytree_t s=NULL;
                            s=left->right; binarytree_del(left->left); node_del(left); binarytree_del(right); node_del(r); return s;
                          }
                          else /* cas de / * b a a ==> b */
                            if (binarytree_equal(left->right,right)) { binarytree_t s=NULL;
                              s=left->left; binarytree_del(left->right); node_del(left); binarytree_del(right); node_del(r); return s;
                            }
                          }
                        return r;
                      }
                    return r;
                  }
                  else if (r->value.string[0]=='^') { binarytree_t right=r->right, left=r->left;
                    if(right->value.type==VALEUR && atof(right->value.string)==1) { node_del(r);; node_del(right); return simplifie1(left); }
                    if(right->value.type==VALEUR && atof(right->value.string)==0) { binarytree_del(r); return(expression_node_new("1")); }
                    return (r);
                }
                else { return r; }
        }
    }
    return r;
}

binarytree_t  binarytree_simplify(binarytree_t r) { binarytree_t r1=NULL;
    do {
        binarytree_del(r1);
        r1=binarytree_clone(r);
        r=simplifie1(r);
        r=simpl2(r);
//        r=distribution(r);
} while (r1 && !binarytree_equal(r1,r));
    binarytree_del(r1);
    return (r);
}


binarytree_t distribution( binarytree_t r) { binarytree_t f3;
    if (r!=NULL) {
        switch(r->value.type) {
            case VALEUR: case VARIABLE : case OPERATEUR_UNAIRE: return r;
            case OPERATEUR_BINAIRE :
	           if(r->value.string[0]=='*' && r->left->value.string[0]=='+') {
	              r->value.string[0]='+'; r->left->value.string[0]='*'; f3=r->right; r->right=expression_node_new("*");
		            r->right->left= r->left->right;  r->left->right=binarytree_clone(f3); r->right->right=f3;
		            return distribution(r);
	           }
	           else
	            if(r->value.string[0]=='*' && r->right->value.string[0]=='+') {
                 r->value.string[0]='+'; r->right->value.string[0]='*'; f3=r->left; r->left=expression_node_new("*");
                 r->left->right= r->right->left;  r->right->left=binarytree_clone(f3); r->left->left=f3;
                 return distribution(r);
	       }
	       else {
	         r->left = distribution(r->left);
	         r->right = distribution(r->right);
		 return r;
	       }
         case PASDEFINI: printf("Valeur non coherente : %s \n",r->value.string); exit(0);
       }
    }
  return r;
}
