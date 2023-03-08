//date le coordinate $P_1=(x_1,y_1)$ e $P_2=(x_2,y_2)$ di due punti,
// fare un programma che ne calcoli la distanza euclidea
// (si ricorda che la distanza euclidea tra due punti è pari a $d(P_1,P_2)=\sqrt{(x_1-x_2)^2+(y_1-y_2)^2}$

#include <stdio.h>
#include <math.h>

int main() {
    int x1,x2,y1,y2,d;

    printf("Inserire x1:\n");
    scanf("%d", &x1);

    printf("Inserire y1:\n");
    scanf("%d", &y1);

    printf("Inserire x2:\n");
    scanf("%d", &x2);

    printf("Inserire y2:\n");
    scanf("%d", &y2);

    d = sqrt(pow((x1-x2),2)+pow((y1-y2),2));

    printf("La distanza e' %d \n", d);
}