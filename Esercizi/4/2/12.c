//scrivere un programma che stampi video la domanda cos'è un file .h? e, se l'utente risponde con una stringa contenente la parola libreria, il programma stampa bocciato, altrimenti Ok. Andiamo avanti.

#include <stdio.h>

int main() {
    printf("Cos'è un file .h?");
    char s[100];
    scanf("%s", s);
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == 'l' && s[i + 1] == 'i' && s[i + 2] == 'b' && s[i + 3] == 'r' && s[i + 4] == 'e' && s[i + 5] == 'r' && s[i + 6] == 'i' && s[i + 7] == 'a') {
            printf("Bocciato");
            return 0;
        }
        i++;
    }
    printf("Ok. Andiamo avanti.");
    return 0;
}

