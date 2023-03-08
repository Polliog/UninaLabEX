//dato il raggio da input, scrivere un programma che calcoli e stampi area e perimetro di un cerchio

#include <stdio.h>

int main() {
    int r,s,p;

    printf("Inserire il raggio:\n");
    scanf("%d", &r);

    s = 3.14 * r * r;

    printf("La superficie totale e' %d \n", s);

    p = 2 * 3.14 * r;

    printf("Il perimetro totale e' %d \n", p);
}