//calcolare la media di una serie di valori inseriti da tastiera (serie terminante con 0)

#include <stdio.h>

int main() {
    int n, t;

    printf("Inserisci un numero:\n");
    scanf("%d", &n);

    int s = 0;
    int c = 0;

    while (n != 0) {
        s = s + n;
        c = c + 1;

        printf("Inserisci un numero:\n");
        scanf("%d", &n);
    }

    printf("La media è %d", s / c);
}