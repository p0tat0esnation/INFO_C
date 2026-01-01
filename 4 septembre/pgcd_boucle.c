#include <stdio.h>

int a = 24;
int b = 30;

int main()
{
    int pgcd = 1;
    for (int i = 1; i <= a && i <= b; ++i)
    {
        if (a % i == 0 && b % i == 0)
            pgcd = i;
    }
    printf("PGCD de %d et %d = %d", a, b, pgcd);
    return 0;
}
