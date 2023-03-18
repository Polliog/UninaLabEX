//costruire un vettore che sia l'unione di 2 vettori dati (ossia mettere gli elementi dei due vettori in un terzo vettore senza ripetizioni)
//senza ripetizioni

#include <stdio.h>

int main() {
    int l1[4];
    int l2[4];
    int l3[8];
    int k = 0;


    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d per il primo array\n", i+1);
        scanf("%d", &l1[i]);
        printf("Inserisci il numero n %d per il secondo array\n", i+1);
        scanf("%d", &l2[i]);
    }

    for (int i = 0; i < 4; i++) {
        int found = 0;

        for (int x = 0; x < k; x++) {
            if (l3[x] == l1[i]) {
                found = 1;
            }
        }

        if (!found) {
            l3[k] = l1[i];
            k++;
        }
    }

    for (int i = 0; i < 4; i++) {
        int found = 0;

        for (int x = 0; x < k; x++) {
            if (l3[x] == l2[i]) {
                found = 1;
            }
        }

        if (!found) {
            l3[k] = l2[i];
            k++;
        }
    }



    for (int i = 0; i < k; i++) {
        printf("%d\n", l3[i]);

    }
}