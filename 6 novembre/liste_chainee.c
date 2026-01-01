/* ------------------------------------------------------------------------------------- */
/* Création / construction /initialisation d'une liste simplement chaînée */

#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
  int nombre;
  Element *suivant;
};

Element *creationListe(int nb) /* Itératif */
{
  Element *resteListe = NULL;
  do
  {
    Element *nouveau = malloc(sizeof(*nouveau)); /* pas besoin de déclarer dans la boucle: à corriger */
    if (nouveau == NULL)
      exit(EXIT_FAILURE);
    nouveau->nombre = nb;
    nouveau->suivant = resteListe;
    resteListe = nouveau;
    nb--;
  } while (nb > 0);
  return resteListe;
}

Element *insertion(Element *debut, int nouveauNb) /* Insertion en début de liste */
{
  /* Création d'un nouvel élément */
  Element *nouveau = malloc(sizeof(*nouveau));
  if (debut == NULL || nouveau == NULL)
    exit(EXIT_FAILURE);
  nouveau->nombre = nouveauNb;
  nouveau->suivant = debut;
  return nouveau;
}

int main(void)
{
  Element *debut = creationListe(10);
  debut = insertion(debut, 11);
  while (debut != NULL)
  {
    printf("%d   ", debut->nombre);
    debut = debut->suivant;
  }
  printf("\n");
}
