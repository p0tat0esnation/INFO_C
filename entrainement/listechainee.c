#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

int compterElements(Element *debut);

int compterElements(Element *debut)
{
    int cpt = 0;
    while (debut != NULL)
    {
        cpt++;
        debut = debut->suivant;
    }
    return cpt;
}

int modifiervaleur(Element *debut, int cible, int nouveau);

int modifiervaleur(Element *debut, int cible, int nouveau)
{
    int cpt = 0;
    while (debut != NULL)
    {
        if (debut->nombre == cible)
        {
            debut->nombre = nouveau;
            cpt++;
        }
        debut = debut->suivant;
    }
    return cpt;
}

Element *ajouterenfin(Element *debut, int valeur);

Element *ajouterenfin(Element *debut, int valeur)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = valeur;
    nouveau->suivant = NULL;

    if (debut == NULL)
    {
        return nouveau;
    }

    Element *actuel = debut;
    while (actuel->suivant != NULL)
    {
        actuel = actuel->suivant;
    }
    actuel->suivant = nouveau;

    return debut;
}

Element *inverserListe(Element *debut)
{
    Element *precedent = NULL;
    Element *actuel = debut;
    Element *prochain = NULL;
    while (actuel != NULL)
    {
        prochain = actuel->suivant;
        actuel->suivant = precedent;
        precedent = actuel;
    }
    return precedent;
}
