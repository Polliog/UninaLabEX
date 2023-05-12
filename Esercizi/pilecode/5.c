///Implementare una struttura dati con politica di accesso Coda con relative funzioni di accesso utilizzando come struttura una lista concatenata.

#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int val;
    struct Queue *next;
};

void startQueue(struct Queue **queue) {
    *queue = NULL;
}

void insert(struct Queue **queue, int val) {
    struct Queue *new = malloc(sizeof(struct Queue));
    new->val = val;
    new->next = NULL;
    if (*queue == NULL) {
        *queue = new;
    } else {
        struct Queue *temp = *queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void getFromQueue(struct Queue **queue, int *val) {
    struct Queue *temp = *queue;
    *val = temp->val;
    *queue = temp->next;
    free(temp);
}

int main() {
    struct Queue *m;
    startQueue(&m);
    insert(&m, 8);
    insert(&m, 4);
    insert(&m, 2);
    insert(&m, 16);

    int val;
    getFromQueue(&m, &val); //mi aspetto 8
    printf("%d\n", val);
    getFromQueue(&m, &val); //mi aspetto 4
    printf("%d\n", val);
    getFromQueue(&m, &val); //mi aspetto 2
    printf("%d\n", val);
    getFromQueue(&m, &val); //mi aspetto 16
    printf("%d\n", val);
}