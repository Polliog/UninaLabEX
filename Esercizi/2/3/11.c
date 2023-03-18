//data una matrice quadrata, dire se la diagonale principale è uguale alla diagonale secondaria

#include <stdio.h>

int main() {
    int m[3][3];
    int v1[3];
    int v2[3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d]", i+1,j+1);
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        v1[i] = m[i][i];
    }

    for (int i = 0; i < 3; i++) {
        v2[i] = m[2-i][2-i];
    }

    int k = 0;

    for (int i = 0; i < 3; i++) {
        if (v1[i] == v2[i]) {
            k++;
        }
    }

    if (k == 3) {
        printf("La diagonale principale è uguale alla diagonale secondaria");
    } else {
        printf("La diagonale principale non è uguale alla diagonale secondaria");
    }
}