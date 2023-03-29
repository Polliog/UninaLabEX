// dato un vettore ordinato e un indice i rimuovi l'elemento in posizione i

#include <stdio.h>

int main() {
    int x = 5;
    int v[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = x; i >= 0; i--) {
        v[i] = v[i - 1];
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
}