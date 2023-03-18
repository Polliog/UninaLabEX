//dati due vettori di uguale lunghezza, effettuarne la somma elemento per elemento e memorizzazione in un terzo vettore.
// Esempio: dati A = 1,2,5,3, B = 2,4,1,2 allora RIS = 3,6,6,5

#include <stdio.h>

int main() {
    int l1[4];
    int l2[4];
    int l3[4];

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l1[i]);
    }

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l2[i]);
    }

    for (int i = 0; i < 4; i++) {
        l3[i] = l1[i] + l2[i];
        printf("%d\n", l3[i]);
    }

}