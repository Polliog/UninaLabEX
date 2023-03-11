//data una sequenza di 10 numeri, dire se la sequenza inserita è crescente o no (NB: l'output deve essere prodotto alla fine)

#include <stdio.h>
#include <stdbool.h>

int main() {
    int p, s;
    bool crescente = true;

    printf("Inserisci un numero:\n");
    scanf("%d", &p);

    for (int i = 0; i < 9; i++) {
        printf("Inserisci un numero:\n");
        scanf("%d", &s);

        if (s < p) {
            crescente = false;
        }

        p = s;
    }

    if (crescente) {
        printf("La sequenza è crescente");
    } else {
        printf("La sequenza non è crescente");
    }
}