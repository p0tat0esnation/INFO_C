#include <stdio.h>

void rechercheIndice(int tab[], int nbVal, double nb)
{
  int trouve = 0, i = 0;
  while ((!trouve) && (i < nbVal))
  {
    if (nb == tab[i++])
    {
      trouve = 1;
      nbVal = i - 1;
    }
  }
  if (trouve)
    printf("%5.2f est la note numéro %d\n", nb, nbVal + 1);
  else
    printf("%5.2f non trouvé \n", nb);
  return;
}

int main()
{
  int t[] = {1, 2, 3, 4, 5, 6};
  rechercheIndice(t, 6, 23.0);
  return 0;
}
