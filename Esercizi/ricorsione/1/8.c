//Dato un numero intero ≥0, fornire una funzione ricorsiva che ne restituisca la sua codifica binaria

#include <stdio.h>

int binario(int n);

int main() {
    printf("%d", binario(10));
}

int binario(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return binario(n / 2) * 10 + n % 2;
    }
}