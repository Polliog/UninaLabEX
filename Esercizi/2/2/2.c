//dato un vettore A ed un vettore B di lunghezza = alla lunghezza di A, determinare se il vettore B è un sottovettore di A
// (ossia se esiste una sequenza di elementi in A uguale all'intera sequenza di elementi in B)

#include <stdio.h>

int main() {
    int l1[4];
    int l2[4];
    int k = 0;

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l1[i]);
    }

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l2[i]);
    }

    for (int i = 0; i < 4; i++) {
        if (l1[i] == l2[0]) {
            for (int x = 0; x < 4; x++) {
                if (l1[i+x] == l2[x]) {
                    k++;
                }
            }
        }
    }

    if (k == 4) {
        printf("Il vettore B è un sottovettore di A");
    } else {
        printf("Il vettore B non è un sottovettore di A");
    }
}