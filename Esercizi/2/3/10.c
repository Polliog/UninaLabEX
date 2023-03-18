//data una matrice, inserire gli indici di riga e di colonna di tutti gli elementi negativi in due vettori distinti, il primo contenente le posizioni di riga ed il secondo le posizioni di colonna

#include <stdio.h>

int main() {
    int m[3][3];
    int l[3];
    int l2[3];
    int j = 0;
    int k = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d]", i+1,j+1);
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (m[i][j] < 0) {
                l[j] = i;
                l2[j] = j;
                j++;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%d %d ", l[i], l2[i]);
}