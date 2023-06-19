#include <stdio.h>
#include "functions.h"

int main() {
 struct Elenco *e;
 init_stack(&e);

 load_music_from_file("canzoni.txt", &e);

 print_list(e);

 write_music_on_file("canzoni_2.txt", e);

 printf("\nProva\n");
}
