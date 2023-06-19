#include <stdio.h>
#include "functions.h"

int main() {
 struct Elenco *e;
 init_node(&e);

 load_music_from_file("canzoni.txt", &e);

 write_music_on_file("canzoni2.txt", &e);
 
 free_memory(e);
 
 printf("\nFinito\n");
 return 0;
}
