/* ------------------------------------------------------------------------------------- */
/* Création d'un Tableau dynamique : avec allocation dynamique de mémoire */
#include <stdlib.h>

int main()
{
  /* Déclaration d'une matrice (tableau à deux dimensions) statique permettant de stocker jusqu'à 100 fois 10 entiers */
  int tab[100][10];

  /* Pour stocker N fois 10 entiers */
  int N = 35;
  int **tableau;
  tableau = malloc(N * 10 * sizeof(int)); // On alloue de la mémoire pour créer le tableau
  if (tableau == NULL)                    // On vérifie si l'allocation a marché ou non
  {
    exit(0); // On arrête tout
  }
  return 0;
}
