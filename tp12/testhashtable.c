#include "tadhash.h"
#include <ctype.h>
#include <string.h>
#include "divers.h"
#include <time.h>

int main(int a, char **b)
{ hashtable_t  histo;
  int n;
  value_t valeur;
  char* mot;


  printf("Taille de la table ? \n"); scanf("%d",&n);
  histo=hashtable_new(n);

  // Ajout du couple "Phelma",1
  puts("Ajout du couple \"Phelma\",1");
  hashtable_put("Phelma",1,histo);
  printf("Table \n");
  hashtable_print(histo);
  puts("---------------");

  // Ajout du couple "une",3
  puts("Ajout du couple \"une\",3");
  hashtable_put("une",2,histo);
  printf("Table \n");
  hashtable_print(histo);
  puts("---------------");

  // Ajout du couple "ecole",2
  puts("Ajout du couple \"ecole\",2");
  hashtable_put("ecole",2,histo);
  printf("Table \n");
  hashtable_print(histo);
  puts("---------------");

  // Ajout du couple "ingénieurs",7
  puts("Ajout du couple \"ingénieurs\",7");
  hashtable_put("ingénieurs",7,histo);
  printf("Table \n");
  hashtable_print(histo);
  puts("---------------");

  // Recherche de la cle "ecole"
  mot="ecole";
  printf("Recherche du mot %s\n",mot);
  if (hashtable_contains_key(mot,histo))
     printf ("%s est dnas la table\n",mot);
  else
  printf ("%s n'est pas dans la table\n",mot);
  puts("---------------");

  // Recherche de la cle "ensimag"
  mot="ensimag";
  printf("Recherche du mot %s\n",mot);
  if (hashtable_contains_key(mot,histo))
     printf ("%s est dnas la table\n",mot);
  else
  printf ("%s n'est pas dans la table\n",mot);
  puts("---------------");

  // Affichage du mot et de la valeur
  mot="ingénieurs";
  printf("Affichage de la valeur associee au mot %s\n",mot);
  if (hashtable_get_value(mot,&valeur,histo)) {
    printf("%s a pour valeur : %d \n",mot, valeur);
  }
  puts("---------------");

  // Affichage du mot et de la valeur
  mot="pagora";
  printf("Affichage de la valeur associee au mot %s\n",mot);
  if (hashtable_get_value(mot,&valeur,histo)) {
    printf("%s a pour valeur : %d \n",mot, valeur);
  }
  puts("---------------");

  // Suppression; A commenter dans un premier temps.

  // Suppresion de l'element de cle  "ingénieurs"
  printf("Affichage de la valeur associee au mot %s\n","ingénieurs");
  hashtable_delete_key("ingénieurs",histo);
  printf("Table \n");
  hashtable_print(histo);
  puts("---------------");

  // Suppresion de l'element de cle  "phelma"
  printf("Affichage de la valeur associee au mot %s\n","phelma");
  hashtable_delete_key("phelma",histo);
  printf("Table \n");
  hashtable_print(histo);
  puts("---------------");

  // Suppresion de l'element de cle  "ense3"
  printf("Affichage de la valeur associee au mot %s\n","ense3");
  hashtable_delete_key("ense3",histo);
  printf("Table \n");
  hashtable_print(histo);
  puts("---------------");


  // Liberation memoire; A commenter dans un premier temps.
  hashtable_delete(histo);
}
