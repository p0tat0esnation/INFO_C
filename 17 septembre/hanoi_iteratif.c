#include <stdio.h>
#include <math.h>

#define MAX 64

typedef struct {
    int disques[MAX];
    int top;
} Tour;

void init_tour(Tour *t, int n) {
    t->top = n-1;
    for (int i=0; i<n; ++i)
        t->disques[i] = n-i;
}

int pop(Tour *t) {
    return t->disques[t->top--];
}

void push(Tour *t, int disk) {
    t->disques[++t->top] = disk;
}

void move(Tour *from, Tour *to, int from_num, int to_num, int *coup) {
    int disk = pop(from);
    push(to, disk);
    printf("%4d     %d -> %d\n", ++(*coup), from_num, to_num);
}

int main() {
    int n = 3; // nombre de disques
    Tour tours[3];
    int coup = 0;
    for (int i=0; i<3; ++i) tours[i].top = -1;
    init_tour(&tours[0], n);
    
    int total_moves = pow(2, n) - 1;
    int src = 0, dest = 2, aux = 1;
    if (n%2 == 0) { int tmp = dest; dest = aux; aux = tmp; }

    for (int i=1; i<=total_moves; ++i) {
        if (i % 3 == 1)
            move(&tours[src], &tours[dest], src+1, dest+1, &coup);
        else if (i % 3 == 2)
            move(&tours[src], &tours[aux], src+1, aux+1, &coup);
        else if (i % 3 == 0)
            move(&tours[aux], &tours[dest], aux+1, dest+1, &coup);
    }
    return 0;
}
