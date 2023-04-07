//Data una stringa s ed un'altra stringa q, verificare se q è una sottostringa di s

#include <stdio.h>

int main() {
    char s[100];
    char q[100];
    printf("Inserisci una stringa:");
    scanf("%s", s);
    printf("Inserisci una stringa:");
    scanf("%s", q);
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {
        if (s[i] == q[j]) {
            j++;
        } else {
            j = 0;
        }
        if (q[j] == '\0') {
            printf("La stringa q è una sottostringa di s");
            return 0;
        }
        i++;
    }
    printf("La stringa q non è una sottostringa di s");
    return 0;
}