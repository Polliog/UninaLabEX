//copiare gli elementi pari e dispari di un vettore in 2 vettori differenti

#include <stdio.h>

int main() {
    int l[32];
    int l2[32];
    int l3[32];
    int j = 0;
    int k = 0;

    for (int i = 0; i < 32; i++) {
        printf("Inserisci il numero n %d", i+1);
        scanf("%d", &l[i]);
    }

    for (int i = 0; i < 32; i++) {
        if (l[i] % 2 == 0) {
            l2[j] = l[i];
            j++;
        } else {
            l3[k] = l[i];
            k++;
        }
    }
}

