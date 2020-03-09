#ifndef _ELEMENT
#define _ELEMENT
#include <string.h>

typedef char* keys_t;

typedef int value_t;

typedef struct {
  keys_t key;
  value_t value;
} element_t;


void element_print (element_t e);
void element_init (element_t* e);
element_t element_empty();
int element_is_empty(element_t e);
int element_equal(element_t*, element_t*);
element_t element_clone(element_t e);
element_t element_new(keys_t key, value_t value);
element_t element_delete(element_t e);

int key_equal(keys_t, keys_t);
int value_equal(value_t, value_t);
#endif
