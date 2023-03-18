//effettuare somma di tutti gli elementi di una matrice

#include <stdio.h>

int main() {
    int l[4][4];
    int sum = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci il numero n %d", i+1);
            scanf("%d", &l[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += l[i][j];
        }
    }

    printf("La somma è %d", sum);
}