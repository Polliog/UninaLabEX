//Definire una struttura dati contenente interi avente una politica di accesso del tipo minimum first out, in cui il valore più piccolo contenuto è sempre il primo ad uscire.
// Provarla con un apposito main(...).

#include <stdio.h>

struct Mfo {
    int index_clear;
    int array[5];
};

void startStack(struct Mfo *stack) {
    stack->index_clear = 0;
}

void insert(struct Mfo *stack, int val) {
    stack->array[stack->index_clear] = val;
    //printf("%d\n", stack->array[stack->index_clear]);
    stack->index_clear++;
    //printf("%d\n", stack->index_clear);
}

void getFromStack(struct Mfo *stack, int *val) {
    int min = 0;
    int set = 0;
    int index = 0;

    for (int i = 0; i < stack -> index_clear; i++) {
        if (!set) {
            min = stack -> array[i];
            index = i;
            set = 1;
        } else {
            if (stack -> array[i] < min) {
                min = stack -> array[i];
                index = i;
            }
        }
    }

    //shift
    for (int i = index; i < stack -> index_clear; i++) {
        stack -> array[i] = stack -> array[i + 1];
    }

    stack -> index_clear--;

    *val = min;
}

int main() {
    struct Mfo m;
    startStack(&m);
    insert(&m, 8);
    insert(&m, 4);
    insert(&m, 2);
    insert(&m, 16);

     int val;
     getFromStack(&m, &val); //mi aspetto 2
     printf("%d\n", val);
     getFromStack(&m, &val); //mi aspetto 4
     printf("%d\n", val);
     getFromStack(&m, &val); //mi aspetto 8
     printf("%d\n", val);
     getFromStack(&m, &val); //mi aspetto 16
     printf("%d\n", val);
}