#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct Joueur Joueur;
struct Joueur
{
    char *nom;
    int score;
    int nombre_cartes;
    Joueur *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Joueur *premier;
};

Liste *initialisation()
{
    Joueur *joueur1 = malloc(sizeof(*joueur1));
    Liste *liste = malloc(sizeof(*liste));

    joueur1->nom = "";
    joueur1->score = 0;
    joueur1->nombre_cartes = 0;
    joueur1->suivant = NULL;

    liste->premier = joueur1;

    return liste;
}

void ajouter_un_joueur_en_premier(Liste *liste, char *nom, int score, int nombre_cartes)
{
    Joueur *joueur_nouveau = malloc(sizeof(*joueur_nouveau));
    joueur_nouveau->nom = nom;
    joueur_nouveau->score = score;
    joueur_nouveau->nombre_cartes = nombre_cartes;
    joueur_nouveau->suivant = liste->premier;
    liste->premier = joueur_nouveau;
}

void afficher_liste(Liste liste)
{
    Joueur *actuel = liste.premier;
    while (actuel != NULL)
    {
        printf("Nom: %s\n", actuel->nom);
        actuel = actuel->suivant;
    }
}

void main()
{
    Liste *maliste = initialisation();
    ajouter_un_joueur_en_premier(maliste, "Thomas", 0, 5);
    afficher_liste(*maliste);
}