//trasformazione stringa minuscola in maiuscola

#include <stdio.h>

int main() {
    char s[100];
    printf("Inserisci una stringa:");
    scanf("%s", s);
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
        i++;
    }
    printf("%s", s);
    return 0;
}