/* ---------------------------------------------- */
/* Structure d'un noeud dans un arbre */
/* ---------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>
#define NB 15			/* Nb de noeuds à placer dans l'arbre */

typedef struct Noeud Noeud;
struct Noeud{
  int valeur;
  Noeud* gauche;
  Noeud* droite;
};

Noeud * creerNoeud ()
{
  Noeud *nouveau = (Noeud*) malloc (sizeof (Noeud));
  if (nouveau == NULL) exit (EXIT_FAILURE);
  nouveau->valeur = 0;	/* inutile */
  nouveau->gauche = NULL;	/* inutile */
  nouveau->droite = NULL;	/* inutile */
  return nouveau;
}

Noeud* creerArbreBinaire(Noeud noeudcourant, int reste) /* À RÉÉCRIRE */
{
  int moitie = reste / 2;
  if (reste == 0)
    {
      noeudcourant->gauche = NULL;
      noeudcourant->droite = NULL;
    }
  if (moitie == 0)		/* il n'y a qu'un noeud à créer à gauche */
    {
      noeudcourant->gauche = creerArbreBinaire(creerNoeud (), 0);
      noeudcourant->droite = NULL;
    }
  else
    {
      noeudcourant->droite = creerArbreBinaire(creerNoeud (), moitie);
      noeudcourant->gauche = creerArbreBinaire(creerNoeud (), moitie + (reste%2));
    }
  return (noeudcourant);
}

Noeud * creerArbre (int nbNoeuds)
{
  if (nbNoeuds == 0)
    return NULL;
  else
    return (creerArbreBinaire(creerNoeud(), nbNoeuds-1));
}

void remplirArbreBinaire_pre (Noeud* racine, int valeur)
  {				/* arbre non vide */
    if (racine == NULL) return;
    racine->valeur = valeur;
    remplirArbreBinaire_pre (racine->gauche, int valeur)
  }

void afficherArbre (Noeud *racine)
{
  if (racine == NULL) return;
  printf (" %d", racine->valeur);
  afficherArbre (racine->gauche);
  afficherArbre (racine->droite);
}

int main(void)
{
  /* afficherArbre (creerNoeud (12)); */
  Noeud* racine = creerArbre(16);
  remplirArbreBinaire (racine,0);
  afficherArbre (racine);
}

/* --------------------------------------------- */
/* Avec un pointeur de retour vers le noeud père */
/* --------------------------------------------- */
typedef struct Noeud Noeud;
struct Noeud{
  int valeur;
  Noeud* pere;
  Noeud* gauche;
  Noeud* droite;
};

/* ---------------------------------------------- */
/* Parcours préfixé (notation polonaise) */
/* ---------------------------------------------- */

void parcoursPrefixe (Noeud * racine)
  {
    if (racine != NULL)
      {
	traiterNoeud(racine);
	parcoursPrefixe(racine->gauche);
	parcoursPrefixe(racine->droite);
      }
  }

void traiterNoeud (Noeud * n)
{
  printf("%d ", n->valeur)
return 0;
}

/* ---------------------------------------------- */
/* Parcours infixé */
/* ---------------------------------------------- */

void parcoursInfixe (Noeud * racine)
  {
    if (racine != NULL)
      {
	parcoursPrefixe(racine->gauche);
	Traiter(racine);
	parcoursPrefixe(racine->droite);
      }
  }

/* ---------------------------------------------- */
/* Parcours postfixé */
/* ---------------------------------------------- */

void parcoursPostfixe (Noeud * racine)
  {
    if (racine != NULL)
      {
	parcoursPrefixe(racine->gauche);
	parcoursPrefixe(racine->droite);
	Traiter(racine);
      }
  }

/* ---------------------------------------------- */
/* Parcours préfixé itératif */
/* ---------------------------------------------- */

void parcoursPrefixeIteratif (Noeud * racine)
{
  Pile * p = initialiser(); /* autre possibilité : déclarer la pile à l'ext de la
fonction */
  Element *courant;
  empiler(p, racine);  /*Vérifier arbre non vide : racine !=NULL.*/
  while (!pileVide(p))
    {
      courant = depiler(p);
      traiterNoeud(courant);
      if (courant->droite != NULL) empiler(p, courant->droite);
      if (courant->gauche != NULL) empiler(p, courant->gauche);
      }
}      

/* ---------------------------------------------- */
/* Parcours en largeur itératif (avec file), arbre binaire */
/* ---------------------------------------------- */

