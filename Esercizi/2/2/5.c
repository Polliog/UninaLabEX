//dato un vettore, eliminarne i duplicati tramite shift

#include <stdio.h>

int main() {
    int l[4];

    printf("Inserisci gli elementi\n");
    scanf("%d %d %d %d", &l[0], &l[1], &l[2], &l[3]);

    for (int i = 0; i < 4; i++) {
        for (int x = i+1; x < 4; x++) {
            if (l[i] == l[x]) {
                for (int y = x; y < 4; y++) {
                    l[y] = l[y+1];
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("%d ", l[i]);
    }
}