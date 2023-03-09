//Stampare i numeri pari da 1 a 10 in senso crescente
#include <stdio.h>

int main() {
    for (int i = 1;i<11;i++) {
        if (i % 2 == 0) {
            printf("%d ",i);
        }
    }
}