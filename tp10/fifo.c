#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>

fifo_t fifo_new(void){
  return NULL;	/* la liste vide est representée par NULL	*/
}

int fifo_is_empty(fifo_t L)
{
  return L==NULL;	/* la liste vide est representée par NULL	*/
}

void fifo_print(fifo_t L) 
{
  fifo_t p = NULL;

  if (fifo_is_empty(L))
  {
    printf("()\n");
  }
  else
  {
    printf("(");
    p = L->next;
    do
    {
      element_print (p->val);
      p = p->next; 
    }while (p!=L->next);
    printf(")\n");
  }
}

fifo_t fifo_enqueue(CARTE e, fifo_t f)
{
  fifo_t c = calloc( 1, sizeof( *c ) );

  if ( NULL == c ) // l'allocation echoue...
  {
    fprintf( stderr, "Fatal: Unable to allocate new list link.\n" );
    return f;
  }

  c->val = e; //remplir la première case

  if (!fifo_is_empty(f)) //si la liste n'est pas vide
  {
    c->next=f->next; //Faire pointer la nouvelle case avec la tete 

    f->next=c; //faire pointer l'ancienne queue vers la nouvelle queue
  }
  else //si la liste est vide
  {
    c->next=c;
  }
  
  return c; // on retourne la nouvelle queue
}

CARTE fifo_peek(fifo_t f)
{
  return (f->next)->val;
}

fifo_t fifo_del_head(fifo_t f) 
{
  fifo_t p=f->next;
  if (f!=p)  //on a plusieur élement
  {
    f->next = p->next;
    free(p);
  }
  else  //il n'y a qu'un élement
  {
    free(f);
    f=NULL;
  }
  
  return f;
}

CARTE fifo_dequeue(fifo_t* af) 
{
  CARTE c = fifo_peek (*af);
  *af = fifo_del_head (*af);
  return c;
}

fifo_t fifo_delete(fifo_t f) 
{
  while (f!=NULL)
  {
    f = fifo_del_head( f );
  };

  return f;
}
