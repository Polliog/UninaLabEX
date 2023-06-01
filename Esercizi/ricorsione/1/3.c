//Stampare una matrice di dimensioni nr×nc
//di interi utilizzando una soluzione ricorsiva. Si consideri come caso base la stampa di una singola riga della matrice.

#include <stdio.h>


int stampa(int m[][3], int r, int c) {
    if (r == 1) {
        for (int i = 0; i < c; i++) {
            printf("%d ", m[r - 1][i]);
        }
        printf("\n");
    } else {
        stampa(m, r - 1, c);
        for (int i = 0; i < c; i++) {
            printf("%d ", m[r - 1][i]);
        }
        printf("\n");
    }
}

int main() {
    int m[3][3] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    stampa(m,3,3);
}