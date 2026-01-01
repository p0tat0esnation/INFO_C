/* ------------------------ Tours de Hanoï ------------------- */
#include <stdio.h>

int main() {
int deplacer (int nb_disques, int depart, int arrivee, int intermediaire)
  {
    static int coup = 0;
    if (nb_disques == 1) 	/* Déplacement d'un seul disque */
      printf("%4d     %d -> %d\n",++coup,depart,arrivee);
    else			/* Déplacement d'une pile de disques */
      {
	deplacer(nb_disques - 1,depart,intermediaire,arrivee);
	deplacer(1,depart,arrivee,intermediaire);
	deplacer(nb_disques - 1,intermediaire,arrivee,depart);
	}
  }

int nbd=3;
deplacer(nbd, 1, 3, 2);
return 0;
}

/* --------------- Recherche d'un élément dans un tableau */

#include <stdio.h>

int main() {
void rechercheIndice (float tab[], int nbVal, float nb)
{
  int trouve=0, i=0;
  while ((! trouve) && (i < nbVal)) /* pas trouvé et pas dépassé la fin du tableau */
    {
      if (nb == tab[i++])
	{
	  trouve = 1;
	  nbVal = i-1;
	    }
    }
  if (trouve)
    printf ("%5.2f est l'élément numéro %d\n", nb, nbVal+1);
  else
    printf ("%5.2f non trouvé \n", nb);
  return;
}

float t[] = {1, 2, 3, 23.0, 5, 6};
rechercheIndice (t, 6, 23.0);
return 0;
}

/* -------------------- Insertion d'un nb dans un tableau trié JML */

#include <stdio.h>

int main() {
float tab_trie[10] = {8.5, 9.5, 12.5, 18};
float element_a_inserer=11.2;
int i, nbnotes=4;

/* Boucle de décalage */
i=nbnotes;
while (i>0 && element_a_inserer<tab_trie[i-1])
  {
    tab_trie[i] = tab_trie[i--];
  }
tab_trie[i] = element_a_inserer;
nbnotes++;
printf("L'élément %4.2f sera inséré en position %d\n", element_a_inserer, ++i);
return 0;
}
