//dato un vettore, calcolare i valori assoluti di tutti gli elementi contenuti al suo interno e inserirli
// in un altro vettore nelle posizioni corrispondenti.
// Esempio: dato A = -1,3,-5,-2,9 allora RIS = 1,3,5,2,9

#include <stdio.h>

int main() {
    int l[4];
    int l2[4];

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l[i]);
    }

    for (int i = 0; i < 4; i++) {
        if (l[i] < 0) {
            l2[i] = l[i] * -1;
        } else {
           l2[i] = l[i];
        }
    }
}