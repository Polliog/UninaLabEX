//stampare la media dei numeri interi da 1 a 10

#include <stdio.h>

int main() {
    int s = 0;
    int c = 0;

    for (int i = 1; i <= 10; i++) {
        s = s + i;
        c = c + 1;
    }

    printf("La media è %d", s / c);
}