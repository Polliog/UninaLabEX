#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void start_node(struct Match **matches) {
  *matches = NULL;
}

void add_node(struct Match **matches,struct Match *match) {
    if (*matches == NULL) {
        *matches = match;
    } else {
        struct Match *temp = *matches;
        while (temp->next != NULL) {
        temp = temp->next;
        }
        temp->next = match;
    }
}

void riga_to_matrice(char *riga, char **campo) {
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

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      //printf("%c", campo[i][j]);
    }
    //printf("\n");
  }
}

char the_winner_is(char **match) {
  for (int i = 0; i < 3; i++) {
    if (match[i][0] == match[i][1] && match[i][1] == match[i][2]) {
       return match[i][0];
    }
  }

  for (int i = 0; i < 3; i++) {
    if (match[0][i] == match[1][i] && match[1][i] == match[2][i]) {
      return match[0][i];
    }
  }

  if (match[0][0] == match[1][1] && match[1][1] == match[2][2]) {
    return match[0][0];
  }

  if (match [0][2] == match[1][1] && match[1][1] == match[2][0]) {
    return match[0][2];
  }

  return 'p';
}

int free_positions(char **campo) {
  int f = 0;

  for (int i = 0; i < 3; i++) {
     for (int j = 0; j < 3; j++) {
        if (campo[i][j] == '@') {
          f++;
        }
     }
  }

  return f;
}

int match_score(char **campo) {
  return 3 + free_positions(campo);
}

void load_matches_from_file(struct Match **matches) {
  FILE *fp = fopen("configurazioni.txt", "r");

  char riga[10];

  while (fgets(riga, sizeof(riga), fp) != NULL) {
    //printf("\n-------------\n");
    struct Match *new = malloc(sizeof(struct Match));

    int skip = 0;
     
    for (int i = 0; i < 10; i++) {
        //printf("%d\n", riga[i]);
      if (riga[i] < '@' && i < 9) {
        //printf("prova : %d\n", i);
        skip = 1;
      }
    }

    if (skip) continue;

    new->campo = malloc(sizeof(char *) * 3);

    for (int i = 0; i < 3; i++) {
      new->campo[i] = malloc(3 * sizeof(char));
    }

    riga_to_matrice(riga, new->campo);

    new->vincitore = the_winner_is(new->campo);

    if (new->vincitore == 'p') {
      new->punteggio = 0;
    } else {
      new->punteggio = match_score(new->campo);
    }

    new -> next = NULL;

    //printf("%s\n", riga);
    add_node(matches, new);
    //printf("\n-------------\n");
    //printf("%s", riga);
  }
}

void print_match(struct Match *match) {
   printf("\n-----------------\n");
   for (int i = 0; i < 3; i++) {
     for (int j = 0; j < 3; j++) {
       printf("%c", match->campo[i][j]);
     }
     printf("\n");
   }
   printf("Vincitore: %c\nPunteggio: %d", match->vincitore, match->punteggio);
}

void print_list(struct Match **matches) {
  struct Match *temp = *matches;

  while (temp != NULL) {
    print_match(temp);
    temp = temp->next;
  }
}

void remove_tied (struct Match **matches) {
  struct Match *temp = *matches;
  struct Match *prev = NULL;

  while (temp != NULL) {
    if (temp->vincitore == 'p' || temp->punteggio == 0) {
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

void write_winners_on_file(char *filename, struct Match **matches, char winner) {
  FILE *fp = fopen(filename, "w");

  struct Match *temp = *matches;

  while (temp != NULL) {
    if (temp->vincitore == winner) {
        for (int i = 0; i < 3; i++) {
            fprintf(fp, "%c%c%c\n", temp->campo[i][0], temp->campo[i][1], temp->campo[i][2]);
        }
        fprintf(fp, "\n");
    }
    temp = temp->next;
  }
}


void free_memory(struct Match **matches) {
  struct Match *temp = *matches;
  struct Match *prev = NULL;

  while (temp != NULL) {
    prev = temp;
    temp = temp->next;
    free(prev);
  }
}