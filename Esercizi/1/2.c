//date base e altezza da input, scrivere un programma che calcoli e stampi l'area di un triangolo
#include <stdio.h>

int main() {
    int b,h,s;

    printf("Inserire base:\n");
    scanf("%d", &b);

    printf("Inserire altezza:\n");
    scanf("%d", &h);

    s = (b * h)/2;

    printf("La superficie totale e' %d \n", s);
}