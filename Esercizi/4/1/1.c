//Dati due insiemi A e B, si definisce prodotto cartesiano l'insieme delle coppie ordinate A×B={(a,b)|a∈A∧b∈B}
//rappresentando i due insiemi A
//e B attraverso due array, implementare una funzione che restituisca il prodotto cartesiano A×B all'interno di una matrice,
// i.e. ogni riga rappresenta un elemento del prodotto cartesiano.

#include <stdio.h>

#define MAX_DIM 8

void cartesianProduct(int *, int *, int *);

int main() {
    int a[MAX_DIM] = {
            1,2,3,4,5,6,7,8
    };
    int b[MAX_DIM] = {
            1,2,3,4,5,6,7,8
    };
    int c[MAX_DIM][2];

    cartesianProduct(a,b,c);

    for (int i = 0; i < MAX_DIM; i++) {
        printf("%d %d\n", c[i][0], c[i][1]);
    }
    return 0;
}

void cartesianProduct(int *a, int *b, int *c) {
    int i = 0;
    for (int j = 0; j < MAX_DIM; j++) {
        for (int k = 0; k < MAX_DIM; k++) {
            *(c + i) = *(a + j);
            *(c + i + 1) = *(b + k);
            i += 2;
        }
    }
}