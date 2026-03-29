#include <stdio.h>

/* ------------------------ Tours de Hanoï ------------------- */

void deplacer(int nb_disques, int depart, int arrivee, int intermediaire)
{
    static int coup = 0;
    if (nb_disques == 1) /* Déplacement d'un seul disque */
        printf("%4d     %d -> %d\n", ++coup, depart, arrivee);
    else /* Déplacement d'une pile de disques */
    {
        deplacer(nb_disques - 1, depart, intermediaire, arrivee);
        deplacer(1, depart, arrivee, intermediaire);
        deplacer(nb_disques - 1, intermediaire, arrivee, depart);
    }
}

int main()
{
    int nbd = 3;
    deplacer(nbd, 1, 3, 2);
    return 0;
}
