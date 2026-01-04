#include <stdio.h>
#include <math.h>

int main() {
    int n = 3; // nombre de disques
    int total_moves = (int)pow(2, n) - 1;
    int a = 1, b = 2, c = 3;

    // Pour n pair, on échange le rôle de b et c
    if (n % 2 == 0) {
        int temp = b; b = c; c = temp;
    }

    for (int i = 1; i <= total_moves; ++i) {
        int from, to;
        if (i % 3 == 1) { from = a; to = c; }
        else if (i % 3 == 2) { from = a; to = b; }
        else { from = b; to = c; }
        printf("%4d     %d -> %d\n", i, from, to);
    }
    return 0;
}
