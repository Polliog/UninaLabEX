//determinare se un carattere inserito da tastiera è una vocale

#include <stdio.h>

int main() {
    char c;

    printf("Inserisci un carattere\n");
    scanf("%c", &c);

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        printf("Il carattere è una vocale minuscola\n");
    } else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        printf("Il carattere è una vocale maiuscola\n");
    } else {
        printf("Il carattere non è una vocale\n");
    }
}