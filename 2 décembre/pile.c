/* ------------------------- */
/* Déclaration d'un élément d'une pile */
/* includes nécessaires */
#include <stdlib.h>
#include <stdio.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

/* Déclaration d'une pile */

typedef struct Pile Pile;
struct Pile
{
    Element *premier;
};

/* ------------------------- */
/* Initialisation d'une pile */
/* ------------------------- */

Pile *initialiser()
{
    Pile *pile = malloc(sizeof(*pile));
    pile->premier = NULL;
    return pile;
}

/* ------------------------- */
/* Prédicat pileVide() */
/* ------------------------- */

#include <stdbool.h>
bool pileVide(Pile *pile)
{
    return (pile->premier == NULL);
}

/* ------------------------- */
/* empiler() */
/* ------------------------- */
void empiler(Pile *pile, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

/* ------------------------- */
/* Prédicat dépiler() */
/* ------------------------- */

#include <stdbool.h>
int depiler(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDepile = 0;
    Element *elementDepile = pile->premier;

    if (!pileVide(pile))
    {
        nombreDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return nombreDepile;
}

/* ------------------------- */
/* Prédicat afficherPile() */
/* ------------------------- */

void afficherPile(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
    }

    printf("\n");
}

int main()
{
    Pile *maPile = initialiser();

    empiler(maPile, 4);
    empiler(maPile, 8);
    empiler(maPile, 15);
    empiler(maPile, 16);
    empiler(maPile, 23);
    empiler(maPile, 42);

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    printf("Je depile %d\n", depiler(maPile));
    printf("Je depile %d\n", depiler(maPile));

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    return 0;
}
