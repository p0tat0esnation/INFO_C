#include <stdio.h>






int triple(int nombre)
{
    return 3 * nombre;
}   
 
int main()
{
    int nombreInitial = 12;
    printf("Le triple de ce nombre est %d\n", triple(nombreInitial));
    return 0;
}

#include <stdio.h>






int main() {
float puissance (float nb, int exposant)
  {
    float resultat = 1;
    int compteur = 0;
    while (compteur < exposant)
      {
	compteur++;
	resultat = resultat*nb;
      }
    return resultat;
  }
float x=2.5;
int m=5;
printf ("%5.2f puissance %d = %10.3f\n", x, m, puissance(x,m));
return 0;
}

#include <stdio.h>






int main() {
float puissanceRec (float x, int N)
  {
    float resultat;
    if (N == 0)
      resultat = 1;
    else
      resultat = x * puissanceRec (x, N-1);
    return resultat;
  }

float x=2;
int m=3;

printf ("%5.2f puissance %d = %10.3f\n", x, m, puissanceRec(x,m));
return 0;
}

#include <stdio.h>






int main() {
int factorielle(int nb)
  {
    int resultat;
    if (nb < 0)
      resultat = 0;
    else if ((nb == 1) || (nb == 0))
       resultat = 1;
    else
      resultat = nb * factorielle(nb-1);
    return resultat;
  }

int n=4;
printf ("%d! = %d\n", n, factorielle(n));
return 0;
}

#include <stdio.h>






int main() {
void conversion10versB (int nb, int base)
  {
    int quotient=1, reste;
    while (quotient != 0)
      {
	quotient = nb / base;
	reste = nb % base;
	nb = quotient;
	printf ("%d\n", reste);
      }
  }

int nb=2500;
conversion10versB(nb,8);
return 0;
}

#include <stdio.h>






int main() {
void rechercheIndice (int tab[], int nbVal, double nb)
{
  int trouve=0, i=0;
  while ((! trouve) && (i < nbVal))
    {
      if (nb == tab[i++])
	{
	  trouve = 1;
	  nbVal = i-1;
	    }
    }
  if (trouve)
    printf ("%5.2f est la note numéro %d\n", nb, nbVal+1);
  else
    printf ("%5.2f non trouvé \n", nb);
  return;
}

int t[] = {1, 2, 3, 4, 5, 6};
rechercheIndice (t, 6, 23.0);
return 0;
}

#include <stdio.h>






int main() {
/* Insertion d'un nb dans un tableau trié JML p.66-68 */
float tab_notes[10] = {8.5, 9.5, 12.5, 18};
float note_a_inserer=11.2;
int i, nbnotes=4;

/* Boucle de décalage */
i=nbnotes;
while (i>0 && note_a_inserer<tab_notes[i-1])
  {
    tab_notes[i] = tab_notes[i--];
  }
tab_notes[i] = note_a_inserer;
nbnotes++;
printf("numcase %d nbnotes %d\n", i, nbnotes);
return 0;
}

#include <stdio.h>






int main() {
int insertion(float tab[10], int nb_element, int val)
  {
    printf("numcase %d nbnotes %f\n", 0, tab[0]);
  }
insertion(note_a_inserer, 4, 0);
return 0;
}
