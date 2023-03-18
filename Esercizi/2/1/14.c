//Dato un vettore, rovesciarlo in loco

#include <stdio.h>

int main() {
    int l1[4];
    int l2[4];

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l1[i]);
        l2[3-i] = l1[i];

    }

    for (int i = 0; i < 4; i++) {
        printf("%d\n", l2[i]);
    }

}