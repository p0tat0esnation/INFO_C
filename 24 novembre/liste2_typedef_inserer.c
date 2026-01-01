


#include <stdlib.h>

typedef struct Element2 Element2;
struct Element2
{
  int valeur;
  Element2 *precedent, *suivant;
};

/* Prototype de la fonction d'insertion */
Element2 * listeInserer2 (Element2 * debut, Element2 * x);

int main() {
  return 0;
}



Element2 * listeInserer2 (Element2 * debut, Element2 * x){
  x->precedent = NULL;
  x->suivant = debut;
  if (debut != NULL)
    debut->precedent = x;
  return x;
}
