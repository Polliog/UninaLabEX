//effettuare la copia di una stringa in un'altra senza utilizzare funzione string copy (strcpy)

#include <stdio.h>

int main() {
    char s[100];
    printf("Inserisci una stringa:");
    scanf("%s", s);
    char s2[100];
    int i = 0;
    while (s[i] != '\0') {
        s2[i] = s[i];
        i++;
    }
    s2[i] = '\0';
    printf("%s", s2);
    return 0;
}