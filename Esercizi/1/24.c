//calcolo potenza di un numero (dati due numeri $a$ e $b$, calcolare $a^b$)

#include <stdio.h>

int main() {
    int a, b;

    printf("Inserisci A\n");
    scanf("%d", &a);


    printf("Inserisci B\n");
    scanf("%d", &b);

    int c = 1;

    for (int i = 0; i < b; i++) {
        c = c * a;
    }

    printf("%d", c);

}