#include <stdio.h>

//ricerca binaria o ricerca dicotomica

int main() {
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int x = 5;

    int min = 0;
    int max = n - 1;
    int mid = (min + max) / 2;

    while (min <= max) {
        if (v[mid] == x) {
            printf("trovato in posizione %d", mid);
            return 0;
        } else if (v[mid] < x) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
        mid = (min + max) / 2;
    }

    printf("non trovato");
}