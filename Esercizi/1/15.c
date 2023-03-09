//fare un programma che, dato un voto di esame da tastiera, stampi promosso se maggiore o uguale di 18, bocciato in caso contrario

#include <stdio.h>

int main() {
    int v;

    printf("Inserisci un voto\n");

    scanf("%d", &v);

    if (v < 18) {
        printf("Bocciato :(");
    } else {
        printf("Promosso :)");
    }
}