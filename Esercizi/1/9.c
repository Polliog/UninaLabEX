//dati i coefficienti in tre variabili $a$,$b$,$c$ in input ed un valore $x$, risolvere un'equazione di
// secondo grado in forma normale (ossia, considerando l'equazione $ax^2+bx+c=0$, dati i valori di $a,b,c$ in input,
// calcolare e stampare i corrispondenti valori di $x$)

#include <stdio.h>
#include <math.h>

int main() {
  double a,b,c,x1,x2;

    printf("Inserisci a\n");
    scanf("%lf", &a);

    printf("Inserisci b\n");
    scanf("%lf", &b);

    printf("Inserisci c\n");
    scanf("%lf", &c);


    x1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
    x2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);


    printf("x1: %lf\n", x1);
    printf("x2: %lf\n", x2);
}