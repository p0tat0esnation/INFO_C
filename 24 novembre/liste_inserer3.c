/* --------------------------------------------------------------
   Insertion d'un élément dans une liste doublement chaînée circulaire avec sentinelle
-------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>

typedef struct Element2 {
    struct Element2 *suivant;
    struct Element2 *precedent;
    int valeur; // exemple de champ de données
} Element2;

Element2 * listeInserer3 (Element2* debut, Element2 * x)
{
    x->suivant = debut->suivant;
    debut->suivant->precedent = x;
    debut->suivant = x;
    x->precedent = debut;
    return debut;
}

int main() {
    // Exemple d'utilisation ici si besoin
    return 0;
}
