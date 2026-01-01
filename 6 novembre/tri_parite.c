/* Tri de nombres selon leur parité*/
/* Une solution pour le CC du 23 septembre 2025 */

#include <stdio.h>

int pair(int nb) /* Teste si un nb est pair (retourne Vrai) ou impair (retourne Faux) */
{
  return 1 - nb % 2;
}

void echanger(int t[], int i, int j)
{
  int temp = t[i];
  t[i] = t[j];
  t[j] = temp;
}

void repartition(int tab[], int nbVal)
{
  int i = 0, j = nbVal - 1;
  while (i < j)
  {
    while ((i < j) && pair(tab[i]))
      i++; /* Recherche du premier élément impair */
    while ((i < j) && !pair(tab[j]))
      j--; /* Recherche du dernier élément pair */
    if (i < j)
      echanger(tab, i++, j--); /*  Échanger les deux valeurs trouvées */
  }
}

void afficher(int t[], int nb)
{
  printf("[");
  for (int i = 0; i < nb; i++)
  {
    printf(" %d", t[i]);
  }
  printf(" ]\n");
}

int main()
{
  /* int a=3; */
  /* printf("La parité du nombre %d est %d\n",a,pair(a)); */
  int t[] = {0, 2, 3, 23, 5, 6};
  repartition(t, 6);
  afficher(t, 6);
  return 0;
}
