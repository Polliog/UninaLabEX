#include <stdio.h>
#include <time.h>
#define RAND_MAX 32767

long int random(long int min, long int max);
double random_btw();
double random_real(double max);
double random_real_in_range(int a, int b);

int main() {
    printf("RAND_MAX: %d", RAND_MAX);

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        //non davvero randomico per renderlo randomico si mette un seme sopra
        printf("%d\n", rand());
    }

    printf("numero compreso tra 1 e 10: %ld\n", random(1, 10));
    printf("numero compreso tra 1 e 10: %ld\n", random(1, 10));
    printf("numero compreso tra 1 e 10: %ld\n", random(1, 10));

    //print random_btw number between 0 and 1
    printf("numero compreso tra 0 e 1: %f\n", random_btw());
    printf("numero compreso tra 0 e 1: %f\n", random_btw());
    printf("numero compreso tra 0 e 1: %f\n", random_btw());


    //print random real number between 0 and 10
    printf("numero compreso tra 0 e 10: %f\n", random_real(10));
    printf("numero compreso tra 0 e 10: %f\n", random_real(10));
    printf("numero compreso tra 0 e 10: %f\n", random_real(10));


    //random real in range
    printf("numero compreso tra 5 e 10: %f\n", random_real_in_range(5, 10));
    printf("numero compreso tra 5 e 10: %f\n", random_real_in_range(5, 10));
    printf("numero compreso tra 5 e 10: %f\n", random_real_in_range(5, 10));

}


//numero compreso

long int random(long int min, long int max) {
    return min + rand() % (max - min + 1);
}

//numero reale compreso tra 0 e 1
double random_btw() {
    return (double) rand() / RAND_MAX;
}

//random real in max
double random_real(double max) {
    return (double) rand() / RAND_MAX * max;
}

double random_real_in_range(int a, int b)
{

    double x = ((b - a) * ((double)rand() / RAND_MAX)) + a;
    return x;
}