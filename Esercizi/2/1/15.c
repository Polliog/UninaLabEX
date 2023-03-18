//dato un vettore A di numeri interi, creare un secondo vettore B contenente:
//1, se il valore nella rispettiva posizione è multiplo di 3 o maggiore di 100,
//2, altrimenti

#include <stdio.h>

int main() {
    int l1[4];
    int l2[4];

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l1[i]);
    }

    for (int i = 0; i < 4; i++) {
        if (l1[i] > 100 || l1[i] % 3 == 0) {
            l2[i] = 1;
        } else {
            l2[i] = 2;
        }
    }
}