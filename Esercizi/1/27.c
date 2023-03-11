//calcolo media di n valori inseriti da tastiera (con n inserito da input, NB: non usare array)

#include <stdio.h>

int main() {
    int n;
    printf("Inserisci un numero:\n");
    scanf("%d", &n);

    int s = 0;

    for (int i = 0; i < n; i++) {
        int a;
        printf("Inserisci il numero n: %d\n", i + 1);
        scanf("%d", &a);

        s = s + a;
    }

    printf("La media è %d", s / n);
}