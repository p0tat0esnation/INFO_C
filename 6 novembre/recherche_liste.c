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
  // Création d'une liste chaînée d'exemple : 1 -> 2 -> 3
  Element e3 = {3, NULL};
  Element e2 = {2, &e3};
  Element e1 = {1, &e2};
  Element *trouve = rechercher(&e1, 2);

  if (trouve != NULL)
    printf("Valeur %d trouvée dans la liste.\n", trouve->nombre);
  else
    printf("Valeur non trouvée dans la liste.\n");

  return 0;
}

typedef struct Element2
{
  int nombre;
  struct Element *suivant;
  struct Element *precedent;
} Element2;