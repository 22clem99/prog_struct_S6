#include "heap.h"
#include "heapsort.h"


int main() {
  element_t x=1;
  heap_t tas;
  tas=heap_new(100);

  x=80; printf("Ajout de "); element_print(x);
  heap_add(x,&tas);
  printf("Nouveau tas : ");  heap_print(tas);
  puts("---------------");

  x=100; printf("Ajout de "); element_print(x);
  heap_add(x,&tas);
  printf("Nouveau tas : ");  heap_print(tas);
  puts("---------------");

  x=90; printf("Ajout de "); element_print(x);
  heap_add(x,&tas);
  printf("Nouveau tas : ");  heap_print(tas);
  puts("---------------");

  x=40; printf("Ajout de "); element_print(x);
  heap_add(x,&tas);
  printf("Nouveau tas : ");  heap_print(tas);
  puts("---------------");

  x=10; printf("Ajout de "); element_print(x);
  heap_add(x,&tas);
  printf("Nouveau tas : ");  heap_print(tas);
  puts("---------------");

  x=30; printf("Ajout de "); element_print(x);
  heap_add(x,&tas);
  printf("Nouveau tas : ");  heap_print(tas);
  puts("---------------");

  x=160; printf("Ajout de "); element_print(x);
  heap_add(x,&tas);
  printf("Nouveau tas : ");  heap_print(tas);
  puts("---------------");

  x=140; printf("Ajout de "); element_print(x);
  heap_add(x,&tas);
  printf("Nouveau tas : ");  heap_print(tas);
  puts("---------------");

  x=70; printf("Ajout de "); element_print(x);
  heap_add(x,&tas);
  printf("Nouveau tas : ");  heap_print(tas);
  puts("---------------");

  x=20; printf("Ajout de "); element_print(x);
  heap_add(x,&tas);
  printf("Nouveau tas : ");  heap_print(tas);
  puts("---------------");
  return EXIT_SUCCESS;
}
