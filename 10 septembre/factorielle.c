#include <stdio.h>



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

int main() {
    int n = 4;
    printf("%d! = %d\n", n, factorielle(n));
    return 0;
}
