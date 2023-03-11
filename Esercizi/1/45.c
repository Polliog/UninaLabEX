//dato un carattere da tastiera, determinare se è maiuscolo o minuscolo e convertirlo nel rispettivo minuscolo/maiuscolo

#include <stdio.h>

int main() {
    char c;

    printf("Inserisci un carattere\n");
    scanf("%c", &c);

    if (c >= 'A' && c <= 'Z') {
        printf("Il carattere è maiuscolo\n");
        c = c + 32;
    } else if (c >= 'a' && c <= 'z') {
        printf("Il carattere è minuscolo\n");
        c = c - 32;
    } else {
        printf("Il carattere non è una lettera\n");
        return 0;
    }

    printf("Il carattere convertito è %c", c);
}