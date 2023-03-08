//date base e altezza da input, scrivere un programma che calcoli e stampi l'area ed il perimetro di un rettangolo

#include <stdio.h>

int main() {
    int l1,l2,s,p;

    printf("Inserire la lunghezza del primo lato:\n");
    scanf("%d", &l1);

    printf("Inserire la lunghezza del secondo lato:\n");
    scanf("%d", &l2);

    s = l1 * l2;

    printf("La superficie totale e' %d \n", s);

    p = (l1 * 2) + (l2 * 2);

    printf("Il perimetro totale e' %d \n", p);
}