//far acquisire all'utente due numeri in due variabili di tipo float ed un simbolo in una variabile di tipo char; se la
// variabile di tipo char ha al suo interno il simbolo '+', stampare la somma delle due variabili, se invece ha al suo
// interno il simbolo '-', stampare la differenza delle due variabili, in tutti gli altri casi stampare "non posso farlo"

#include <stdio.h>

int main() {
    float a, b;
    char c;

    printf("Inserisci un numero:\n");
    scanf("%f", &a);
    printf("Inserisci un numero:\n");
    scanf("%f", &b);
    printf("Inserisci un simbolo:\n");
    scanf(" %c", &c);

    if (c == '+') {
        printf("La somma è %f", a + b);
    } else if (c == '-') {
        printf("La differenza è %f", a - b);
    } else {
        printf("Non posso farlo");
    }
}