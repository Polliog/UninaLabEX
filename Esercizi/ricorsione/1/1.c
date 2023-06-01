//dato un vettore v=(v1,v2,…,vn), fornire una soluzione ricorsiva per stamparne i valori. Si consideri come caso base la stampa di un singolo elemento.


#include <stdio.h>

void stampa(int v[], int n);

int main() {
    int v[] = {1, 2, 3, 4, 5};
    stampa(v, 5);
}

void stampa(int v[], int n) {
    if (n == 1) {
        printf("%d\n", v[0]);
    } else {
        stampa(v, n - 1);
        printf("%d\n", v[n - 1]);
    }
}