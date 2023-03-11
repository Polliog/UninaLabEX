//dato da tastiera due valori $n$ ed $m$, stampare $n$ A seguite da m B (es. se l'utente immette $3$ e $5$, stampare AAABBBBB)

#include <stdio.h>

int main() {
    int n, m;

    printf("Inserisci un numero:\n");
    scanf("%d", &n);
    printf("Inserisci un numero:\n");
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        printf("A");
    }

    for (int i = 0; i < m; i++) {
        printf("B");
    }
}