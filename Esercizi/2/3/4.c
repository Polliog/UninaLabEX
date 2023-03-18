//copiare la diagonale principale di una matrice in un vettore

#include <stdio.h>

int main() {
    int m[3][3];
    int v[3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d]", i+1,j+1);
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        v[i] = m[i][i];
    }

    printf("Risultato: %d %d %d", v[0], v[1], v[2]);
}