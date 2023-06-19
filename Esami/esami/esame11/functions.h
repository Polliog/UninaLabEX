#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Match {
	char **campo;
	char vincitore;
	int punteggio;
	struct Match *next;
};

void init_node(struct Match **matches);

void load_matches_from_file(char *filename, struct Match **matches);

void append(struct Match **matches, struct Match *match); 

int free_positions(char **match); 

void print_list(struct Match *match); 

void remove_tied(struct Match **matches); 

void write_winners_on_file(char *filename,struct Match **matches,char vincitore); 

void free_memory(struct Match **matches); 

#endif
