//Stampare l'alfabeto delle minuscole invertito, ossia dalla z alla a

#include <stdio.h>

int main() {
    for (char c = 'z'; c >= 'a'; c--) {
        printf("%c", c);
    }
}