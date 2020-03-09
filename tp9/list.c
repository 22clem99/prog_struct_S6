// Fichier list.c
#include "list.h"

// Pour plus de proprete des concepts,
// on définit l'identifier NIL (signifiant "fin de liste")
// plutôt que d'utiliser directement NULL (signifiant "pointeur nul")
#define NIL NULL

list_t list_new()
{
  return NIL;
}

int list_is_empty( list_t l )
{
  return NIL == l;
}

list_t list_add_first( element_t e, list_t l )
{
  list_t p = calloc( 1, sizeof( *p ) );
  if ( NULL == p ) {
    fprintf( stderr, "Fatal: Unable to allocate new list link.\n" );
    return l;
  }
  p->val  = e;
  p->next = l;
  return p;
}

list_t list_del_first( list_t l )
{
  assert(!list_is_empty(l));

  list_t p = l->next;
  free( l );
  return p;
}

void list_print(list_t l)
{
  list_t p;
  printf("( ");
  for ( p=l; ! list_is_empty(p); p = p->next) {
    element_print( p->val );
    printf( " " );
  }
  printf(")\n");
}

// Precondition : liste non vide
element_t list_first(list_t l)
{
  assert(!list_is_empty(l));
  return l->val;
}

int list_length(list_t l)
{
  int len = 0;
  list_t p;
  for( p=l; ! list_is_empty(p) ; p=p->next ) {
    len ++;
  }
  return len;
}

list_t list_find(element_t e, list_t l)
{
  list_t p;
  for( p=l; ! list_is_empty(p) ; p=p->next ) {
    if( element_equal(&(p->val), &e) ) {
      return p;
    }
  }
  return NULL;
}

// A completer
//////////////////////////////////////////////////

// Compte le nombre de e dans la liste
int list_count(element_t e, list_t l)
{
  list_t p;
  int count = 0;
  for ( p=l; ! list_is_empty(p); p = p->next)
  {
    if (element_equal(&(p->val), &e))
    {
      count++;
    }
  }
  return (count);
}

// Ajoute en fin de liste
list_t list_add_last(element_t e, list_t l)
{
  list_t c = calloc( 1, sizeof( *c ) ), p=NULL;

  c->val = e;
  c->next = NIL;


  if ( NULL == c )
  {
    fprintf( stderr, "Fatal: Unable to allocate new list link.\n" );
    return l;
  }

  for ( p=l; ! list_is_empty(p); p = p->next) //on cherche le dernier ellement
  {
    if ((p->next)==NIL)
    {
      p->next=c;
      return(l);
    }
  }
}

// Libere toute la liste et retourne une liste vide
list_t list_delete(list_t l)
{
  if (list_is_empty(l)) return NULL;
  if (!list_is_empty(l->next)) list_delete(l->next);

  free(l);
  return NULL;
}

// Concatene 2 listes
list_t list_concat(list_t l1, list_t l2)
{
  list_t p=NULL;
  for ( p=l2; ! list_is_empty(p); p = p->next) //on cherche le dernier ellement
  {
    if (!list_is_empty(l1))
    {
      l1=list_add_last( p->val ,l1);
    }
    else
    {
      l1 = list_add_first( p->val , l1 );
    }
  }
  return l1;
}

// Clone une liste
list_t list_copy(list_t l)
{
  list_t l_copy=NULL,p;
  l_copy=list_new();

  for ( p=l;! list_is_empty(p); p = p->next)
  {
     if (!list_is_empty(l_copy))
     {
       l_copy=list_add_last( p->val ,l_copy);
     }
     else
     {
        l_copy = list_add_first( p->val , l_copy );
     }
  }
  return (l_copy);
}

// Supprime l'element en position n et retourne la nouvelle liste
// Les positions demarrent a 1
list_t list_remove_n(int n, list_t l)
{
  list_t p=NULL, sup;
  int i=1;
  if ((n>=1)&&(n<=list_length(l)))
  {
    if (n==1)
    {
      if (list_length(l)==1)
      {
        p = NIL;
        free(l);
      }
      else
      {
        p = l->next;
        free(l);
      }
    }
    else
    {
      for ( p=l; ! list_is_empty(p); p = p->next) //on cherche le dernier ellement
      {
        if ((i+1)==n)
        {
          sup=p->next;
          p->next = (p->next)->next;
          free(sup);
        }
        i++;
      }
      p=l;
    }
  }
  else
  {
    p=l;
  }

  return p;
}
