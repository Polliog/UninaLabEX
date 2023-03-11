//stampare la media dei numeri interi tra a e b, con a e b dati dall'utente

#include <stdio.h>

int main() {
    int a, b;

    printf("Inserisci a:\n");
    scanf("%d", &a);
    printf("Inserisci b:\n");
    scanf("%d", &b);

    int s = 0;
    int c = 0;

    for (int i = a; i <= b; i++) {
        s = s + i;
        c = c + 1;
    }

    printf("La media è %d", s / c);
}