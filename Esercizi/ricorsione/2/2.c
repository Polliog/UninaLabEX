//Data una lista concatenata L
//, proporre una soluzione ricorsiva che ne stampi tutti i valori dall'ultimo al primo

#include <stdio.h>

struct nodo {
    int valore;
    struct nodo *next;
};

void stampa(struct nodo *head);

int main() {
    struct nodo *head = NULL;
    struct nodo *second = NULL;
    struct nodo *third = NULL;

    head = malloc(sizeof(struct nodo));
    second = malloc(sizeof(struct nodo));
    third = malloc(sizeof(struct nodo));

    head->valore = 1;
    head->next = second;

    second->valore = 2;
    second->next = third;

    third->valore = 3;
    third->next = NULL;

    stampa(head);
}

void stampa(struct nodo *head) {
    if (head == NULL) {
        return;
    } else {
        stampa(head->next);
        printf("%d\n", head->valore);
    }
}