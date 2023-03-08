//dati in input i coefficienti $m$ e $q$ ed un valore $y$,
// fare un programma che risolva la corrispondente equazione di primo grado in forma normale
// (ossia, considerando l'equazione $y=mx+q$, dati i valori di $m$,$q$ ed $y$, calcolare stampare il valore di $x$)

#include <stdio.h>

int main() {
    int y,m,q,x;

    printf("Inserire il valore di y:\n");
    scanf("%d", &y);

    printf("Inserire il valore di m:\n");
    scanf("%d", &m);

    printf("Inserire il valore di q:\n");
    scanf("%d", &q);

    x = (y-q)/m;

    printf("Il valore di x e' %d \n", x);
}