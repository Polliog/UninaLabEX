//inserisci la variabile k nella posizione x nell'array senza rimuovere nessun elemento

#include <stdio.h>

int main() {
    int x = 5;
    int k = 69;
    int v[11] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 10; i >= x; i--) {
        v[i] = v[i - 1];
    }

    v[x] = k;

    for (int i = 0; i < 11; i++) {
        printf("%d ", v[i]);
    }
}
