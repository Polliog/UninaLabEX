//data una matrice M∈RN×N, copiare in un vettore la sua diagonale principale ed in un altro vettore la sua diagonale secondaria. Si ricorda che:
//
//la diagonale principale di una matrice M∈RN×N
//
//        è la sequenza degli elementi mi,j tali che i=j
//
//        . Esempio:
//
//M=⎛⎜⎝m1,1 m1,2 m1,3m2,1 m2,2 m2,3m3,1 m3,2 m3,3⎞⎟⎠
//
//la diagonale secondaria di una matrice M∈RN×N
//
//        è la sequenza degli elementi mi,j tali che i+j=N+1
//
//        . Esempio:
//
//M=⎛⎜⎝m1,1 m1,2 m1,3m2,1 m2,2 m2,3m3,1 m3,2 m3,3⎞⎟

#include <stdio.h>

void estraiPrimaria(int[][3], int[], int);
void estraiSecondaria(int[][3], int[], int);
void stampaVettore(int[], int);


int main() {
    int m[3][3] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };

    int v1[3];
    int v2[3];

    estraiPrimaria(m,v1,3);
    estraiSecondaria(m,v2,3);

    stampaVettore(v1,3);
    stampaVettore(v2,3);
}

void estraiPrimaria(int m[][3], int v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                v[i] = m[i][j];
            }
        }
    }
}

void estraiSecondaria(int m[][3], int v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j == n - 1) {
                v[i] = m[i][j];
            }
        }
    }
}

void stampaVettore(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}