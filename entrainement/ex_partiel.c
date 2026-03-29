#include <stdio.h>
#include <stdlib.h>

int elementLibre(liste tab, int n);
void creerListeVide(liste tab, int n);
void afficherListe(int tete, liste tab);
void insererElement(int x, int *tete, liste tab, int n);

typedef struct
{
    int valeur;
    int suivant;
} element;
typedef element *liste;

int elementLibre(liste tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (tab[i].suivant == -1)
        {
            return i; // On retourne l'indice de la première case libre
        }
    }
    return -1; // Retourne -1 si aucune case n'est libre (tableau plein)
}

void creerListeVide(liste tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        tab[i].suivant = -1;
    }
}

void afficherListe(int tete, liste tab)
{
    int courant = tete;

    // Tant qu'on n'a pas atteint la fin de la liste (-2)
    // On ajoute != -1 par sécurité au cas où la liste serait mal formée
    while (courant != -2 && courant != -1)
    {
        printf("%d ", tab[courant].valeur);
        courant = tab[courant].suivant;
    }
    printf("\n");
}

void insererElement(int x, int *tete, liste tab, int n)
{
    // 1. Trouver une case libre
    int libre = elementLibre(tab, n);

    if (libre == -1)
    {
        printf("Erreur : Le tableau est plein, impossible d'insérer.\n");
        return;
    }

    // 2. Initialiser la nouvelle case
    tab[libre].valeur = x;

    // 3. Cas particulier : la liste est vide OU le nouvel élément doit devenir la nouvelle tête
    // (*tete == -2 signifie liste vide selon comment vous l'initialisez dans le main)
    if (*tete == -2 || tab[*tete].valeur >= x)
    {
        tab[libre].suivant = *tete;
        *tete = libre; // C'est ici que le pointeur est indispensable
        return;
    }

    // 4. Cas général : insertion au milieu ou à la fin
    int courant = *tete;
    int precedent = -1;

    // On avance jusqu'à trouver un élément plus grand que x
    while (courant != -2 && tab[courant].valeur < x)
    {
        precedent = courant;
        courant = tab[courant].suivant;
    }

    // On chaîne le nouvel élément entre "precedent" et "courant"
    tab[precedent].suivant = libre;
    tab[libre].suivant = courant;
}