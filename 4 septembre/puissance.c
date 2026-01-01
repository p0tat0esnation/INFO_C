#include <stdio.h>

double x = 2.0;
int m = 4;

int main()
{
    double resultat;
    int compteur;
    compteur = 0;
    resultat = 1;
    while (compteur < m)
    {
        compteur++;
        resultat = resultat * x;
    }
    printf("%5.2f puissance %d = %10.3f\n", x, m, resultat);
    return 0;
}
