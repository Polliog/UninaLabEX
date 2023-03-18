#include <stdio.h>
#include <stdlib.h>

int main() {

    int **matrice;

    int i, j;
    int colonne, righe;

    printf("righe da allocare:\n");
    scanf("%d", &righe);

    printf("colonne da allocare:\n");
    scanf("%d", &colonne);

    matrice = malloc(righe * colonne);


    for (i = 0; i < righe; i++)
        matrice[i] = malloc(colonne);


    for (i = 0; i < righe; i++)
        for (j = 0; j < colonne; j++) {
            printf("Elemento: [%d] [%d]\n", i + 1, j + 1);
            scanf("%d", &matrice[i][j]);
        }


    for (i = 0; i < righe; i++)
        for (j = 0; j < colonne; j++)
            printf("Elemento:  [%d] [%d] : %d\n", i + 1, j + 1, matrice[i][j]);

}