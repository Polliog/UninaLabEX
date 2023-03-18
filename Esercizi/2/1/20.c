//costruire un vettore che sia l'intersezione di 2 vettori dati (ossia mettere i soli elementi comuni tra i due vettori in un terzo vettore senza ripetizioni)

#include <stdio.h>

int main() {
    int l1[4];
    int l2[4];
    int l3[8];
    int k = 0;

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d per il primo array\n", i + 1);
        scanf("%d", &l1[i]);
    }

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d per il secondo array\n", i + 1);
        scanf("%d", &l2[i]);
    }

    for (int i = 0; i < 4; i++) {
        for (int x = 0; x < 4; x++) {
            if (l1[i] == l2[x]) {
                l3[k] = l1[i];
                k++;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%d ", l3[i]);
    }
}