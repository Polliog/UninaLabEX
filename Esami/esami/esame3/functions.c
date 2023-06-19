#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

void init_bacheca(struct Bacheca **post) {
  *post = NULL;
}

void append(struct Bacheca **bacheca, struct Bacheca *post) {
  struct Bacheca *new = post;

  if (*bacheca == NULL) {
    *bacheca = new;
    return;
  }

  struct Bacheca *tmp = *bacheca;

  while (tmp -> next != NULL) {
    tmp =  tmp -> next;
  }

  tmp -> next = new;
}

void pop(struct Bacheca **bacheca) {
  struct Bacheca *temp = *bacheca;

  printf("\n Contenuto: %s \n Likes: %d \n", temp->msg, temp->n_like);

  free(temp);
}

int len(struct Bacheca **bacheca) {
  int n = 0;

  struct Bacheca *temp = *bacheca;

  while (temp != NULL) {
    n++;
    temp = temp -> next;
  };

  return n;
}


int is_empty(struct Bacheca **bacheca) {
  if (len(bacheca) > 0) {
    return 0;
  } else {
    return 1;
  }
}


void load_user_from_file(struct Bacheca **bacheca, char *nomefile) {
  FILE *fp = fopen(nomefile, "r");

  if (fp == NULL) {
    printf("\nErrore nella lettura del file\n");
    return;
  }

  char contenuto[256] = {0};
  char likes[256] = {0};

  while (fgets(contenuto, 256, fp) != NULL) {
    struct Bacheca *temp = malloc(sizeof(struct Bacheca));
    fgets(likes, 256, fp);

    temp->msg = malloc(sizeof(char) * 256);
    strcpy(temp->msg, contenuto);

    temp->n_like = atoi(likes);

    append(bacheca, temp);
  }

  fclose(fp);
}

void condividi(struct Bacheca *post) {
  FILE *fp = fopen("condivisi.txt", "a");

  if (fp == NULL) {
   printf("\nSi e' verificato un errore durante la lettura e scrittura del file\n");
   return;
  }

  fprintf(fp, "%s", post->msg);
  fprintf(fp, "%i\n", post->n_like);

  fclose(fp);
}

void free_memory(struct Bacheca **bacheca) {
  struct Bacheca *tmp = *bacheca;
  while (tmp != NULL) {
    free(tmp -> msg);
    struct Bacheca *tmp2 = tmp;
    tmp = tmp->next;
    free(tmp2);
  }
}
