//Il prodotto tra due matrici M∈RR×Q e W∈RQ×C
//
//        è definito come la matrice P∈RR×C
//        tale che, ∀1≤i≤R,∀1≤j≤C
//
//:
//pi,j=Q∑k=1mi,k⋅wk,j==mi,1⋅w1,j+mi,2⋅w2,j+mi,3⋅w3,j+⋯+mi,Q⋅wQ,j
//
//        Scrivere un programma che, date due matrici, ne calcoli il prodotto.

#include <stdio.h>

void prodottoMatriciale(int[][3], int[][3],int[][3], int,int);
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

    prodottoMatriciale(m1,m2,m3,3,3);
    stampaMatrice(m3,3,3);
}

void prodottoMatriciale(int m1[][3], int m2[][3], int m3[][3], int c, int r) {
    for (int i = 0; i < c;i++) {
        for (int j = 0; j < r;j++) {
            m3[i][j] = m1[i][j] * m2[i][j];
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