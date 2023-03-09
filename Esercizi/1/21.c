//stampare i numeri da 1 a 50 separati da uno spazio e andando a capo ogni 10

#include <stdio.h>

int main() {
    for (int i = 1; i < 51; i++) {
        if (i % 10 == 0) {
            printf("%d\n", i);
        } else {
            printf("%d ", i);
        }
    }
}