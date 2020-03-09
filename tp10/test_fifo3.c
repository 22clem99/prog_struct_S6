#include <stdio.h>
#include "fifo.h"
#include "distribution.h"


int main() {  fifo_t jeu1, jeu2;
  int alea, nbparcoul;
  jeu1=fifo_new();
  jeu2=fifo_new();
  do {
    printf("Combien de carte par couleur dans le jeu : 1..13"); fflush(stdout); scanf("%d",&nbparcoul);
  } while (nbparcoul<=0 || nbparcoul>13);
  do {
    printf("Entrer un nombre quelconque superieur a 1 (graine du generateur aleatoire)"); fflush(stdout); scanf("%d",&alea);
  } while(alea<=0);
  if (distribution(&jeu1,&jeu2,alea,nbparcoul) !=1) printf("Erreur dans la distribution\n");
  else {
    puts("jeu du premier joueur"); fifo_print(jeu1);
    puts("jeu du deuxieme joueur"); fifo_print(jeu2);
  }
  jeu1=fifo_delete(jeu1);
  jeu2=fifo_delete(jeu2);
}
