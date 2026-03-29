#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Joueur Joueur;
struct Joueur
{
    char nom[24];
    int score;
    int nombre_cartes;
    Joueur *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Joueur *premier;
};

static void copier_nom(char destination[24], const char *source)
{
    if (source == NULL)
    {
        source = "";
    }

    strncpy(destination, source, 23);
    destination[23] = '\0';
}

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));

    if (liste == NULL)
    {
        return NULL;
    }

    liste->premier = NULL;

    return liste;
}

void ajouter_un_joueur_en_premier(Liste *liste, const char *nom, int score, int nombre_cartes)
{
    if (liste == NULL)
    {
        return;
    }

    Joueur *joueur_nouveau = malloc(sizeof(*joueur_nouveau));

    if (joueur_nouveau == NULL)
    {
        return;
    }

    copier_nom(joueur_nouveau->nom, nom);
    joueur_nouveau->score = score;
    joueur_nouveau->nombre_cartes = nombre_cartes;
    joueur_nouveau->suivant = liste->premier;
    liste->premier = joueur_nouveau;
}

void afficher_liste(const Liste *liste)
{
    if (liste == NULL)
    {
        return;
    }

    Joueur *actuel = liste->premier;
    while (actuel != NULL)
    {
        printf("Nom: %s | Score: %d | Cartes: %d\n",
               actuel->nom,
               actuel->score,
               actuel->nombre_cartes);
        actuel = actuel->suivant;
    }
}

void liberer_liste(Liste *liste)
{
    if (liste == NULL)
    {
        return;
    }

    Joueur *actuel = liste->premier;
    while (actuel != NULL)
    {
        Joueur *suivant = actuel->suivant;
        free(actuel);
        actuel = suivant;
    }

    free(liste);
}

int main(void)
{
    Liste *liste = initialisation();

    if (liste == NULL)
    {
        fprintf(stderr, "Erreur: impossible d'initialiser la liste.\n");
        return 1;
    }

    ajouter_un_joueur_en_premier(liste, "Alice", 10, 3);
    ajouter_un_joueur_en_premier(liste, "Bob", 15, 5);
    ajouter_un_joueur_en_premier(liste, "Charlie", 7, 2);

    afficher_liste(liste);
    liberer_liste(liste);

    return 0;
}
