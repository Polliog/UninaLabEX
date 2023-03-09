//fare un programa che, dato da tastiera un numero reale, ne calcoli e ne stampi il valore assoluto

#include <stdio.h>

int main() {

        float n;

        printf("Inserisci un numero reale\n");

        scanf("%f", &n);

        if (n < 0) {
            n = -n;
        }

        printf("Il valore assoluto e' %f\n", n);
}