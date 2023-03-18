//concatenare due vettori in un terzo vettore. Esempio: dati A = 1,2,5,3, B = 2,4,1,2 allora RIS = 1,2,5,3,2,4,1,2

#include <stdio.h>

int main() {
    int l1[4];
    int l2[4];
    int l3[8];

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l1[i]);
    }

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l2[i]);
    }

    for (int i = 0; i < 4; i++) {
        l3[i] = l1[i];
    }

    for (int i = 0; i < 4; i++) {
        l3[i+4] = l2[i];
    }
}