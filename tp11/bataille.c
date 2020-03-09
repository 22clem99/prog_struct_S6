
#include "fifo.h"
#include "lifo.h"
#include "distribution.h"
#include <stdlib.h>
#include <stdio.h>


int main (void)
{
    fifo_t jeu_1 = fifo_new(), jeu_2 = fifo_new();
    lifo_t bataille_1 = lifo_new(), bataille_2 = lifo_new();

    int graine, nb_carte;



    printf("~~~~~~~~~~~~~~Bienvenue dans la simulation d'une bataille~~~~~~~~~~~~~~");
    do
    {
        printf("\n - choisir le nombre de carte dans le jeu [1,13]:");
        scanf("%d", &nb_carte);
        printf("\n - choisir la graine de génération de nombre aléatoire :");
        scanf("%d", &graine);
    }while((graine <= 0)||(nb_carte<=0)||(nb_carte > 13));
    
    distribution(jeu_1, jeu_2, graine, nb_carte);

    do
    {
        add_carte_bataille_1 (&bataille_1, jeu_1, 1);
        add_carte_bataille_2 (&bataille_2, jeu_2, 1);

        do
        {
            
        } while (lifo_peek(bataille_1)==lifo_peek(bataille_2));
        
    } while (!fifo_is_empty(jeu_1) && !fifo_is_empty(jeu_2));
}


void add_carte_bataille (lifo_t *bataille, fifo_t jeu, int vis)
{
    CARTE tmp;

    tmp = fifo_dequeue(jeu);
    tmp.visible = vis;
    *bataille = lifo_push(tmp , *bataille);
}

