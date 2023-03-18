//dato un vettore X , calcolare la somma S di ogni numero elevato alla rispettiva posizione. Esempio: X = [3 5 2 7] allora S=3^1+5^2+2^3+7^4

#include <stdio.h>

int pwr(int v, int e) {
    int r = 1;
    for (int i = 0; i < e; i++) {
        r *= v;
    }
    return r;
}

int main() {
    int x[4];

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d ", i + 1);
        scanf("%d", &x[i]);
    }

    int s = 0;

    for (int i = 0; i < 4; i++) {
        s += pwr(x[i], i + 1);
    }

    printf("La somma è %d", s);
}