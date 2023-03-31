//implementare una funzione che accetta un vettore, restituire due variabili, la prima contenente il numero di elementi pari presenti nel vettore e la seconda il numero di elementi dispari (utilizzare il passaggio di parametri tramite puntatore per restituire i risultati)

#include <stdio.h>
#define MAX_DIM 8

void checkArray(int[MAX_DIM], int*,int*);

int main() {
    int v[MAX_DIM] = {
            24,32,6,5,3,11,7
    };

    int np = 0, nd = 0;
    int *np_p, *nd_p;
    np_p = &np;
    nd_p = &nd;

    checkArray(v,np_p,nd_p);
    printf("%d %d", np, nd);
    return 0;
}

void checkArray(int *v, int *np, int *nd) {
    for (int i = 0; i < MAX_DIM -1; i++) {
        if (*(v + i) % 2 == 0) {
            *np += 1;
        } else {
            *nd += 1;
        }
    }
}