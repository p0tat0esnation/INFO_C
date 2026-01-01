/* Tri de nombres selon leur parité*/
/* Une solution pour le CC du 23 septembre 2025 */

#include <stdio.h>

int main() {
int pair(int nb)		/* Teste si un nb est pair (retourne Vrai) ou impair (retourne Faux) */
  {
    return 1 - nb%2;
  }

void echanger (int t[], int i, int j)
  {
    int temp = t[i];
    t[i] = t[j];
    t[j] = temp;
  }

void repartition(int tab[], int nbVal)
  {
    int i=0, j=nbVal-1;
    while (i < j)
      {
	while ((i<j) && pair(tab[i])) i++; /* Recherche du premier élément impair */
	while ((i<j) && !pair(tab[j])) j--;  /* Recherche du dernier élément pair */
	if (i<j) echanger(tab,i++,j--);    /*  Échanger les deux valeurs trouvées */
      }
  }

void afficher (int t[], int nb)
  {
    printf ("[");
    for (int i=0; i<nb; i++)
      {
	printf (" %d",t[i]);
      }
    printf (" ]\n");
  }

/* int a=3; */
/* printf("La parité du nombre %d est %d\n",a,pair(a)); */
int t[] = {0, 2, 3, 23, 5, 6};
repartition(t,6);
afficher (t,6);
return 0;
}

/* ------------------------------------------------------------------------------------- */
/* Taille des variables en langage C : sizeof(<type>)  */

int main() {
#include <stdio.h>
printf("Char : %d octets\n", sizeof(char));
printf("Int : %d octets\n", sizeof(int));
printf("Float : %d octets\n", sizeof(float));
return 0;
}

/* ------------------------------------------------------------------------------------- */
/* Allocation standard d'espace mémoire */

int main() {
#include <stlib.h>

int* memoireAllouee = NULL;  // Création d'un pointeur sur un int

memoireAllouee = malloc(sizeof(int));
if (memoireAllouee == NULL) // L'allocation a échoué
  exit(0);		    /* Arrêt immédiat du programme */
// sinon, on peut continuer le programme normalement
return 0;
}

/* ------------------------------------------------------------------------------------- */
/* free :: libération espace mémoire */

int main() {
#include <stlib.h>
void free(void* pointeur);
return 0;
}

/* ------------------------------------------------------------------------------------- */
/* Création d'un Tableau dynamique : avec allocation dynamique de mémoire */

int main() {
/* Déclaration d'une matrice (tableau à deux dimensions) statique permettant de stocker jusqu'à 100 fois 10 entiers */
int tab[100][10]; 

/* Pour stocker N fois 10 entiers */
int N=35;
int **tableau;
tableau = malloc(N * 10 * sizeof(int)); // On alloue de la mémoire pour créer le tableau
if (tableau == NULL) // On vérifie si l'allocation a marché ou non
  {
    exit(0); // On arrête tout
  }
return 0;
}

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

Element* creationListe (int nb)	/* Itératif */
{
  Element *resteListe = NULL;
  do {
    Element *nouveau = malloc (sizeof (*nouveau)); /* pas besoin de déclarer dans la boucle: à corriger */
    if (nouveau == NULL) exit (EXIT_FAILURE);
    nouveau->nombre = nb;
    nouveau->suivant = resteListe;
    resteListe = nouveau;
    nb--;
  } while (nb > 0);
  return resteListe;
}

Element* insertion (Element *debut, int nouveauNb) /* Insertion en début de liste */
{
  /* Création d'un nouvel élément */
  Element *nouveau = malloc (sizeof (*nouveau));
  if (debut == NULL || nouveau == NULL) exit (EXIT_FAILURE);
  nouveau->nombre = nouveauNb;
  nouveau->suivant = debut;
  return nouveau;
}

int main(void)
{
  Element * debut = creationListe(10);
  debut = insertion (debut, 11);
  while (debut != NULL)
    {
      printf("%d   ", debut->nombre);
      debut = debut->suivant;
    }
  printf("\n");
}

/* ------------------------------------------------------------------------------------- */
/* Recherche d'un élément dans une liste simplement chainée */

int main() {
Element* rechercher (Element* debut, int val)
{
  if ((debut == NULL) || (val == debut-> nombre)) return debut;
  rechercher (debut->suivant, val);
}
return 0;
}
