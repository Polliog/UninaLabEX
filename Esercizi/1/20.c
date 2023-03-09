//Stampare i numeri pari da 1 a 10 in modo decrescente

#include <stdio.h>

int main() {
    for (int i = 11;i>0;i--) {
        if (i % 2 == 0) {
            printf("%d ",i);
        }
    }
}