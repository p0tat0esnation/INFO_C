/* -----------------------------------------------------------------------------
   Tests des variantes de listes chaînées :
   1) Simple sans sentinelle
   2) Simple avec sentinelle
   3) Double sans sentinelle
   4) Double circulaire avec sentinelle
----------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

/* ========================= 1) SIMPLE SANS SENTINELLE ========================= */

typedef struct CellS
{
    int valeur;
    struct CellS *suivant;
} CellS;

CellS *inserer_tete_simple_sans_sentinelle(CellS *tete, int valeur)
{
    CellS *n = malloc(sizeof(*n));
    if (n == NULL)
        exit(EXIT_FAILURE);
    n->valeur = valeur;
    n->suivant = tete;
    return n;
}

void afficher_simple(const CellS *tete)
{
    const CellS *p = tete;
    while (p != NULL)
    {
        printf("%d ", p->valeur);
        p = p->suivant;
    }
    printf("\n");
}

void liberer_simple(CellS *tete)
{
    while (tete != NULL)
    {
        CellS *suiv = tete->suivant;
        free(tete);
        tete = suiv;
    }
}

/* ========================== 2) SIMPLE AVEC SENTINELLE ========================= */

typedef struct CellSS
{
    int valeur;
    struct CellSS *suivant;
} CellSS;

CellSS *creer_sentinelle_simple(void)
{
    CellSS *sent = malloc(sizeof(*sent));
    if (sent == NULL)
        exit(EXIT_FAILURE);
    sent->valeur = -1; /* non utilisé */
    sent->suivant = NULL;
    return sent;
}

void inserer_apres_sentinelle_simple(CellSS *sentinelle, int valeur)
{
    CellSS *n = malloc(sizeof(*n));
    if (n == NULL)
        exit(EXIT_FAILURE);
    n->valeur = valeur;
    n->suivant = sentinelle->suivant;
    sentinelle->suivant = n;
}

void afficher_simple_avec_sentinelle(const CellSS *sentinelle)
{
    const CellSS *p = sentinelle->suivant;
    while (p != NULL)
    {
        printf("%d ", p->valeur);
        p = p->suivant;
    }
    printf("\n");
}

void liberer_simple_avec_sentinelle(CellSS *sentinelle)
{
    CellSS *p = sentinelle->suivant;
    while (p != NULL)
    {
        CellSS *suiv = p->suivant;
        free(p);
        p = suiv;
    }
    free(sentinelle);
}

/* ========================== 3) DOUBLE SANS SENTINELLE ========================= */

typedef struct CellD
{
    int valeur;
    struct CellD *suivant;
    struct CellD *precedent;
} CellD;

CellD *inserer_tete_double_sans_sentinelle(CellD *tete, int valeur)
{
    CellD *n = malloc(sizeof(*n));
    if (n == NULL)
        exit(EXIT_FAILURE);
    n->valeur = valeur;
    n->precedent = NULL;
    n->suivant = tete;
    if (tete != NULL)
        tete->precedent = n;
    return n;
}

void afficher_double(const CellD *tete)
{
    const CellD *p = tete;
    while (p != NULL)
    {
        printf("%d ", p->valeur);
        p = p->suivant;
    }
    printf("\n");
}

void liberer_double(CellD *tete)
{
    while (tete != NULL)
    {
        CellD *suiv = tete->suivant;
        free(tete);
        tete = suiv;
    }
}

/* =================== 4) DOUBLE CIRCULAIRE AVEC SENTINELLE ==================== */

typedef struct Element2
{
    struct Element2 *suivant;
    struct Element2 *precedent;
    int valeur;
} Element2;

Element2 *creer_sentinelle_double_circulaire(void)
{
    Element2 *sent = malloc(sizeof(*sent));
    if (sent == NULL)
        exit(EXIT_FAILURE);
    sent->valeur = -1; /* non utilisé */
    sent->suivant = sent;
    sent->precedent = sent;
    return sent;
}

Element2 *nouvel_element2(int valeur)
{
    Element2 *x = malloc(sizeof(*x));
    if (x == NULL)
        exit(EXIT_FAILURE);
    x->valeur = valeur;
    x->suivant = NULL;
    x->precedent = NULL;
    return x;
}

Element2 *listeInserer3(Element2 *debut, Element2 *x)
{
    x->suivant = debut->suivant;
    debut->suivant->precedent = x;
    debut->suivant = x;
    x->precedent = debut;
    return debut;
}

void afficher_double_circulaire_avec_sentinelle(const Element2 *sentinelle)
{
    const Element2 *p = sentinelle->suivant;
    while (p != sentinelle)
    {
        printf("%d ", p->valeur);
        p = p->suivant;
    }
    printf("\n");
}

void liberer_double_circulaire_avec_sentinelle(Element2 *sentinelle)
{
    Element2 *p = sentinelle->suivant;
    while (p != sentinelle)
    {
        Element2 *suiv = p->suivant;
        free(p);
        p = suiv;
    }
    free(sentinelle);
}

int main(void)
{
    printf("1) Simple sans sentinelle :\n");
    CellS *l1 = NULL;
    l1 = inserer_tete_simple_sans_sentinelle(l1, 3);
    l1 = inserer_tete_simple_sans_sentinelle(l1, 2);
    l1 = inserer_tete_simple_sans_sentinelle(l1, 1);
    afficher_simple(l1);
    liberer_simple(l1);

    printf("2) Simple avec sentinelle :\n");
    CellSS *s1 = creer_sentinelle_simple();
    inserer_apres_sentinelle_simple(s1, 3);
    inserer_apres_sentinelle_simple(s1, 2);
    inserer_apres_sentinelle_simple(s1, 1);
    afficher_simple_avec_sentinelle(s1);
    liberer_simple_avec_sentinelle(s1);

    printf("3) Double sans sentinelle :\n");
    CellD *l2 = NULL;
    l2 = inserer_tete_double_sans_sentinelle(l2, 3);
    l2 = inserer_tete_double_sans_sentinelle(l2, 2);
    l2 = inserer_tete_double_sans_sentinelle(l2, 1);
    afficher_double(l2);
    liberer_double(l2);

    printf("4) Double circulaire avec sentinelle :\n");
    Element2 *sent = creer_sentinelle_double_circulaire();
    listeInserer3(sent, nouvel_element2(3));
    listeInserer3(sent, nouvel_element2(2));
    listeInserer3(sent, nouvel_element2(1));
    afficher_double_circulaire_avec_sentinelle(sent);
    liberer_double_circulaire_avec_sentinelle(sent);

    return 0;
}