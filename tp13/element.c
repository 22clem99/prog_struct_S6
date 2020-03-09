#include "element.h"

void element_print (element_t e) {
  printf("%d ",e);
}

int element_equal(element_t* e1, element_t* e2) {
  return  ELEMENT_EQUAL(e1,e2);
}

int element_compare(element_t* e1, element_t* e2) {
   return ELEMENT_COMPARE(e1,e2);
 }
