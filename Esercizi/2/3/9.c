//copiare il perimetro di una matrice in un vettore

#include <stdio.h>

int main() {
    int m[3][3];
    int v[8];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d]", i+1,j+1);
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        v[i] = m[0][i];
    }

    for (int i = 0; i < 3; i++) {
        v[i+3] = m[i][2];
    }

    for (int i = 0; i < 3; i++) {
        v[i+6] = m[2][2-i];
    }

    for (int i = 0; i < 3; i++) {
        v[i+9] = m[2-i][0];
    }

    printf("Risultato: %d %d %d %d %d %d %d %d", v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
}