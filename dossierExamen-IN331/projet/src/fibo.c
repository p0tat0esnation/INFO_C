#include "functions.h"

//Un petit exercice pour s'échauffer : écrire une fonction C qui calcule la valeur de Fibonacci pour un entier n.

void fibonnacci(int n, int values[]){
	if (n <= 0) return;
	values[0] = 0;
	if (n == 1) return;
	values[1] = 1;
	for (int i = 2; i < n; i++) {
		values[i] = values[i-1] + values[i-2];
	}
}