//dato un vettore A di numeri interi, creare un secondo vettore B contenente solo i valori di A che siano compresi tra 10 e 20

#include <stdio.h>

int main() {
    int l1[4];
    int l2[4];
    int k = 0;

    for (int i = 0; i < 4; i++) {
        printf("Inserisci il numero n %d\n", i+1);
        scanf("%d", &l1[i]);
    }

    for (int i = 0; i < 4; i++) {
        if (l1[i] > 10 && l1[i] < 20) {
            l2[k] = l1[i];
            k++;
        }
    }
}