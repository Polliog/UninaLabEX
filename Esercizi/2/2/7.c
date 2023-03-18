//dato un vettore ed un valore $k$, ricerca di $k$ all'interno di un vettore
// (ottimizzato, ossia il ciclo si deve fermare quando l'elemento è stato trovato, USARE UN WHILE NON UN FOR)

#include <stdio.h>

int main() {
    int l[32];
    int k;
    int found = 0;

    for (int i = 0; i < 32; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l[i]);
    }

    printf("Inserisci il numero da cercare\n");
    scanf("%d", &k);

    for (int i = 0; i < 32; i++) {
        if (l[i] == k) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Il numero è presente");
    } else {
        printf("Il numero non è presente");
    }

}