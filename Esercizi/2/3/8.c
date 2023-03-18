//data una matrice e due interi pos1 e pos2, scambiare le due righe nelle posizioni corrispondenti

#include <stdio.h>

int main() {
    int m[3][3];
    int pos1, pos2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d]", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }

    printf("Inserisci pos1 e pos2");
    scanf("%d %d", &pos1, &pos2);

    int temp[3];

    for (int i = 0; i < 3; i++) {
        temp[i] = m[pos1][i];
    }

    for (int i = 0; i < 3; i++) {
        m[pos1][i] = m[pos2][i];
    }

    for (int i = 0; i < 3; i++) {
        m[pos2][i] = temp[i];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
    }
}