//implementare una struttura dati con politica di accesso Pila con relative funzioni di accesso utilizzando come struttura una lista concatenata.

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int val;
    struct Stack *next;
};

void startStack(struct Stack **stack) {
    *stack = NULL;
}

void insert(struct Stack **stack, int val) {
    struct Stack *new = malloc(sizeof(struct Stack));
    new->val = val;
    new->next = *stack;
    *stack = new;
}

void getFromStack(struct Stack **stack, int *val) {
    struct Stack *temp = *stack;
    *val = temp->val;
    *stack = temp->next;
    free(temp);
}

int main() {
    struct Stack *m;
    startStack(&m);
    insert(&m, 8);
    insert(&m, 4);
    insert(&m, 2);
    insert(&m, 16);

    int val;
    getFromStack(&m, &val); //mi aspetto 16
    printf("%d\n", val);
    getFromStack(&m, &val); //mi aspetto 2
    printf("%d\n", val);
    getFromStack(&m, &val); //mi aspetto 4
    printf("%d\n", val);
    getFromStack(&m, &val); //mi aspetto 8
    printf("%d\n", val);
}