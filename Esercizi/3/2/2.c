//. Il prodotto tra una matrice A∈RR×C ed un vettore x∈RC è definito come il vettore q∈RR tale che, ∀1≤i≤R, vale: qi=C∑j=1ai,j⋅xj In altri termini: q=⎛⎜
//⎜
//⎜
//⎜
//⎜⎝a1,1⋅x1+⋯+a1,C⋅xCa2,1⋅x1+⋯+a2,C⋅xC⋮aR,1⋅x1+⋯+aR,C⋅xC⎞⎟
//⎟
//⎟
//⎟
//⎟⎠

//la matrice somma S∈RR×C tra due matrici M,W∈RR×C è la matrice avente, in ogni posizione, la somma degli elementi nelle posizioni corrispondenti, ossia, ∀1≤i≤R,∀1≤j≤C:
//si,j=mi,j+mi,j
//scrivere un programma che, date due matrici, calcoli e visualizzi la loro matrice somma

#include <stdio.h>

void prodottoMatrice(int[][3], int, int, int);
void stampaMatrice(int[][3], int, int);
int main() {
    int m1[3][3] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };

    int n = 10;

    prodottoMatrice(m1,n,3,3);
    stampaMatrice(m1,3,3);
}

void prodottoMatrice(int m[][3], int n, int c, int r) {
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            m[i][j] *= n;
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