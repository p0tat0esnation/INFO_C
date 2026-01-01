/* ------------------------------------------------------------------------------------- */
/* Allocation standard d'espace mémoire */

#include <stdlib.h>

int main()
{

  int *memoireAllouee = NULL; // Création d'un pointeur sur un int

  memoireAllouee = malloc(sizeof(int));
  if (memoireAllouee == NULL) // L'allocation a échoué
    exit(0);                  /* Arrêt immédiat du programme */
  // sinon, on peut continuer le programme normalement
  return 0;
}
