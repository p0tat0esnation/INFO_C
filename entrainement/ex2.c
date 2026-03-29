#include <stdio.h>
#include <stdlib.h>

void echanger(int t[], int i, int j)
{
    int temp = t[i];
    t[i] = t[j];
    t[j] = temp;
}

int pair(int nb)
{
    if (nb % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void triParite(int tab[], int nbVal)
{
    int i = 0;         // Indice partant du début
    int j = nbVal - 1; // Indice partant de la fin

    while (i < j)
    {
        // Avancer i tant que l'élément est déjà pair (bien placé à gauche)
        // Sécurité : on vérifie aussi (i < j) pour ne pas déborder
        while ((i < j) && pair(tab[i]))
        {
            i++;
        }

        // Reculer j tant que l'élément est déjà impair (bien placé à droite)
        while ((i < j) && !pair(tab[j]))
        {
            j--;
        }

        // Si i est toujours à gauche de j, on a trouvé deux éléments mal placés
        if (i < j)
        {
            echanger(tab, i, j);
            // Optionnel mais efficace : on décale d'un cran après l'échange
            i++;
            j--;
        }
    }
}