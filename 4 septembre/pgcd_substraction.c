#include <stdio.h>

int a = 24;
int b = 30;

int main()
{
    int c;
    if (b == 0)
        printf("Le PGCD est %d", a);
    else
    {
        while (a > 0)
        {
            if (a < b)
            {
                c = a;
                a = b;
                b = c;
            }
            a = a - b;
        }
        printf("Le PGCD est %d", b);
    }
    return 0;
}
