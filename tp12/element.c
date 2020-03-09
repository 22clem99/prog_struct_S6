#include "element.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void element_print (element_t e) {
  printf("%s : %d; ", e.key,e.value);
}

void element_init (element_t* e) {
  e->value=0; e->key=NULL;
}

element_t element_empty() {
  element_t e;
  element_init(&e);
  return e;
}

int element_is_empty(element_t e) {
  element_t vide=element_empty();
  return element_equal(&e,&vide);
}

int element_equal(element_t* e1, element_t* e2) {
  return key_equal(e1->key,e2->key) && value_equal(e1->value,e1->value);
}

int value_equal(value_t v1, value_t v2) {
  return v1==v2;
}

int key_equal(keys_t k1, keys_t k2) {
  return strcasecmp(k1,k2)==0;
}

element_t element_clone(element_t e) {
  element_t clone;
  clone.value=e.value;
  clone.key = strdup(e.key);
  return clone;
}

element_t element_new(keys_t key, value_t value) {
  element_t e;
  e.key=strdup(key);
  e.value=value;
  return e;
}

element_t element_delete(element_t e) {
  if (e.key) free(e.key);
  e.key=NULL;
  e.key=0;
  return e;
}
