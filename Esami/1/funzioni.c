#include "funzioni.h"
#include <stdlib.h>
#include <stdio.h>


void startStack(struct Stack **stack) {
    //Inizializzazione della pila
    *stack = NULL;
}

//Inserimento nello stack visto che ci sono anche delle matrici allocate dinamicamente
//Bisogna allocarle col malloc
void insertInStack(struct Stack **stack, char val[3][3]) {
    struct Stack *new = malloc(sizeof(struct Stack));
    new->winner = the_winner_is(val);
    new->next = *stack;

    //salva val in new->match
    //allocazione dinamica di memoria per la matrice
    new->match = malloc(3 * sizeof(char *)); //char * perchè è un array di array di char

    for (int i = 0; i < 3; i++) {
        new->match[i] = malloc(3 * sizeof(char));
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            new->match[i][j] = val[i][j];
        }
    }


    if (new->winner == 'p') {
        new->punteggio = 0;
    }  else {
        new->punteggio = match_score(val);
    }

    *stack = new;
}

void load_matches_from_file(struct Stack **stack) {
    FILE *fp = fopen("configurazioni.txt", "r");
    if (fp == NULL) {
        printf("Errore nella lettura del file");
    }

    char actual[9];
    char actual_parsed[3][3];

    while (fgets(actual, sizeof(actual), fp) != NULL) {
        printf("%s", actual);

        //Transforma la stringa in una matrice di char
        int i = 0;
        int j = 0;
        int k = 0;
        while (actual[i] != '\0') {
            if (actual[i] != ' ') {
                actual_parsed[j][k] = actual[i];
                k++;
            }
            i++;
        }
        insertInStack(stack, actual_parsed);
    }


    fclose(fp);
}



char the_winner_is(char match[3][3]) {
    //check rows
    for (int i = 0; i < 3; i++) {
        if (match[i][0] == match[i][1] && match[i][1] == match[i][2]) {
            return match[i][0]; //###
        }
    }

    //check columns
    for (int i = 0; i < 3; i++) {
        if (match[0][i] == match[1][i] && match[1][i] == match[2][i]) {
            return match[0][i]; // # \ # \ #
        }
    }

    //check diagonals
    if (match[0][0] == match[1][1] && match[1][1] == match[2][2]) {
        return match[0][0];
    }
    if (match[0][2] == match[1][1] && match[1][1] == match[2][0]) {
        return match[0][2];
    }

    return 'p';
}


int free_positions(char match[3][3]) {
    int positions = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (match[i][j] == '@') {
                positions++;
            }
        }
    }
    return positions;
}

//0 se pareggio, altrimenti 3 + posizioni libere
int match_score(char match[3][3]) {
    int points = 3 + free_positions(match);
    return points;
}

void print_match(struct Stack *stack) {
    printf("\nMatch:\n");
    for (int i = 0; i < 3; i++) {
        printf("%c %c %c\n", stack->match[i][0], stack->match[i][1], stack->match[i][2]);
    }
    printf("Winner: %c\n", stack->winner);
    printf("Punteggio: %d\n", stack->punteggio);
    printf("\n");
}

//ricorsiva
void print_list(struct Stack *stack) {
    print_match(stack);

    if (stack->next != NULL) {
        print_list(stack->next);
    }
}

void remove_from_stack(struct Stack **stack, int punteggio) {
    if (*stack == NULL) {
        return;
    }

    if ((*stack)->punteggio == punteggio) { //se il punteggio è uguale a quello passato come parametro
        struct Stack *temp = *stack; //salva il puntatore al primo elemento
        *stack = (*stack)->next; //sposta il puntatore al secondo elemento
        free(temp); //libera il primo elemento
        remove_from_stack(stack, punteggio); //richiama la funzione
    } else {
        remove_from_stack(&((*stack)->next), punteggio); //richiama la funzione
    }
}


void remove_tied_matches(struct Stack **stack) {
    int punteggio = 0;
    remove_from_stack(stack, punteggio);
}


void write_winners_on_file(char filename[], struct Stack *stack, char winner) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Errore nella scrittura del file");
    }

    while (stack != NULL) {
        if (stack->winner == winner) {
            for (int i = 0; i < 3; i++) {
                fprintf(fp, "%c %c %c\n", stack->match[i][0], stack->match[i][1], stack->match[i][2]);
            }
            fprintf(fp, "\n\n\n");
        }
        stack = stack->next;
    }

    fclose(fp);
}