void parcoursLargeurIteratifAB (Noeud * racine)
{
  File * f = initialiser(); /* autre possibilité : déclarer la file à l'ext de la fonction */
  Element *courant;
  enfiler(f, racine);  /*Vérifier arbre non vide : racine !=NULL.*/
  while (!fileVide(p))
    {
      courant = defiler(p);
      traiterNoeud(courant);
      if (courant->gauche != NULL) enfiler(p, courant->gauche);
      if (courant->droite != NULL) enfiler(p, courant->droite);
      }
}      

/* ---------------------------------------------- */
/* Parcours en largeur itératif (avec file), arbre général */
/* ---------------------------------------------- */
void parcoursLargeurIteratif (Noeud * racine)
{
  File * f = initialiser(); /* autre possibilité : déclarer la file à l'ext de la fonction */
  Element *courant;
  enfiler(f, racine);  /*Vérifier arbre non vide : racine !=NULL.*/
  while (!fileVide(p))
    {
      courant = defiler(p);
      traiterNoeud(courant);
      enfiler(f, courant->filsGauche);
      courant = courant->filsGauche->frereDroit;
      while (courant != NULL)
      {
      enfiler(f, courant);
      courant = courant->frereDroit; /* déplacement à droite pour récupérer les autres frères */
      }
    }
}      

/* Déclaration d'un élément d'une pile */

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

/* Déclaration d'une pile */

typedef struct Pile Pile;
struct Pile
{
    Element *premier;
};

/* ------------------------- */
/* Initialisation d'une pile */
/* ------------------------- */

Pile *initialiser()
{
    Pile *pile = malloc(sizeof(*pile));
    pile->premier = NULL;
    return pile;
}

/* ------------------------- */
/* Prédicat pileVide() */
/* ------------------------- */

#include <stdbool.h>
bool pileVide(Pile *pile)
{
    return (pile->premier == NULL);
}

/* ------------------------- */
/* empiler() */
/* ------------------------- */
void empiler(Pile *pile, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

/* ------------------------- */
/* Prédicat dépiler() */
/* ------------------------- */

#include <stdbool.h>
int depiler(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDepile = 0;
    Element *elementDepile = pile->premier;

    if (!pileVide(pile))
    {
        nombreDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return nombreDepile;
}

/* ------------------------- */
/* Prédicat afficherPile() */
/* ------------------------- */

void afficherPile(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
    }

    printf("\n");
}

int main()
{
    Pile *maPile = initialiser();

    empiler(maPile, 4);
    empiler(maPile, 8);
    empiler(maPile, 15);
    empiler(maPile, 16);
    empiler(maPile, 23);
    empiler(maPile, 42);

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    printf("Je depile %d\n", depiler(maPile));
    printf("Je depile %d\n", depiler(maPile));

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    return 0;
}

/* ------------------------- */
/* Déclaration file */
/* ------------------------- */

typedef struct File File;
struct File
{
    Element *premier;
};

/* ------------------------- */
/* initialiser() */
/* ------------------------- */
File *initialiser()
{
    File *file = malloc(sizeof(*file));
    file->premier = NULL;

    return file;
}

/* ------------------------- */
/* Prédicat fileVide() */
/* ------------------------- */
#include <stdbool.h>
bool fileVide(File *file)
{
    return (file->premier == NULL);
}

/* ------------------------- */
/* enfiler() */
/* ------------------------- */
void enfiler(File *file, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier */
    {
        file->premier = nouveau;
    }
}

/* ------------------------- */
/* défiler() */
/* ------------------------- */
int defiler(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDefile = 0;

    /* On vérifie s'il y a quelque chose à défiler */
    if (file->premier != NULL)
    {
        Element *elementDefile = file->premier;

        nombreDefile = elementDefile->nombre;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return nombreDefile;
}

/* ------------------------- */
/* afficherFile() */
/* ------------------------- */
void afficherFile(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *element = file->premier;

    while (element != NULL)
    {
        printf("%d ", element->nombre);
        element = element->suivant;
    }

    printf("\n");
}

int main()
{
    File *maFile = initialiser();

    enfiler(maFile, 4);
    enfiler(maFile, 8);
    enfiler(maFile, 15);
    enfiler(maFile, 16);
    enfiler(maFile, 23);
    enfiler(maFile, 42);

    printf("\nEtat de la file :\n");
    afficherFile(maFile);

    printf("\nJe defile %d\n", defiler(maFile));
    printf("Je defile %d\n", defiler(maFile));

    printf("\nEtat de la file :\n");
    afficherFile(maFile);

    return 0;
}
