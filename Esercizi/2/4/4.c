//Data una matrice di caratteri composta solo di O,X, _ (posizione vuota), determinate se tale matrice corrisponde ad una configurazione vincente per il gioco del Tris

#include <stdio.h>

int main() {
    char m[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d]\n", i+1,j+1);
            scanf("%c", &m[i][j]);
            getchar();
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }

    int k = 0;
    int l = 0;

    for (int i = 0; i < 3; i++) {
        if (m[i][0] == m[i][1] && m[i][1] == m[i][2]) {
            k = 1;
        }
        if (m[0][i] == m[1][i] && m[1][i] == m[2][i]) {
            l = 1;
        }
    }

    if (k || l) {
        printf("Risultato: vittoria");
    } else {
        printf("Risultato: nessuna vittoria");
    }
}