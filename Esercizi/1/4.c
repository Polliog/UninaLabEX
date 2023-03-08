//fare un programma che calcoli e stampi la media di 4 numeri interi dati dall'utente

#include <stdio.h>

int main() {
    int n1,n2,n3,n4,m;

    printf("Inserisci 4 numeri:\n");

    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    scanf("%d", &n4);


    printf("Numeri inseriti: %d %d %d %d \n", n1,n2,n3,n4);

    m = (n1+n2+n3+n4)/4;

    printf("La media e': %d", m);
}