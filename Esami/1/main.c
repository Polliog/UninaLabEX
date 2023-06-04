//TRACCIA NEL FILE 2006_traccia.pdf

#include <stdio.h>
#include "funzioni.h"

int main() {
    //punto 1
    struct Stack *m;
    startStack(&m);

    load_matches_from_file(&m);

    //punto 2
    print_list(m);

    //punto 3
    remove_tied_matches(&m);

    print_list(m);

    //punto 4

    write_winners_on_file("vittorie_X.txt", m, 'X');
    write_winners_on_file("vittorie_O.txt", m, 'O');

}