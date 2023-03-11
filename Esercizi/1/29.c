//Senza utilizzare array, date le altezze di N individui (con N inserito da tastiera), calcolare:
//A l'altezza media,
//B il numero di persone più alte di m. 1,80,
//C il numero di persone più basse di m. 1,65.

#include <stdio.h>

int main() {
    int n;
    float h = 0,b = 0,a = 0;

    printf("Quante persone ci sono?\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
         float t = 0;
         printf("Quanto e' alta la persona n %d\n", i+1);
         scanf("%f", &t);

         h += t;

         if (t > 1.80) {
             a++;
         }

         if (b < 1.65) {
             b++;
         }
    }

    printf("Altezza media: %f\n", h / n);
    printf("Persone alte: %f\n", a);
    printf("Persone basse: %f\n", b);
}