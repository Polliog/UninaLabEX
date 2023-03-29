#include <stdio.h>
int main() {
    int a, b;
    a = 5;
    b = 7;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    printf("%d %d", a, b);
}