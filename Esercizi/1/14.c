//fare un programa che calcoli e stampi il massimo tra 3 valori dati dall'utente in 3 variabili distinte

#include <stdio.h>

int main() {
    int a,b,c,m;

    printf("Inserisci a\n");
    scanf("%d", &a);

    m = a;

    printf("Inserisci b\n");
    scanf("%d", &b);

    if (b > m) {
        m = b;
    }

    printf("Inserisci c\n");
    scanf("%d", &c);

    if (c > m) {
        m = c;
    }

    printf("Il massimo e': %d", m);



}