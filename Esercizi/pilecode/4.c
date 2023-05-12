//dato un numero, stamparne la codifica binaria. Non possono essere utilizzate strutture di supporto diverse da Pile e/o Code.

#include <stdio.h>

struct Stack {
    int index_clear;
    int array[5];
};


void startStack(struct Stack *stack) {
    stack->index_clear = 0;
}

void insert(struct Stack *stack, int c) {
    stack->array[stack->index_clear] = c;
    stack->index_clear++;
}

void printBin(struct Stack *stack) {
    for (int i = stack->index_clear - 1; i >= 0; i--) {
        printf("%d", stack->array[i]);
    }
}

void decToBin(struct Stack *stack, int n) {
    while (n > 0) {
        insert(stack, n % 2);
        n = n / 2;
    }
}

int main() {
    struct Stack m;
    startStack(&m);

    decToBin(&m, 7);

    printBin(&m);
}
