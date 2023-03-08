//fare un programma che calcoli e stampi la media pesata di 4 numeri interi e 4 pesi reali dati dall'utente

#include <stdio.h>

int main() {
    int n1,n2,n3,n4;
    float p1,p2,p3,p4,m;

    printf("Inserisci 4 numeri:\n");

    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    scanf("%d", &n4);

    printf("Inserisci 4 pesi:\n");

    scanf("%f", &p1);
    scanf("%f", &p2);
    scanf("%f", &p3);
    scanf("%f", &p4);

    printf("Numeri inseriti: %d %d %d %d \n", n1,n2,n3,n4);
    printf("Pesi inseriti: %f %f %f %f \n", p1,p2,p3,p4);

    m = ((n1*p1)+(n2*p2)+(n3*p3)+(n4*p4))/(p1+p2+p3+p4);

    printf("La media e': %f", m);
}
