#include <stdio.h>

int n = 4;

int main()
{
    int i, resultat;
    resultat = 1;
    for (i = 1; i <= n; i++)
        resultat = resultat * i;
    printf("Factorielle de %d = %d", n, resultat);
    return 0;
}
