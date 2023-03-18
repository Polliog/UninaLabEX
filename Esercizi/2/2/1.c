//dato un vettore, stamparne un diagramma a barre fatto di * . esempio: vettore: [ 3 6 4] la stampa sarà:
//***
//******
//****

#include <stdio.h>

int main() {
    int l[4];

    printf("Inserisci gli elementi\n");
    scanf("%d %d %d %d", &l[0], &l[1], &l[2], &l[3]);

    for (int i = 0; i < 4; i++) {
        for (int x = 0; x < l[i]; x++) {
            printf("*");
        }
        printf("\n");
    }
}