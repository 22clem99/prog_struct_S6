#include "heap.h"

heap_t heap_new(int m) {
  heap_t tas;
  
  tas.data = calloc ( m, sizeof(element_t));
  tas.max_size = m;
  tas.number = 0;

  return tas;
}

int heap_is_empty(heap_t tas) 
{
  return (!tap.number);
}

/* Ajoute l'element valeur au tas pointe par ptas */
int heap_add(element_t valeur, heap_t* ptas) 
{
  int i= ptas->number, j;
  *(ptas->data + ptas->number) = valeur; //
  do
  {
    j = HEAP_FATHER(i);
    if (element_compare(ptas->data + i, ptas->data + j )==1)
    {
      swap ( ptas->data + i, ptas->data + j);
      i=j;
    }
    else
    {
      break;
    }    
  } while ( i != 0);
  ptas->number+=1;
  return 0;
}


/* Retourne l'indice du plus grand des deux fils ou -1 si c'est une feuille */
static int heap_largest_son(heap_t tas, int indice) 
{
  int f_1 = HEAP_LEFTSON (indice), f_2 = HEAP_RIGHTSON(indice), res;
  if (!element_is_empty(tas.data[f_1])&&!element_is_empty(tas.data[f_2]))
  {
    if (ELEMENT_COMPARE(tas.data[f_1],tas.data[f_2])==1)
    {
      res = f_1;
    }
    else
    {
      res = f_2;
    }
  }
  else
  {
    if (element_is_empty(tas.data[f_1]))
    {
      res = f_2
    }
    else
    {
      res = f_1;
    }
  }
  
  return res;
}

/* Supprimer la racine en la remplacant par le dernier element du tas */
int heap_delete_max(heap_t* ptas) 
{
  int i = 0, j = ;

  swap (ptas->data,ptas->data + ptas->number -1);
  ptas->number--;
  do
  {

  } while (i != ) 
  return 1;
}


void heap_delete(heap_t* ptas) {
}

/* Retourne l'element max */
element_t heap_get_max(heap_t tas) {
  return tas.data[0];
}

/* Affiche le tas a l'ecran */
void heap_print(heap_t tas) {
  for (int i=0; i<tas.number; i++)
    element_print(tas.data[i]);
  puts("");
}

/*
  Verifie la propriete des tas sur tous les noeuds :
  le pere est plus grand que les 2 fils
*/

int heap_verification(heap_t tas) {
  int i;
  for (i=0; i< tas.number/2; i++) {
  if (ELEMENT_COMPARE(tas.data+i,tas.data+HEAP_LEFTSON(i))<0) return i;
    if (HEAP_RIGHTSON(i)<tas.number && tas.data[i]<tas.data[HEAP_RIGHTSON(i)]) return i;
  }
  return -1;
}


//POUR LE PLAISIR !!!!!!!!
static void swap ( element_t * a, element_t * b )
{
  element_t tmp;

  tmp = *a;
  *a = *b;
  b* = tmp;
}