/* --------------------------------------------------------------
   Suppression d'un élément dans une liste doublement chaînée circulaire avec sentinelle
-------------------------------------------------------------- */

#include <stdlib.h>

typedef struct Element2
{
  struct Element2 *suivant;
  struct Element2 *precedent;
  // ajoutez d'autres champs si nécessaire
} Element2;

Element2 *listeSupprimer3(Element2 *x)
{
  if (x == NULL)
    return NULL;
  x->suivant->precedent = x->precedent;
  x->precedent->suivant = x->suivant;
  return x;
}

int main()
{
  // Exemple d'utilisation ici si besoin
  return 0;
}
