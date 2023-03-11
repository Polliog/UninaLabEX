//dato un input n, stampa di un triangolo Fatto di * iniziante con un * e terminante con n *

#include <stdio.h>

int main() {
    int n;

    printf("Inserisci un numero:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int x = 0; x < i + 1; x++) {
            printf("*");
        }
        printf("\n");
    }
}