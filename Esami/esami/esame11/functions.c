#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


void init_node (struct Match **matches) {
  *matches = NULL;
}

void append(struct Match **matches, struct Match *match) {
	if (*matches == NULL) {
		*matches = match;
		return;
	} else {
		struct Match *temp = *matches;
		while (temp -> next != NULL) {
		  temp = temp->next;
		}
		temp->next = match;
	}
}

void parse_matrix(char *riga, char **campo) {
	int i = 0;
	int j = 0;
	int k = 0;

	while (riga[i] != '\0') {
		if (riga[i] != ' ') {
			campo[j][k] = riga[i];
			k++;
			if (k == 3) {
				j++;
				k = 0;
			}
		}
		i++;

	}
};

char the_winner_is(char **campo) {
	//riga
	for (int i = 0; i < 3; i++) {
		if (campo[i][0] == '@') continue;

		if (campo[i][0] == campo[i][1] && campo[i][1] == campo[i][2]) {
			return campo[i][0];
		}
	}

	//colonna
	for (int i = 0; i < 3; i++) {
		if (campo[0][i] == '@') continue; 

		if (campo[0][i] == campo[1][i] && campo[1][i] == campo[2][i]) {
			return campo[0][i];
		}
	}

	//diagonale principale
	
	if (campo[0][0] != '@') {
		if (campo[0][0] == campo[1][1] && campo[1][1] == campo[2][2]) {
			return campo[0][0];
		}
	}

	//secondaria
	if (campo[2][0] != '@') {
		if (campo[2][0] == campo[1][1] && campo[1][1] == campo[0][2]) {
	  		return campo[2][0];
		}
	}

	return 'P';
}

int match_score(char **match) {
	int p = free_positions(match);

	return 3 + p;
}

int free_positions(char **match) {
	int p = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (match[i][j] == '@') {
				p++;
			}
		}
	}

	return p;
}

void load_matches_from_file(char *filename, struct Match **matches) {
	FILE *fp = fopen(filename, "r");
	
	if (fp == NULL) {
		printf("\nErrore nell'apertura del file: %s\n", filename);
		return;
	}	

	char campo[10];

	while (fscanf(fp, "%s", campo) != EOF) {
		struct Match *new = malloc(sizeof(struct Match));

		new->campo = malloc(sizeof(char *) * 3);

		for (int i = 0; i < 3; i++) {
		  new->campo[i] = malloc(sizeof(char) * 3);
		}


		parse_matrix(campo, new->campo);

		new->vincitore = the_winner_is(new->campo);

		if (new->vincitore != 'P') {
			new->punteggio = match_score(new -> campo);
		} else {
			new -> punteggio = 0;
		}

		append(matches, new);

	}

	fclose(fp);
}

void print_match(struct Match *match) {
	printf("\n-------------------------\n");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%c", match->campo[i][j]);
		}
		printf("\n");
	}

	printf("Vincitore: %c\nPunteggio: %d\n", match->vincitore, match->punteggio);
	printf("\n-------------------------\n");
}

void print_list(struct Match *match) {
	if (match == NULL) return;

	print_match(match);

	match = match->next;
	print_list(match);
}

void remove_tied(struct Match **matches) {
	struct Match *temp = *matches;
	struct Match *prev = NULL;

	while (temp != NULL) {
		if (temp -> vincitore == 'P') {
			if (prev == NULL) {
				*matches = temp->next;
			} else {
				prev->next = temp->next;
			}
		} else {
			prev = temp;
		}

		temp = temp->next;
	}
}

void write_winners_on_file(char *filename,struct Match **matches,char vincitore) {
  FILE *fp = fopen(filename, "w");

  if (fp == NULL) {
  	printf("\nErrore nella scrittura del file: %s\n", filename);
	return;
  }

  struct Match *temp = *matches;

  while (temp != NULL) {
	if (temp -> vincitore != vincitore) {
		temp = temp->next;
		continue;
	};
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			fprintf(fp,"%c", temp->campo[i][j]);
		}
	}

	fprintf(fp, "\n");

	temp = temp->next;	
  }
}

void free_memory(struct Match **matches) {
	struct Match *temp = *matches;
	struct Match *prev = NULL;

	while (temp != NULL) {
		prev = temp;
		temp = prev->next;

		for (int i = 0; i < 3; i++) {
		   free(prev->campo[i]);
		}

		free(prev->campo);

		free(prev);
	}
}










