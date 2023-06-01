//Data una lista concatenata in cui ogni nodo contiene un numero di telefono codificato in forma di vettore di interi, scrivere una funzione ricorsiva che elimini dalla lista tutti i numeri di telefono che non iniziano con prefisso 081.
//Stampare la lista risultante.

#include <stdio.h>

struct nodo {
    int valore[10];
    struct nodo *next;
};

void stampa(struct nodo *head);

void elimina(struct nodo *head);

int main() {
    struct nodo *head = NULL;
    struct nodo *second = NULL;
    struct nodo *third = NULL;

    head = malloc(sizeof(struct nodo));
    second = malloc(sizeof(struct nodo));
    third = malloc(sizeof(struct nodo));

    head->valore[0] = 0;
    head->valore[1] = 8;
    head->valore[2] = 1;
    head->valore[3] = 2;
    head->valore[4] = 3;
    head->valore[5] = 4;
    head->valore[6] = 5;
    head->valore[7] = 6;
    head->valore[8] = 7;
    head->valore[9] = 8;
    head->next = second;

    second->valore[0] = 0;
    second->valore[1] = 8;
    second->valore[2] = 1;
    second->valore[3] = 2;
    second->valore[4] = 3;
    second->valore[5] = 4;
    second->valore[6] = 5;
    second->valore[7] = 6;
    second->valore[8] = 7;
    second->valore[9] = 8;
    second->next = third;

    third->valore[0] = 0;
    third->valore[1] = 8;
    third->valore[2] = 1;
    third->valore[3] = 2;
    third->valore[4] = 3;
    third->valore[5] = 4;
    third->valore[6] = 5;
    third->valore[7] = 6;
    third->valore[8] = 7;
    third->valore[9] = 8;
    third->next = NULL;

    stampa(head);
    elimina(head);
    stampa(head);
}

