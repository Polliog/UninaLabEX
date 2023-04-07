//Data una matrice contenente, in ogni riga, una stringa, copiare in un vettore la prima lettera presente in ogni riga dopo averla convertita in maiuscolo

#include <stdio.h>

int main() {
    char s[100][100];
    char v[100];
    int i = 0;
    while (scanf("%s", s[i]) != EOF) {
        v[i] = s[i][0] - 'a' + 'A';
        i++;
    }
    for (int j = 0; j < i; j++) {
        printf("%c ", v[j]);
    }
    return 0;
}