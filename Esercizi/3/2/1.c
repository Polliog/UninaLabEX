//la matrice somma S∈RR×C tra due matrici M,W∈RR×C è la matrice avente, in ogni posizione, la somma degli elementi nelle posizioni corrispondenti, ossia, ∀1≤i≤R,∀1≤j≤C:
//si,j=mi,j+mi,j
//scrivere un programma che, date due matrici, calcoli e visualizzi la loro matrice somma

#include <stdio.h>

void sommaMatriciale(int[][3], int[][3],int[][3], int,int);
void stampaMatrice(int[][3], int, int);
int main() {
    int m1[3][3] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };

    int m2[3][3]  = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };

    int m3[3][3];

    sommaMatriciale(m1,m2,m3,3,3);
    stampaMatrice(m3,3,3);
}

void sommaMatriciale(int m1[][3], int m2[][3], int m3[][3], int c, int r) {
    for (int i = 0; i < c;i++) {
        for (int j = 0; j < r;j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void stampaMatrice(int m[][3], int c, int r) {
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}