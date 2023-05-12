//Data una stringa $s$, verificare se la stringa è palindroma. Gli elementi di $s$ potranno essere letti/scritti solo ed esclusivamente dal primo all'ultimo.
// Non possono essere utilizzate strutture di supporto diverse da Pile e/o Code.

//aerea

#include <stdio.h>

struct Stack {
    int index_clear;
    char array[5];
};


void startStack(struct Stack *stack) {
    stack->index_clear = 0;
}

void insert(struct Stack *stack, char c) {
    stack->array[stack->index_clear] = c;
    stack->index_clear++;
}

void checkPalindromo(struct Stack *stack) {
    int i = 0;
    int j = stack->index_clear - 1;
    while (i < j) {
        if (stack->array[i] != stack->array[j]) {
            printf("La stringa non è palindroma");
            return;
        }
        i++;
        j--;
    }
    printf("La stringa è palindroma");
}

int main() {
    struct Stack m;
    startStack(&m);

    insert(&m, 'a');
    insert(&m, 'e');
    insert(&m, 'r');
    insert(&m, 'e');
    insert(&m, 'a');


    checkPalindromo(&m);
}