//
//Dati due vettori v,w∈Rn
//, fornire una soluzione ricorsiva per il calcolo del loro prodotto scalare


#include <stdio.h>

int prodottoScalare(int v[], int w[], int n);

int main() {
    int v[] = {1, 2, 3, 4, 5};
    int w[] = {1, 2, 3, 4, 5};
    printf("%d", prodottoScalare(v, w, 5));
}

int prodottoScalare(int v[], int w[], int n) {
    if (n == 1) {
        return v[0] * w[0];
    } else {
        return v[n - 1] * w[n - 1] + prodottoScalare(v, w, n - 1);
    }
}