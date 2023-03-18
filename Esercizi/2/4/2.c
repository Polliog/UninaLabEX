//date due matrici M1 e M2, dire, per ogni riga di M2, se ne esiste almeno una uguale in M1


#include <stdio.h>

int main() {
    int m1[3][3];
    int m2[3][3];

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
        int eq = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (m2[i][j] == m1[k][j]) {
                    eq = 1;
                }
            }
        }

        if (eq) {
            printf("La riga %d di m2 è uguale ad almeno una riga di m1", i + 1);
        } else {
            printf("La riga %d di m2 non è uguale ad alcuna riga di m1", i + 1);
        }
    }
}