//fare un programa che, dati in input 3 valori a,b ed x, stampi se x è compreso tra a e b o meno (estremi inclusi)

#include <stdio.h>

int main() {
    int a,b,x;

    printf("Inserisci a\n");
    scanf("%d", &a);
    printf("Inserisci b\n");
    scanf("%d", &b);
    printf("Inserisci x\n");
    scanf("%d", &x);


    if (x >= a && x <= b) {
        printf("Incluso\n");
    } else {
        printf("Escluso\n");
    }
}

