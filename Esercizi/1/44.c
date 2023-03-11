//dati da tastiera due valori $a$ e $b$, sommare tutti i numeri pari compresi, eventuali estremi inclusi, tra $a$ e $b$ (es. se l'utente immette $2$ e $7$, il risultato dovrà essere $2+4+6=12$)

#include <stdio.h>

int main() {
    int a, b;

    printf("Inserisci a:\n");
    scanf("%d", &a);
    printf("Inserisci b:\n");
    scanf("%d", &b);

    int s = 0;

    for (int i = a; i <= b; i++) {
        if (i % 2 == 0) {
            s = s + i;
        }
    }

    printf("La somma è %d", s);
}