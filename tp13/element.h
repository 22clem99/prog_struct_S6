#ifndef _ELEMENT
#define _ELEMENT
#include <stdio.h>
#include <stdlib.h>

typedef int element_t;
#define ELEMENT_COMPARE(e1,e2)  (*(e1)>*(e2) ? 1 : *(e1)==*(e2) ? 0 : -1)
#define ELEMENT_EQUAL(e1,e2)  (*(e1)==*(e2))

void element_print (element_t e);
element_t element_empty();
int element_is_empty(element_t e);
int element_equal(element_t*, element_t*);
int element_compare(element_t*, element_t*);

#endif
