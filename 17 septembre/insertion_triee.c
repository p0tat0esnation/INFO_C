#include <stdio.h>

/* -------------------- Insertion d'un nb dans un tableau trié JML */

int main()
{
  float tab_trie[10] = {8.5, 9.5, 12.5, 18};
  float element_a_inserer = 11.2;
  int i, nbnotes = 4;

  /* Boucle de décalage */
  i = nbnotes;
  while (i > 0 && element_a_inserer < tab_trie[i - 1])
  {
    tab_trie[i] = tab_trie[i--];
  }
  tab_trie[i] = element_a_inserer;
  nbnotes++;
  printf("L'élément %4.2f sera inséré en position %d\n", element_a_inserer, ++i);
  return 0;
}
