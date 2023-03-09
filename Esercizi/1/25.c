//calcolo fattoriale di un numero (dato un numero $a$, calcolare $a!$)

#include <stdio.h>

int main() {
    int a;

    printf("Inserisci A:\n");
    scanf("%d", &a);

    int c = 1;

    for (int i = 1; i <= a; i++) {
        c = c * i;
    }

    printf("%d", c);
}