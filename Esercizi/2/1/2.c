//stampare la somma di tutti gli elementi in un vettore

#include <stdio.h>

int main() {
    int l[32];
    int s = 0;

    for (int i = 0; i < 32; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l[i]);
    }

    for (int i = 0; i < 32; i++) {
        s = s + l[i];
    }

    printf("La somma è %d", s);

}