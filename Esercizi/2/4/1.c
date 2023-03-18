//verificare se un dato vettore è uguale ad una o più righe di una matrice; se sì, stampare in quali posizioni si trovano tali righe

#include <stdio.h>

int main() {
    int m[3][3];
    int v[3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d]\n", i+1,j+1);
            scanf("%d", &m[i][j]);
        }
    }
    printf("Inserisci vettore\n");
    scanf("%d %d %d", &v[0], &v[1], &v[2]);

    int e[3];
    int k = 0;

    for (int i = 0; i < 3; i++) {
        int eq = 1;
        for (int j = 0; j < 3; j++) {
            if (v[j] != m[i][j]) {
                eq = 0;
            }
        }

        if (eq) {
            e[k] = i;
            k++;
        }
    }

    if (k) {
        printf("Risultato: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", e[i]);
        }
    } else {
        printf("Risultato: nessuna riga uguale");
    }
}