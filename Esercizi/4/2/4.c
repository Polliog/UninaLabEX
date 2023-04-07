//verificare se una stringa è composta da soli caratteri maiuscoli

#include <stdio.h>

int main() {
    char s[100];
    printf("Inserisci una stringa:");
    scanf("%s", s);
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] < 'A' || s[i] > 'Z') {
            printf("La stringa non è composta da soli caratteri maiuscoli");
            return 0;
        }
        i++;
    }
    printf("La stringa è composta da soli caratteri maiuscoli");
    return 0;
}