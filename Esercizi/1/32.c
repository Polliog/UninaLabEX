//ripetere l'esercizio precedente usando due cicli invece di uno


#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        for (int x = 0; x < 10; x++) {
            printf("*");
        }
        printf("\n");
    }
}
