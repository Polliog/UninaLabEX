//dato un vettore, verificare se è ordinato in modo crescente.

#include <stdio.h>

int main() {
    int l[4];
    int found = 0;

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d", i+1);
        scanf("%d", &l[i]);
    }

    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            continue;
        }
        if (l[i] < l[i-1]) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("NO");
    } else {
        printf("SI");
    }

}