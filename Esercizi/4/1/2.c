//Si generalizzi l'operazione precedente al caso in cui gli insiemi A e B siano rappresentati da due matrici in cui ogni riga corrisponde ad un elemento dell'insieme rappresentato. Esempio:

#include <stdio.h>

#define MAX_DIM 8

void cartesianProduct(int *, int *, int *);

int main() {
    int a[MAX_DIM][2] = {
            {1,2},
            {3,4},
            {5,6},
            {7,8}
    };
    int b[MAX_DIM][2] = {
            {1,2},
            {3,4},
            {5,6},
            {7,8}
    };
    int c[MAX_DIM][4];

    cartesianProduct(a,b,c);

    for (int i = 0; i < MAX_DIM; i++) {
        printf("%d %d %d %d\n", c[i][0], c[i][1], c[i][2], c[i][3]);
    }
    return 0;
}

void cartesianProduct(int *a, int *b, int *c) {
    int i = 0;
    for (int j = 0; j < MAX_DIM; j++) {
        for (int k = 0; k < MAX_DIM; k++) {
            *(c + i) = *(a + j);
            *(c + i + 1) = *(a + j + 1);
            *(c + i + 2) = *(b + k);
            *(c + i + 3) = *(b + k + 1);
            i += 4;
        }
    }
}