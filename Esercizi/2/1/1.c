//determinare il minimo (massimo) presente in un vettore e stamparne a video sia valore che la posizione in cui si trova.
// Esempio: dato A = 1,3,5,-2,4,0,6 allora stampa il minimo è -2 e la posizione in cui si trova è 3

#include <stdio.h>

int main() {
    int idx;
    int val = 0;

    int l[32];

    for (int i = 0; i < 32; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l[i]);
    }


    for (int i = 0; i < 32; i++) {
        if (l[i] < val) {
            val = l[i];
            idx = i;
        }
    }

    printf("Il minimo è %d e si trova in posizione %d", val, idx);

}