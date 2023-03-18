#include <stdio.h>

int main() {
    int l[4];
    int idx;

    printf("Inserisci gli elementi\n");
    scanf("%d %d %d %d", &l[0], &l[1], &l[2], &l[3]);

    printf("Inserisci l'indice dell'elemento da eliminare\n");
    scanf("%d", &idx);

    for (int i = idx; i < 4; i++) {
        l[i] = l[i-1];
    }

    for (int i = 0; i < 4; i++) {
        printf("%d ", l[i]);
    }
}