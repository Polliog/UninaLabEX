#ifndef UNINALABEX_FUNZIONI_H
#define UNINALABEX_FUNZIONI_H

struct Stack {
    char **match;
    char winner; //x, o, p
    struct Stack *next;
    int punteggio;
};

void startStack(struct Stack **stack);

void insertInStack(struct Stack **stack, char val[3][3]);

void load_matches_from_file(struct Stack **stack);

char the_winner_is(char match[3][3]);

int match_score(char match[3][3]);

void print_list(struct Stack *stack);

void remove_from_stack(struct Stack **stack, int punteggio);

void remove_tied_matches(struct Stack **stack);

void write_winners_on_file(char filename[], struct Stack *stack, char winner);

#endif
