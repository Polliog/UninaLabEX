//sommare due matrici elemento per elemento memorizzandone i valori in una terza matrice

#include <stdio.h>

int main() {
    int m1[3][3];
    int m2[3][3];
    int m3[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d] di m1", i + 1, j + 1);
            scanf("%d", &m1[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d] di m2", i + 1, j + 1);
            scanf("%d", &m2[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m3[i][j]);
        }
    }

}