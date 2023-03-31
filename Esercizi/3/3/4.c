//Dato in input un vettore v, scrivere una funzione che restituisca un vettore riassunto di 3 elementi dove:
//
//il primo elemento punta al minimo di v
//
//. Se tale valore è presente più volte, si desidera che l'elemento punti alla prima occorrenza;
//il secondo elemento punta al massimo di v
//. Se tale valore è presente più volte, si desidera che l'elemento punti all'ultima occorrenza;
//il terzo elemento punta all'ultima occorrenza del valore più frequente nel vettore v

#include <stdio.h>

#define MAX_DIM 8

void checkArray(int[MAX_DIM], int*,int*,int*);

int main() {
    int v[MAX_DIM] = {
            24,32,6,5,3,11,7
    };

    int min, max, mf;
    int *min_p, *max_p, *mf_p;
    min_p = &min;
    max_p = &max;
    mf_p = &mf;

    checkArray(v,min_p,max_p,mf_p);
    printf("%d %d %d", min, max, mf);
    return 0;
}

void checkArray(int *v, int *min, int *max, int *mf) {
    int max_f = 0;
    for (int i = 0; i < MAX_DIM -1; i++) {
        if (*(v + i) < *min) {
            *min = *(v + i);
        }
        if (*(v + i) > *max) {
            *max = *(v + i);
        }
        int f = 0;
        for (int j = 0; j < MAX_DIM -1; j++) {
            if (*(v + i) == *(v + j)) {
                f++;
            }
        }
        if (f > max_f) {
            max_f = f;
            *mf = *(v + i);
        }
    }
}

