//dati due input b e h, stampa di un rettangolo di * di base b e altezza h avente sulla diagonale secondaria il carattere #

#include <stdio.h>

int main() {
    int b, h;

    printf("Altezza?\n");
    scanf("%d", &h);
    printf("Base?\n");
    scanf("%d", &b);


    for (int i = 0; i < h; i++) {
        for (int x = 0; x < b; x++) {
            if ( (b - x - 1) == i) {
                printf("#");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}