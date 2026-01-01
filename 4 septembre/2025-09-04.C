#include <stdio.h>


int a = 24;
int b = 30;




int main() {
int c;
if (b == 0)
  printf("Le PGCD est %d", a);
 else {
   while (a > 0)
     {
     if (a < b) {
       c = a;
       a = b;
       b = c;
       }
     a = a-b;
     }
   printf("Le PGCD est %d", b);
   }
return 0;
}

#include <stdio.h>


int a = 24;
int b = 30;




int main() {
int pgcd;
for(int i=1; i <= a && i <= b; ++i)
{
    if(a%i==0 && b%i==0)
        pgcd = i;
}
printf("PGCD de %d et %d = %d", a, b, pgcd);
return 0;
}

#include <stdio.h>


int a = 24;
int b = 30;




int main() {
int k;

while (b != 0)
  {
    k = a%b;
    a=b;
    b=k;
    }
printf("PGCD obtenu = %d", a);
return 0;
}

#include <stdio.h>


int n = 4;



int main() {
int i, resultat;
resultat = 1;
for (i=1; i <= n; i++)
  resultat = resultat * i;
printf("Factorielle de %d = %d", n, resultat);
return 0;
}

#include <stdio.h>


double x = 2.0;
int m = 4;




int main() {
float resultat;
int compteur;
compteur = 0;
resultat = 1;
while (compteur < m)
  {
    compteur++;
    resultat = resultat*x;
  }
printf ("%5.2f puissance %d = %10.3f\n", x, m, resultat);
return 0;
}
