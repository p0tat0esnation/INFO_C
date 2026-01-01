/* --------------------------------------------------------------
   Suppression d'un élément dans une liste simplement chainée
-------------------------------------------------------------- */

#include <stdlib.h>

typedef struct Element {
    int valeur;
    struct Element* suivant;
} Element;

Element* recherchePrecedent(Element* debut, Element* x);

/* début = pointeur sur le début de la liste, x = pointeur sur l'élément à oter de la liste */
Element* supprimer(Element* debut, Element* x)
{
    Element* precedent;
    if (debut == x)
        return x->suivant;
    else {
        precedent = recherchePrecedent(debut, x);
        precedent->suivant = x->suivant;
        return debut;
    }
}

/* L'objet pointé par x appartient à la liste. */
/* L'objet pointé par x n'est pas le premier objet de la liste (ce cas est directement pris en compte dans la fonction "supprimer". */
Element* recherchePrecedent(Element* debut, Element* x)
{
    Element* precedent;
    precedent = debut;
    while (precedent->suivant != x)
        precedent = precedent->suivant;
    return precedent;
}

int main() {
    return 0;
}
