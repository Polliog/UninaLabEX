//dato un vettore stampare UGUALI se tutti gli elementi contenuti al suo interno sono tra loro uguali,
// NO se ne esiste anche soltanto uno diverso (versione NON ottimizzata,
// ossia attraverso un ciclo for (o while) che scorre il vettore fino alla fine)

#include <stdio.h>

int main() {
    int l[32];
    int found = 0;

    for (int i = 0; i < 32; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l[i]);
    }

    for (int i = 0; i < 32; i++) {
        if (l[i] != l[0]) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("NO");
    } else {
        printf("UGUALI");
    }

}
