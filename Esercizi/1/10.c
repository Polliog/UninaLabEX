//fare un programa che stampi se un numero dato in input è pari o dispari (se è dispari stampare DISPARI, se è pari stampare PARI)

#include <stdio.h>

int main() {

    int n;

    printf("Inserisci un numero\n");

    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Il numero e' pari\n");
    } else {
        printf("Il numero e' dispari\n");
    }

}











