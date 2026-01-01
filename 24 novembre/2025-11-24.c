/* --------------------------------------------------------------
   Suppression d'un élément dans une liste simplement chainée
-------------------------------------------------------------- */

int main() {
Element* supprimer (Element* debut, Element* x) /* début = pointeur sur le début de la liste, x = pointeur sur l'élément à oter de la liste */
{
  Element* precedent
  if (debut == x)
    return x->suivant;
  else {
    precedent = recherchePrecedent (debut, x);
    precedent->suivant = x->suivant;
    return debut;
    }
}

Element * recherchePrecedent (Element* debut, Element* x)
/* L'objet pointé par x appartient à la liste. */
/* L'objet point par x n'est pas le premier objet de la liste (ce cas est directement pris en compte dans la fonction "supprimer". */
{
  Element * precedent;
  precedent = debut;
  while (precedent->suivant != x)
    precedent = precedent->suivant;
  return precedent;
}
return 0;
}

/* --------------------------------------------------------------
   Déclaration de type d'un élément d'une liste doublement chainée
-------------------------------------------------------------- */

typedef struct Element2 Element2;
struct Element2
{
  int valeur;
  Element2 *precedent, *suivant;
};

/* --------------------------------------------------------------
   Insertion d'un élément dans une liste doublement chainée
-------------------------------------------------------------- */

int main() {
Element2 * listeInserer2 (Element2 * debut, Element2 * x)
{
  x->precedent = NULL;
  x->suivant = debut;
  if (debut != NULL)
    debut->precedent = x;
  return x;
}
return 0;
}

/* --------------------------------------------------------------
   Suppression d'un élément dans une liste doublement chainée
-------------------------------------------------------------- */

#include <stdlib.h>

int main() {
Element2 * listeSupprimer2 (Element2* debut, Element2 * x)
{
  if (x->suivant != NULL)	/* x n'est pas en fin de liste */
    x->suivant->precedent = x->precedent;
  if (debut == x)		/* x est en début de liste */
    return x->suivant;		/* On retourne le second élément */
  else
    {				/* x n'est pas en début de liste */
      x->precedent->suivant = x->suivant;
      return debut;
    }
}
return 0;
}

/* --------------------------------------------------------------
   Suppression d'un élément dans une liste doublement chaînée circulaire avec sentinelle
-------------------------------------------------------------- */

#include <stdlib.h>

int main() {
Element2 * listeSupprimer3 (Element2 * x)
{
  x->suivant->precedent = x->precedent;
  x->precedent->suivant = x->suivant;
}
return 0;
}

/* --------------------------------------------------------------
   Insertion d'un élément dans une liste doublement chaînée circulaire avec sentinelle
-------------------------------------------------------------- */

#include <stdlib.h>

int main() {
Element2 * listeInserer3 (Element2* debut, Element2 * x)
{
  x->suivant = debut->suivant;
  debut->suivant->precedent = x;
  debut->suivant = x;
  x->precedent = debut;
}
return 0;
}
