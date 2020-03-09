#include "tadhash.h"
#include <ctype.h>
#include <string.h>

#define A 31 

unsigned int hash(char* s, int n) 
{
  int i, len = strlen (s);
  unsigned long h = s[len];

  for (i=len-2; i>=0; i--)
  {
    h = ( h * A + tolower (s[i]);
  }
  h = h % n;
  return (h);
}


hashtable_t hashtable_new(int m) 
{
  return ( calloc ( m, sizeof(*list_t)));
}

int hashtable_put(keys_t k, value_t v, hashtable_t t) 
{
  list_t p;
  int key_pre = 0;
  if ((t[v].size)==0) 
  {
    element_t e;
    e.key = k;
    e.value = 1;
    t[v]->data = list_add_last(e, t[v]->data);
    if (t[v]->data==NULL)
    {
      return 0;
    }
  }
  else
  {
    for( p=t[v]->data; ! list_is_empty(p) ; p=p->next ) 
    {
      if( key_equal((p->val)->key, k)) 
      {
        (p->val)->value++;
        key_pre = 1;
      }
    }
    if (key_pre == 0)
    {
      element_t e;
      e.key = k;
      e.value = 1;
      t[v]->data = list_add_last(e, t[v]->data);
      if (t[v]->data==NULL)
      {
        return 0;
      }
    }
  } 
  return (1); 
}

int hashtable_contains_key(keys_t k,hashtable_t t) 
{
  
}

int hashtable_get_value(keys_t k, value_t* pv, hashtable_t t) {
  //TODO completer

}

void hashtable_print(hashtable_t t) {
  //TODO completer

}
////////////////////////////////////////////////////////////////


// A faire dans un second temps :

int hashtable_delete_key(keys_t k, hashtable_t t) {
  //TODO completer

}

hashtable_t hashtable_delete(hashtable_t t) {
  //TODO completer

}

void hashtable_analyse(hashtable_t t) {
  //TODO completer
}

void hashtable_sort_print(hashtable_t tab) {
  int i;
  list_t l;
  l=list_new();

  for (i=0; i<tab.size; i++) {
    if (!list_is_empty(tab.data[i])) {
      l = list_concat(list_inverse_copy(tab.data[i]),l);
    }
  }
  // tri fusion de la liste temporaire
  l= list_sort_value(l);

  list_print(l);

  // Suppression de la liste temporaire
  list_delete(l);
}


