#include <stdio.h>

int a = 24;
int b = 30;

int main()
{
    int k;
    while (b != 0)
    {
        k = a % b;
        a = b;
        b = k;
        printf("a = %d, b = %d, a %% b = %d\n", a, b, k);
    }
    printf("PGCD obtenu = %d", a);
    return 0;
}
