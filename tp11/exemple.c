
#include "fifo.h"
#include "lifo.h"
#include "element.h"
#include "distribution.h"
#include "graph_print.h"

/* Dimension de la fenetre */
#define  DIMX 500
#define  DIMY 700

/* Posiiton en X du jeu du joueur 1 */
#define POS_X_FILE1 50
/* Posiiton en X de la pile de batailleu du joueur 1 */
#define POS_X_PILE1 150
/* Posiiton en X du jeu du joueur 2 */
#define POS_X_FILE2 350
/* Posiiton en X de la pile de batailleu du joueur 2 */
#define POS_X_PILE2 250
#define POS_Y (DIMY-120)


int  main(int argc, char** argv) {  CARTE c;
  fifo_t j1=fifo_new(),j2=fifo_new();
  lifo_t p1=lifo_new(),p2=lifo_new();
        // La variable pour manipuler une fenetre graphique
  SDL_PHWindow* f1=NULL;
        /* On cree une fenetre graphique */
  f1=SDL_PH_CreateWindow(DIMX,DIMY);
  if (f1==NULL) { puts("Impossible d'ouvrir une fenetre"); exit(EXIT_FAILURE); }

        /* On cree et melange toutes les cartes (ici 6*4), avec leur representation sous forme d'image dans la file jeu*/
   if (distribution(&j1,&j2,1,13)==0) {
     printf("Tous les fichiers images de cartes ne sont pas disponibles\n");
     exit(EXIT_FAILURE);
   }

        /* On affiche le jeu e du joueur 1*/
  fifo_draw(j1,f1,POS_X_FILE1,POS_Y);
        /* On affiche le jeu e du joueur 2*/
  fifo_draw(j2,f1,POS_X_FILE2,POS_Y);
       /* On affiche la pile du joueur 1*/
  lifo_draw(p1,f1,POS_X_PILE1,POS_Y);
        /* On affiche la pile du joueur 2*/
  lifo_draw(p2,f1,POS_X_PILE2,POS_Y);

	/* Juste pour ne pas  quitter tout de suite*/
  puts("Taper Return pour continuer");    getchar();
  puts("On prend une carte de chaque joueur");
  puts("On la met sur sa pile");

  /* On efface les piles et les files des joueurs */
  lifo_erase(p1,f1,POS_X_PILE1,POS_Y);
  lifo_erase(p2,f1,POS_X_PILE2,POS_Y);
  fifo_erase(j1,f1,POS_X_FILE1,POS_Y);
  fifo_erase(j2,f1,POS_X_FILE2,POS_Y);

  /* On remplit les  piles avec les premieres cartes face visible  de chaque joueur */
  c=fifo_dequeue(&j1); c.visible=1 ; p1=lifo_push(c,p1);
  c=fifo_dequeue(&j2); c.visible=1 ; p2=lifo_push(c,p2);

  /* On affiche les nouvelles piles et files des joueurs */
  lifo_draw(p1,f1,POS_X_PILE1,POS_Y);
  lifo_draw(p2,f1,POS_X_PILE2,POS_Y);
  fifo_draw(j1,f1,POS_X_FILE1,POS_Y);
  fifo_draw(j2,f1,POS_X_FILE2,POS_Y);
  /* On attend */
  puts("Taper Return pour continuer");    getchar();
  /* la file pointee par gagnant designe le joueur qui gnagne les 2 cartes */
  fifo_t* gagnant=NULL;
  if (lifo_peek(p1).rang > lifo_peek(p2).rang) {
    puts("le joueur 1 gagne les cartes");
    gagnant=&j1;
  }
  else if (lifo_peek(p1).rang < lifo_peek(p2).rang) {
    puts("le joueur 2 gagne les cartes");
    gagnant=&j2;
  }
  else {
    puts("bataille");
  }

  /* Gain des cartes par le gagnant s'il existe */
  if (gagnant) {
    /* On efface les piles et les files gagnees par un joueur  */
    lifo_erase(p1,f1,POS_X_PILE1,POS_Y);
    lifo_erase(p2,f1,POS_X_PILE2,POS_Y);
    /* On met les cartes des piles dans la file du gagnant
    On garde les cartes face visible pour montrer leurs
    destinations sur cet exemple */
    c=lifo_pop(&p1); c.visible=1; *gagnant=fifo_enqueue(c,*gagnant);
    c=lifo_pop(&p2); c.visible=1; *gagnant=fifo_enqueue(c,*gagnant);
    /* On affiche les nouvelles  files des joueurs  */
    fifo_draw(j1,f1,POS_X_FILE1,POS_Y);
    fifo_draw(j2,f1,POS_X_FILE2,POS_Y);
  }

  puts("Taper Return pour continuer");    getchar();

}
