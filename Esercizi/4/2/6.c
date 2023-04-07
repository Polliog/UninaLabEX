//contare quanti caratteri maiuscoli sono presenti in una stringa

#include <stdio.h>

int main() {
    char s[100];
    printf("Inserisci una stringa:");
    scanf("%s", s);
    int i = 0;
    int count = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            count++;
        }
        i++;
    }
    printf("%d", count);
    return 0;
}