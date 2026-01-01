#include <stdio.h>



float puissanceRec (float x, int N)
{
    float resultat;
    if (N == 0)
        resultat = 1;
    else
        resultat = x * puissanceRec (x, N-1);
    return resultat;
}

int main() {
    float x = 2;
    int m = 3;

    printf ("%5.2f puissance %d = %10.3f\n", x, m, puissanceRec(x,m));
    return 0;
}
