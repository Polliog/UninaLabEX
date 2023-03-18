//ricerca di un elemento k dato dall'utente all'interno di una matrice. Se presente, visualizzare l'indice di riga e di colonna in cui si trova

#include <stdio.h>

int main() {
    int m[3][3];
    int k;
    int found = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Inserisci [%d;%d]", i+1,j+1);
            scanf("%d", &m[i][j]);
        }
    }

    printf("Inserisci il numero da cercare\n");
    scanf("%d", &k);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (m[i][j] == k) {
                found = 1;
                printf("Il numero è presente in [%d;%d]", i+1, j+1);
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        printf("Il numero non è presente");
    }

}