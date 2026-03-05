#include <stdio.h>

/* ------------------------------------------------------------------------------------- */
/* Recherche d'un élément dans une liste simplement chainée */

typedef struct Element
{
  int nombre;
  struct Element *suivant;
} Element;

Element *rechercher(Element *debut, int val)
{
  if ((debut == NULL) || (val == debut->nombre))
    return debut;
  return rechercher(debut->suivant, val);
}

int main()
{
  // Exemple d'utilisation possible ici
  return 0;
}

typedef struct Element2
{
  int nombre;
  struct Element *suivant;
  struct Element *precedent;
} Element2;