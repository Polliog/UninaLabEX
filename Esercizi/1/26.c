//Inserendo 10 numeri interi, calcolare e stampare quanti numeri pari sono stati inseriti


#include <stdio.h>

int main() {
    int n = 0, p = 0;

    for (int i = 0; i < 10; i++) {
        printf("Inserisci il numero n: %d\n", i + 1);
        scanf("%d", &n);

        if (n % 2 == 0) {
            p++;
        }
    }

    printf("Hai inserito %d numeri pari", p);
}