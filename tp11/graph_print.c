#include "graph_print.h"

	/* Affichage graphique d'une carte */
void card_draw(CARTE* e, SDL_PHWindow*  f1,int x, int y) {
  if (e->visible!=0) {
    if ((e->im).data!=NULL) SDL_PH_DrawIm32(f1,(e->im).data,(e->im).lig,(e->im).col,x,y);
    else  if ((e->dos).data!=NULL) SDL_PH_DrawIm32(f1,(e->dos).data,(e->im).lig,(e->im).col,x,y);
  }
  else {
    if ((e->dos).data!=NULL) SDL_PH_DrawIm32(f1,(e->dos).data,(e->im).lig,(e->im).col,x,y);
  }
}

	/* Efface une carte */
void card_erase(CARTE* e, SDL_PHWindow*  f1,int x, int y) { SDL_Rect r;
  r.x = x; r.y = y; r.h = e->im.lig; r.w = e->im.col;
  SDL_SetRenderDrawColor(f1->rendu,255,255,255,255);
  SDL_RenderFillRect(f1->rendu,&r);
}

	/* Affiche une pile */
void lifo_draw(lifo_t p, SDL_PHWindow*  f1, int x, int y) {
   lifo_draw_dec(p,f1,x,y,DECALAGE);
   SDL_PH_FlushWindow(f1);
}

	/* Efface une pile */
void lifo_erase(lifo_t p, SDL_PHWindow*  f1, int x, int y) {
   lifo_erase_dec(p,f1,x,y,DECALAGE); SDL_PH_FlushWindow(f1);
}

	/* Affiche une file implemente par une liste circulaire */
void fifo_draw(fifo_t L, SDL_PHWindow*  f1, int x, int y) {
  fifo_draw_dec(L,f1,x,y,DECALAGE); SDL_PH_FlushWindow(f1);
}

	/* Efface toute une file */
void fifo_erase(fifo_t L, SDL_PHWindow*  f1, int x, int y) {
  fifo_erase_dec(L,f1,x,y,DECALAGE); SDL_PH_FlushWindow(f1);
}

/* Les fonctions d'affichage avec un decalage entre chaque carte */
void lifo_draw_dec(lifo_t p, SDL_PHWindow*  f1, int x, int y, int decalage) {
   int j=lifo_length(p)-1;
   if (!lifo_is_empty(p)) {
     lifo_draw_dec(p->next,f1,x,y, decalage);
     card_draw(&p->val,f1,x,y-decalage*j);
   }
}

void lifo_erase_dec(lifo_t p, SDL_PHWindow*  f1, int x, int y, int decalage) { lifo_t c; int i;
  for (i=0,c=p; !lifo_is_empty(c); i++,c=c->next)
    card_erase(&c->val,f1,x,y-decalage*i);
}

void fifo_draw_dec(fifo_t L, SDL_PHWindow*  f1, int x, int y, int decalage) { fifo_t p;
  if (!fifo_is_empty(L)) { int i=0;
    p=L;
    do {
      p=p->next;
      card_draw(&p->val,f1,x,y-decalage*i++);
    } while (p!=L);
  }
}

void fifo_erase_dec(fifo_t L, SDL_PHWindow*  f1, int x, int y, int decalage) { fifo_t p;
  if (!fifo_is_empty(L)) { int i=0;
    p=L;
    do {
      p=p->next;
      card_erase(&p->val,f1,x,y-decalage*i++);
    } while (p!=L);
  }
}
