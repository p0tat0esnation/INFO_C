#include <stdio.h>

// Prototype of the puissance function
float puissance(float nb, int exposant);

float puissance(float nb, int exposant)
{
    float resultat = 1;
    int compteur = 0;
    while (compteur < exposant)
    {
        compteur++;
        resultat = resultat * nb;
    }
    return resultat;
}

int main() {
    float x = 2.5;
    int m = 5;
    printf("%5.2f puissance %d = %10.3f\n", x, m, puissance(x, m));
    return 0;
}
