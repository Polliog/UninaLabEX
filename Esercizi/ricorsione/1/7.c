//Dato un numero intero ≥0, fornire una funzione ricorsiva che ne stampi la sua codifica binaria


#include <stdio.h>

void binario(int n);

int main() {
    binario(10);
}

void binario(int n) {
    if (n == 0) {
        printf("0");
    } else if (n == 1) {
        printf("1");
    } else {
        binario(n / 2);
        printf("%d", n % 2);
    }
}