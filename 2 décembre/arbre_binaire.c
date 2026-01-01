/* ---------------------------------------------- */
/* Structure d'un noeud dans un arbre */
/* ---------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>
#define NB 16 /* Nb de noeuds à placer dans l'arbre */

typedef struct Noeud Noeud;
struct Noeud
{
  int valeur;
  Noeud *gauche;
  Noeud *droite;
};

Noeud *creerNoeud()
{
  Noeud *nouveau = (Noeud *)malloc(sizeof(Noeud));
  if (nouveau == NULL)
    exit(EXIT_FAILURE);
  nouveau->valeur = 0;    /* inutile */
  nouveau->gauche = NULL; /* inutile */
  nouveau->droite = NULL; /* inutile */
  return nouveau;
}

Noeud *creerArbreBinaire(Noeud *noeudcourant, int reste) /* Réécrit : prend un pointeur */
{
  if (noeudcourant == NULL)
    return NULL;
  if (reste == 0)
  {
    noeudcourant->gauche = NULL;
    noeudcourant->droite = NULL;
    return noeudcourant;
  }
  int moitie = reste / 2;
  if (moitie == 0) /* il n'y a qu'un noeud à créer à gauche */
  {
    noeudcourant->gauche = creerArbreBinaire(creerNoeud(), 0);
    noeudcourant->droite = NULL;
  }
  else
  {
    noeudcourant->droite = creerArbreBinaire(creerNoeud(), moitie);
    noeudcourant->gauche = creerArbreBinaire(creerNoeud(), moitie + (reste % 2));
  }
  return (noeudcourant);
}

Noeud *creerArbre(int nbNoeuds)
{
  if (nbNoeuds == 0)
    return NULL;
  else
    return (creerArbreBinaire(creerNoeud(), nbNoeuds - 1));
}

void remplirArbreBinaire(Noeud *racine, int valeur)
{ /* parcours préfixe : assigne valeurs */
  if (racine == NULL)
    return;
  racine->valeur = valeur;
  remplirArbreBinaire(racine->gauche, valeur + 1);
  remplirArbreBinaire(racine->droite, valeur + 1);
}

void afficherArbre(Noeud *racine)
{
  if (racine == NULL)
    return;
  printf(" %d", racine->valeur);
  afficherArbre(racine->gauche);
  afficherArbre(racine->droite);
}

static void afficherRec(Noeud *node, const char *prefix, int isLast, const char *label)
{
  if (!node)
    return;

  printf("%s%s%s%d\n",
         prefix,
         isLast ? "\\-- " : "|-- ",
         label,
         node->valeur);

  char newPrefix[1024];
  snprintf(newPrefix, sizeof(newPrefix), "%s%s", prefix, isLast ? "    " : "|   ");

  int hasLeft = (node->gauche != NULL);
  int hasRight = (node->droite != NULL);

  // Le fils gauche n'est "dernier" que s'il n'y a pas de fils droit
  if (hasLeft)
    afficherRec(node->gauche, newPrefix, !hasRight, "G: ");

  // Le fils droit est toujours le dernier (si présent)
  if (hasRight)
    afficherRec(node->droite, newPrefix, 1, "D: ");
}

void afficherArbreVrai(Noeud *racine)
{
  if (!racine)
  {
    puts("(arbre vide)");
    return;
  }

  printf("%d\n", racine->valeur);

  int hasRight = (racine->droite != NULL);

  if (racine->gauche)
    afficherRec(racine->gauche, "", !hasRight, "G: ");

  if (racine->droite)
    afficherRec(racine->droite, "", 1, "D: ");
}

int main(void)
{
  /* afficherArbre (creerNoeud (12)); */
  Noeud *racine = creerArbre(NB);
  remplirArbreBinaire(racine, 0);
  afficherArbreVrai(racine);
}

/*https://www.lri.fr/~fiorenzi/Teaching/AL/C4.pdf*/