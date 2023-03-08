GNU nano 6.2                                                                                es6.c                                                                                         //fare un programma che calcoli e stampi il risultato scambio del contenuto di due variabili, stamparle prima e dopo lo
//scambio (ossia, date due variabili a e b, "spostare" in a il contenuto della variabile b ed in b il contenuto della variabile a)

#include <stdio.h>

int main() {

    int a,b,c;

    printf("Inserisci A\n");
    scanf("%d", &a);

    printf("Inserisci B\n");
    scanf("%d", &b);

    printf("A: %d\n", a);
    printf("B: %d\n", b);

    c = a;
    a = b;
    b = c;

    printf("A: %d\n", a);
    printf("B: %d\n", b);

}
