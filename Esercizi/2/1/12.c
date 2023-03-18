//dato un vettore e date due variabili contenenti due indici di posizione,scambiare gli elementi nelle posizioni date

#include <stdio.h>

int main() {
    int l[4];
    int a;
    int b;
    int c;

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l[i]);
    }

    printf("Inserisci il primo indice da scambiare\n");
    scanf("%d", &a);
    printf("Inserisci il secondo indice da scambiare\n");
    scanf("%d", &b);

    c = l[a];
    l[a] = l[b];
    l[b] = c;

    for (int i = 0; i < 4; i++) {
        printf("%d\n", l[i]);
    }
}