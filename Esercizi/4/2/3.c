//implementare funzione string compare senza utilizzare quella già presente (strcmp)

#include <stdio.h>

int main() {
    char s1[100];
    char s2[100];
    printf("Inserisci una stringa:");
    scanf("%s", s1);
    printf("Inserisci una stringa:");
    scanf("%s", s2);
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            printf("Le stringhe sono diverse");
            return 0;
        }
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') {
        printf("Le stringhe sono uguali");
    } else {
        printf("Le stringhe sono diverse");
    }
    return 0;
}