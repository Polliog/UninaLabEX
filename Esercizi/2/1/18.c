//dato due vettori di numeri A e B, inserire in una variabile T il valore:
//1, se i due vettori sono uguali (es. A= [1 4 5] e B= [1 4 5])
//2, se sono uno il "reverse" dell'altro (es. A= [1 4 5] e B= [5 4 1])
//3, tutti gli altri casi.

#include <stdio.h>

int main() {
    int l1[4];
    int l2[4];
    int t = 0;

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l1[i]);
    }

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l2[i]);
    }

    for (int i = 0; i < 4; i++) {
        if (l1[i] != l2[i]) {
            t = 3;
            break;
        }
    }

    if (t == 0) {
        t = 1;
        return printf("%d", t);
    }

    t = 0;

    for (int i = 0; i < 4; i++) {
        if (l1[i] != l2[3-i]) {
            t = 3;
            break;
        }
    }

    if (t == 0) {
        t = 2;
        return printf("%d", t);
    }

    printf("%d", t);
}