#include "distribution.h"

/* Version efficace de distribution : a chaque tour i, on echange dasn le tableau de marquage tab, la carte tiree et au hazard et la carte en position i
*/

CARTE take_one_card(char* tab, int nbcarterestant ) { CARTE c;
  int i,j, k;
  memset(&c,0,sizeof(c));
  j=nbcarterestant!=0 ? random()%nbcarterestant : 0;
  k=tab[j] ;
  i=tab[j]; tab[j]=tab[nbcarterestant-1]; tab[nbcarterestant-1]=i;
  c.rang=1+k/4; c.couleur=k%4; c.visible=0;

#ifdef MODEGRAPHIQUE
  char* cou[]={"trefle","carreau","coeur","pique"};
  char nom[256];
  sprintf(nom,"%s%s_%d.ppm",IMAGE_PATH,cou[c.couleur],c.rang-1);
  if ( (c.im.data=SDL_PH_ReadIm32(nom,&(c.im.lig),&(c.im.col)))==NULL) {
    printf("Erreur lecture fichier %s\n",nom);
    c.im.data=NULL;
    return c;
  }
  else {
    c.dos.data=SDL_PH_ReadIm32(IMAGE_PATH"dos.ppm",&(c.dos.lig),&(c.dos.col));
  }
#endif

  return c;
}


int distribution(fifo_t* aj1, fifo_t *aj2, int alea, int nbcarte) { int i, return_value=1;
  char* tab=calloc(nbcarte*4,1); /* Indique les cartes deja utilisees par un 1 */
  for(i=0; i<nbcarte*4; i++) tab[i]=i;
  srandom(alea);        /* initialisation du generateur aleatoire */
  CARTE c;
  for (i=0; i<nbcarte*4/2; i++) {
    *aj1=fifo_enqueue(c=take_one_card(tab,nbcarte*4-2*i),*aj1);
    if (c.im.data==NULL) return_value=0;
    *aj2=fifo_enqueue(c=take_one_card(tab,nbcarte*4-2*i-1),*aj2);
    if (c.im.data==NULL) return_value=0;
  }
  free(tab); tab=NULL;
  return return_value;
}



int melanger(fifo_t* aj, int alea, int nbcarte) { int i;
    char* tab=calloc(nbcarte*4,1); /* Indique les cartes deja utilisees par un 1 */
    for(i=0; i<nbcarte*4; i++) tab[i]=i;
    srandom(alea);        /* initialisation du generateur aleatoire */
    for (i=0; i<nbcarte*4; i++) {
        *aj=fifo_enqueue(take_one_card(tab,nbcarte*4-i-1),*aj);
    }
    free(tab); tab=NULL;
    return 1;
}
