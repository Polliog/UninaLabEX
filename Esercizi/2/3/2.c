//memorizzare e stamapre me somme di ogni riga di una matrice in un vettore

#include <stdio.h>

int main() {
    int m[3][3];
    int sum[3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d]", i+1,j+1);
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        int s = 0;
        for (int j = 0; j < 3; j++) {
           s += m[i][j];
        }
        sum[i] = s;
    }

    printf("Risultato: %d %d %d", sum[0], sum[1], sum[2]);
}