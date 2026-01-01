/* --------------------------------------------------------------
   Suppression d'un élément dans une liste doublement chainée
-------------------------------------------------------------- */

#include <stdlib.h>

typedef struct Element2 {
    struct Element2* precedent;
    struct Element2* suivant;
    int valeur; // exemple de champ, à adapter selon vos besoins
} Element2;

Element2* listeSupprimer2(Element2* debut, Element2* x)
{
  if (x->suivant != NULL) 	/* x n'est pas en fin de liste */
    x->suivant->precedent = x->precedent;
  if (debut == x) 		/* x est en début de liste */
    return x->suivant; 		/* On retourne le second élément */
  else
    { 				/* x n'est pas en début de liste */
      x->precedent->suivant = x->suivant;
      return debut;
    }
}

int main() {
    // Exemple d'utilisation possible ici
    return 0;
}
