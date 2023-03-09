//fare un programma che, dati da tastiera 3 valori dall'utente a,b ed x, stampi se x è compreso tra a e b o meno (estremi esclusi)

#include <stdio.h>

int main() {
    int a,b,x;

    printf("Inserisci a\n");
    scanf("%d", &a);
    printf("Inserisci b\n");
    scanf("%d", &b);
    printf("Inserisci x\n");
    scanf("%d", &x);


    if (x > a && x < b) {
        printf("Incluso\n");
    } else {
        printf("Escluso\n");
    }
}


