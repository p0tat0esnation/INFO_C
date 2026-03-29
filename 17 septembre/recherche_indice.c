#include <stdio.h>

/* --------------- Recherche d'un élément dans un tableau */

void rechercheIndice(float tab[], int nbVal, float nb)
{
  int trouve = 0, i = 0;
  while ((!trouve) && (i < nbVal)) /* pas trouvé et pas dépassé la fin du tableau */
  {
    if (nb == tab[i++])
    {
      trouve = 1;
      nbVal = i - 1;
    }
  }
  if (trouve)
    printf("%5.2f est l'élément numéro %d\n", nb, nbVal + 1);
  else
    printf("%5.2f non trouvé \n", nb);
  return;
}

int main()
{
  float t[] = {1, 2, 3, 23.0, 5, 6};
  rechercheIndice(t, 6, 23.0);
  return 0;
}
