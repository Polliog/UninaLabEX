//dire in che posizione si trova il primo carattere maiuscolo

#include <stdio.h>

int main() {
    char s[100];
    printf("Inserisci una stringa:");
    scanf("%s", s);
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            printf("%d", i);
            return 0;
        }
        i++;
    }
    printf("-1");
    return 0;
}