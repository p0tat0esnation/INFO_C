#include <stdio.h>
#include <stdlib.h>

int **creerMatrice(int nblignes, int nbcol)
{
    int **matrice = malloc(nblignes * sizeof(int *));
    if (matrice == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < nblignes; i++)
    {
        matrice[i] = malloc(nbcol * sizeof(int));
        if (matrice[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(matrice[j]);
            }
            free(matrice);
            return NULL;
        }
    }
    return matrice;
}

void liberermatrice(int **matrice, int nblignes)
{
    if (matrice == NULL)
    {
        return;
    }
    for (int i = 0; i < nblignes; i++)
    {
        free(matrice[i]);
    }
    free(matrice);
    return;
}

void initdiag(int **matrice, int taille)
{
    if (matrice == NULL)
    {
        return;
    }
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            if (i == j)
            {
                matrice[i][j] = 1;
            }
            else
            {
                matrice[i][j] = 0;
            }
        }
    }
}