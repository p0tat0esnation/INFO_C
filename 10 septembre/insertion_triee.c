#include <stdio.h>



int main() {
/* Insertion d'un nb dans un tableau trié JML p.66-68 */
float tab_notes[10] = {8.5, 9.5, 12.5, 18};
float note_a_inserer=11.2;
int i, nbnotes=4;

/* Boucle de décalage */
i=nbnotes;
while (i>0 && note_a_inserer<tab_notes[i-1])
  {
    tab_notes[i] = tab_notes[i--];
  }
tab_notes[i] = note_a_inserer;
nbnotes++;
printf("numcase %d nbnotes %d\n", i, nbnotes);
return 0;
}
