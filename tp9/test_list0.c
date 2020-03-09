#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() { CARTE c; list_t l1=NULL,l2=NULL, p=NULL;
    l1=list_new(); l2=list_new();
    printf("----------------------------------------------\n");
    printf("test de l'ajout en tete d'une carte et de l'affichage\n");
    printf("----------------------------------------------\n");
    printf("Nombre de cartes : %d\n",list_length(l1));
    printf("-------------------------------\n");
    printf("Ajout en tete de l'as de coeur\n");
    c.rang=1; c.couleur=COEUR; l1=list_add_first(c,l1);
    printf("Liste l1 : ");    list_print(l1);
    printf("Nombre de cartes : %d\n",list_length(l1));
    printf("-------------------------------\n");
    printf("Ajout en tete du roi de coeur\n");
    c.rang=13;    c.couleur=COEUR;  l1=list_add_first(c,l1);
    printf("Liste l1 : ");    list_print(l1);
    printf("Nombre de cartes : %d\n",list_length(l1));
    printf("-------------------------------\n");
    printf("Ajout en tete de l'as de pique\n");
    c.rang=1;    c.couleur=PIQUE;  l1=list_add_first(c,l1);
    printf("Liste l1 : ");    list_print(l1);
    printf("Nombre de cartes : %d\n",list_length(l1));
    printf("-------------------------------\n");
    printf("Ajout en tete du roi de pique\n");
    c.rang=13;    c.couleur=PIQUE; l1=list_add_first(c,l1);
    printf("Liste l1 : ");    list_print(l1);
    printf("Nombre de cartes : %d\n",list_length(l1));
    printf("-------------------------------\n");
    printf("Ajout en tete de l'as de pique\n");
    c.rang=1;    c.couleur=PIQUE; l1=list_add_first(c,l1);
    printf("Liste l1 : ");    list_print(l1);
    printf("Nombre de cartes : %d\n",list_length(l1));

    printf("\n----------------------------------------------\n");
    printf("Test du nombre de carte donnee dans une liste \n");
    printf("----------------------------------------------\n");
    printf("Test du nombre d'as de pique \n");
    printf("-------------------------------\n");
    c.rang=1;    c.couleur=PIQUE;
    int nb;
    nb=list_count(c,l1);
    printf("Nombre de "); element_print(c);
    printf("\ndans la liste : "); list_print(l1);
    printf("La carte est presente %d fois\n",nb);

    printf("-------------------------------\n");
    printf("Test du nombre de 10 de pique carte\n");
    c.rang=10;    c.couleur=PIQUE;
    nb=list_count(c,l1);
    printf("Nombre de "); element_print(c);
    printf("\ndans la liste : "); list_print(l1);
    printf("La carte est presente %d fois\n",nb);

    l2=list_new();
    printf("\n----------------------------------------------\n");
    printf("Nouvelle Liste : test de l'ajout en queue d'une carte \n");
    printf("----------------------------------------------\n");
    printf("Ajout en queue de l'as de coeur\n");
    c.rang=1;    c.couleur=COEUR;   l2=list_add_last(c,l2);
    printf("Liste l2 : ");    list_print(l2);
    printf("-------------------------------\n");
    printf("Ajout en queue du roi de coeur\n");
    c.rang=13;    c.couleur=COEUR;   l2=list_add_last(c,l2);
    printf("Liste l2 : ");    list_print(l2);
    printf("-------------------------------\n");
    printf("Ajout en queue de l'as de pique\n");
    c.rang=1;    c.couleur=PIQUE;   l2=list_add_last(c,l2);
    printf("Liste l2 : ");    list_print(l2);
    printf("-------------------------------\n");
    printf("Ajout en queue du roi de pique\n");
    c.rang=13;    c.couleur=PIQUE;   l2=list_add_last(c,l2);
    printf("Liste l2 : ");    list_print(l2);


    printf("\n----------------------------------------------\n");
    printf("test de la suppression en tete d'une carte \n");
    printf("----------------------------------------------\n");
    printf("Suppression en tete\n");
    if (!list_is_empty(l1)) l1=list_del_first(l1);
    printf("Liste l1 : ");    list_print(l1);
    printf("-------------------------------\n");
    printf("Suppression en tete\n");
    if (!list_is_empty(l1)) l1=list_del_first(l1);
    printf("Liste l1 : ");    list_print(l1);
    printf("-------------------------------\n");
    printf("Suppression en tete\n");
    if (!list_is_empty(l1)) l1=list_del_first(l1);
    printf("Liste l1 : ");    list_print(l1);
    printf("-------------------------------\n");
    printf("Suppression en tete\n");
    if (!list_is_empty(l1)) l1=list_del_first(l1);
    printf("Liste l1 : ");    list_print(l1);
    printf("-------------------------------\n");
    printf("Suppression en tete\n");
    if (!list_is_empty(l1)) l1=list_del_first(l1);
    printf("Liste l1 : ");    list_print(l1);

    printf("\n----------------------------------------------\n");
    printf("Liberation de toutes les listes\n");
    printf("----------------------------------------------\n");
    l1=list_delete(l1);     l2=list_delete(l2);

    printf("\n----------------------------------------------\n");
    printf("Test de la presence d'une carte dans une liste vide\n");
    printf("----------------------------------------------\n");
    c.rang=10;    c.couleur=PIQUE;
    p=list_find(c,l1);
    printf("Recherche de "); element_print(c);
    printf("\ndans la liste l1 : "); list_print(l1);
    if (p==NULL) printf("La carte n'est pas presente\n");
    else {printf("La carte est presente, c'est une erreur\n"); exit(EXIT_FAILURE);}

    exit(EXIT_SUCCESS);
}
