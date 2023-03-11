//dato da tastiera un valore $n$, stampare $n$ A alternate ad $n$ B (es. se l'utente immette $3$, stampare ABABABA)

#include <stdio.h>

int main() {
    int n;

    printf("Inserisci un numero: ");

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("A");
        printf("B");
    }
}