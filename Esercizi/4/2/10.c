//data una stringa e due variabili carattere C1 e C2, sostituire nella stringa tutte le occorrenze di C1 con C2

#include <stdio.h>

int main() {
    char s[100];
    printf("Inserisci una stringa:");
    scanf("%s", s);
    char c1, c2;
    printf("Inserisci il primo carattere:");
    scanf(" %c", &c1);
    printf("Inserisci il secondo carattere:");
    scanf(" %c", &c2);
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == c1) {
            s[i] = c2;
        }
        i++;
    }
    printf("%s", s);
    return 0;
}