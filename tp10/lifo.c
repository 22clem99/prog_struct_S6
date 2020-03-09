#include "lifo.h"
#include <stdio.h>
#include <stdlib.h>

lifo_t lifo_new(void) {
  return NULL;
}

int lifo_is_empty(lifo_t p) 
{
  return list_is_empty(p);
}

lifo_t lifo_push (CARTE e,lifo_t p)
{
  return list_add_first(e,p);
}

lifo_t lifo_del_first(lifo_t p) 
{
  return (lifo_t) list_del_first ((list_t)(p));
}

/* la pile n'est pas modifiée */
CARTE lifo_peek(lifo_t p)
{
  return list_first(p);
}

CARTE lifo_pop(lifo_t* ap)	/* attention: la pile est modifiee */
{	  
  CARTE c = (*ap)->val;
  *ap= lifo_del_first(*ap);
  return c;
}

int lifo_length(lifo_t p) 
{  
  return list_length ((list_t) p);
}

void lifo_print(lifo_t p) 
{
  list_print((list_t) p);
}

lifo_t lifo_delete(lifo_t p) 
{
  return list_delete((list_t) p);
}
