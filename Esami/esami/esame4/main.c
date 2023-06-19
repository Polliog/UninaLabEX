#include <stdio.h>
#include "functions.h"

int main() {
  struct Match *m;

  start_node(&m);
  
  load_matches_from_file(&m);

  print_list(&m);

  remove_tied(&m);

  write_winners_on_file("vittorie_X.txt", &m, 'X');
  write_winners_on_file("vittorie_O.txt", &m, 'O');
  
  printf("\nFinito\n");
}
