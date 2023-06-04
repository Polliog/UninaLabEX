#include "funzioni.h"
#include <stdio.h>

int main() {
    struct Bacheca *b;
    initStack(&b);

    //Punto 1
    printf("Punto 1\n\n");
    printf("Empty: %d\n", is_empty(b));

    printf("Inserimento:\n");


    char post[255] = "Calabria merda";
    append(&b, post, 1);

   printf("Empty: %d\n", is_empty(b));
   printf("Len: %d\n", len(b));

    printStack(b);

    printf("Tolgo:\n");

    pop(&b);

    printf("Empty: %d\n", is_empty(b));
    printf("Len: %d\n", len(b));
    printStack(b);


    printf("\n\nPunto 2\n\n");
    load_user_from_file(&b, "utente42.txt");

    printStack(b);

    printf("Empty: %d\n", is_empty(b));

    int actual_len = len(b);

    printf("Len: %d\n", actual_len);

    printf("\n\nPunto 3\n\n");


    for (int i = 0; i < actual_len; i++) {
        int selection = -1;

        printPost(b, i+1);

        printf("\nSeleziona un opzione:\n"
               "1: Fermati\n"
               "2: Prossimo Post\n"
               "3: Aggiungi Like\n"
               "4: Condividi Post");

        scanf("%d", &selection);

        switch (selection) {
            case 1:
                return 0;
            case 2:
                continue;
            case 3:
                add_like(b, i);
                save_on_file(b, "utente42.txt");
                break;
            case 4:
                share_post(b, i+1);
                break;
        }
    }
}