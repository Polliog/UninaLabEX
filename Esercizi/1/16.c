//dati da tastiera 3 valori a,b e op, stampare:
//la somma di a e b se op è 1;
//la differenza tra a e b se op è 2;
//il prodotto tra a e b se op è 3;
//il quoziente tra a e b se op è 4.

#include <stdio.h>

int main() {
    int a,b,op;

    printf("Inserisci a\n");
    scanf("%d", &a);
    printf("Inserisci b\n");
    scanf("%d", &b);
    printf("Inserisci op\n");
    scanf("%d", &op);


    switch (op) {
        case 1:
            printf( "%d\n", a+b);
            break;
        case 2:
            printf("%d\n", a-b);
            break;
        case 3:
            printf("%d\n", a*b);
            break;
        case 4:
            printf("%d\n", a/b);
            break;
        default:
            printf("Operazione non valida\n");
            break;
    }
}