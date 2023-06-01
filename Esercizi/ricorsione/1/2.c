//dato un vettore v=(v1,v2,…,vn), fornire una soluzione ricorsiva per stamparne i valori partendo dall'ultimo al primo. Si consideri come caso base la stampa di un singolo elemento.

#include <stdio.h>

void stampa(int v[], int n) {
    if (n == 1) {
        printf("%d\n", v[n - 1]);
    } else {
        printf("%d\n", v[n - 1]);
        stampa(v, n - 1);
    }
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    stampa(v, 5);
}