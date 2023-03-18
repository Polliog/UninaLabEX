//data una matrice, scrivere un programma che determini qual è la colonna col maggior numero di elementi pari. Stamparne quindi l'indice

#include <stdio.h>

int main() {
    int m[3][3];
    int max = 0;
    int maxIndex = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d]", i+1,j+1);
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        int count = 0;
        for (int j = 0; j < 3; j++) {
            if (m[j][i] % 2 == 0) {
                count++;
            }
        }
        if (count > max) {
            max = count;
            maxIndex = i;
        }
    }

    printf("La colonna con più numeri pari è %d", maxIndex+1);
}