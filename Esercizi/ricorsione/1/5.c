//data una stringa s, fornire una soluzione ricorsiva per la verifica che s sia palindroma

#include <stdio.h>

int palindroma(char s[], int n);

int main() {
    char s[] = "anna";
    printf("%d", palindroma(s, 4));
}

int palindroma(char s[], int n) {
    if (n == 1) {
        return 1;
    } else {
        if (s[0] == s[n - 1]) {
            return palindroma(s + 1, n - 2);
        } else {
            return 0;
        }
    }
}