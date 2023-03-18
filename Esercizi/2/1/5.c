//dato un vettore, calcolare e stampare i valori assoluti di tutti gli elementi contenuti al suo interno

#include <stdio.h>

int main() {
    int l[4];

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l[i]);
    }

    for (int i = 0; i < 4; i++) {
        if (l[i] < 0) {
            printf("%d\n", l[i] * -1);
        } else {
            printf("%d\n", l[i]);
        }
    }
}