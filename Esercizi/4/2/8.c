//contare quanti vocali e consonanti sono presenti in una stringa

#include <stdio.h>

int main() {
    char s[100];
    printf("Inserisci una stringa:");
    scanf("%s", s);
    int i = 0;
    int countVocali = 0;
    int countConsonanti = 0;
    while (s[i] != '\0') {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            countVocali++;
        } else {
            countConsonanti++;
        }
        i++;
    }
    printf("Vocali: %d Consonanti: %d", countVocali, countConsonanti);
    return 0;
}