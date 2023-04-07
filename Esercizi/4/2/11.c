//data una stringa S ed un vettore di interi V, inserire in V il numero di occorrenze di ogni carattere di S esempio: S= [ p i p p o \0 ] allora V= [ 3 1 3 3 1 ]

#include <stdio.h>

int main() {
    char s[100];
    printf("Inserisci una stringa:");
    scanf("%s", s);
    int v[26] = {0};
    int i = 0;
    while (s[i] != '\0') {
        v[s[i] - 'a']++;
        i++;
    }
    for (int j = 0; j < 26; j++) {
        printf("%d ", v[j]);
    }
    return 0;
}