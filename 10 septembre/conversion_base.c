#include <stdio.h>

void conversion10versB(int nb, int base)
{
  int quotient = 1, reste;
  while (quotient != 0)
  {
    quotient = nb / base;
    reste = nb % base;
    nb = quotient;
    printf("%d\n", reste);
  }
}

int main()
{
  int nb = 2500;
  conversion10versB(nb, 8);
  return 0;
}
