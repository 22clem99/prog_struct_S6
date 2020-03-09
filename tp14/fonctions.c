#include "expression.h"

/*
  Double vers chaine avec suppression des 0 inutiles
*/
char* double2string(double x, char* s) {int i;
  sprintf(s,"%lf",x);
  for(i=strlen(s)-1; i>0 && s[i]=='0'; i--) s[i]=0;
  if (i>0 && s[i]=='.')s[i]=0;
  return s;
}

/*
  Chaine resultat d'operation binaire de 2 noeuds
  contenant des VALEURS
*/
char* string_operation(char* a1,char* sv, char op) {
  char s[512];
  double v,v1, v2;
  v1=atof(a1); v2=atof(sv);
  switch(op) {
    case '+' : v=v1+v2; break;
    case '-' : v=v1-v2; break;
    case '*' : v=v1*v2; break;
    case '/' : v=v1/v2; break;
    case '^' : v=pow(v1,v2); break;
    default: v=0;
  }
  double2string(v,s);
  return strdup(s);
}
