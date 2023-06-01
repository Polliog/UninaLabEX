//Data una lista concatenata contenente valori interi, scrivere una funzione ricorsiva che ne elimini tutti i nodi avente valore pari a k, con k fornito dall'utente

#include <stdio.h>

struct nodo {
    int valore;
    struct nodo *next;
};

void stampa(struct nodo *head);

void elimina(struct nodo *head, int k);

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
    elimina(head, 2);
    stampa(head);
}


void stampa(struct nodo *head) {
    if (head == NULL) {
        return;
    } else {
        printf("%d\n", head->valore);
        stampa(head->next);
    }
}

void elimina(struct nodo *head, int k) {
    if (head == NULL) {
        return;
    } else {
        if (head->valore == k) {
            head = head->next;
            elimina(head, k);
        } else {
            elimina(head->next, k);
        }
    }
}


