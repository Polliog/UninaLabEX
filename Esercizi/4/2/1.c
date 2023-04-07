//calcolare la lunghezza di una stringa senza utilizzare la funzione string length (strlen)

#include <stdio.h>

int main() {
    char s[100];
    printf("Inserisci una stringa:");
    scanf("%s", s);
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    printf("%d", i);
    return 0;
}