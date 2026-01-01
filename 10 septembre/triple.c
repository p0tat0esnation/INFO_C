#include <stdio.h>




int triple(int nombre)
{
    return 3 * nombre;
}   
 
int main()
{
    int nombreInitial = 12;
    printf("Le triple de ce nombre est %d\n", triple(nombreInitial));
    return 0;
}
