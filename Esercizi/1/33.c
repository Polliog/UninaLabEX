//dati due input b e h, stampa di un rettangolo fatto di * di base b e altezza h

#include <stdio.h>

int main() {
    int b,h;

    printf("Altezza?\n");
    scanf("%d", &h);
    printf("Base?\n");
    scanf("%d", &b);

    for (int i = 0; i < h; i++) {
        for (int x = 0; x < b; x++) {
            printf("*");
        }
        printf("\n");
    }
}