//verificare se una stringa è palindroma

#include <stdio.h>

int main() {
    char s[100];
    printf("Inserisci una stringa:");
    scanf("%s", s);
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    int j = 0;
    while (j < i / 2) {
        if (s[j] != s[i - j - 1]) {
            printf("La stringa non è palindroma");
            return 0;
        }
        j++;
    }
    printf("La stringa è palindroma");
    return 0;
}