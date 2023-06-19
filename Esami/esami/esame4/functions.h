#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Match {
  char **campo;
  char vincitore;
  int punteggio;
  struct Match *next;
};


void load_matches_from_file(struct Match **matches);

void start_node(struct Match **matches);

void print_list(struct Match **matches);

void remove_tied(struct Match **matches);

void write_winners_on_file(char *filename, struct Match **matches, char winner);

#endif
