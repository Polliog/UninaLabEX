//usando un solo ciclo, stampare i numeri pari da 1 a 50 andando a capo ogni 5

#include <stdio.h>

int main() {
    for (int i = 1; i < 51; i++) {
        if (i % 5 == 0) {
            printf("%d\n", i);
        } else {
            printf("%d ", i);
        }
    }
}