#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_node(struct Post **bacheca) {
  *bacheca = NULL;
}

//FIFO
void append(struct Post **bacheca, struct Post *post) {
  if (*bacheca == NULL) {
    *bacheca = post;
    return;
  } else {
    struct Post *temp = *bacheca;
    while (temp->next != NULL) {
       temp = temp->next;
    }
    temp -> next = post;
  }
}

struct Post * pop(struct Post **bacheca) {
  struct Post *temp = *bacheca;

  *bacheca = temp->next;

  return temp;
}

int len(struct Post **bacheca) {
  struct Post *temp = *bacheca;
  int i = 0;

  if (*bacheca == NULL) return 0;
  
  while(temp != NULL) {
    i++;
    temp = temp->next;
  }
  return i;
}

int is_empty(struct Post **bacheca) {
  if (len(bacheca) > 0) {
    return 0;
  } else {
    return 1;
  }
}

//punto 2
void load_user_from_file(struct Post **bacheca, char *nomefile) {
  FILE *fp = fopen(nomefile, "r");

  if (fp == NULL) {
    printf("\nImpossibile leggere il file: %s\n", nomefile);
    return;
  }

  char msg[256] = {0};
  char likes[256] = {0};

  while (fgets(msg, sizeof(msg), fp) != NULL) {
    fgets(likes, sizeof(likes), fp);
    struct Post *new = malloc(sizeof(struct Post));

    new -> msg = malloc(sizeof(char) * sizeof(msg));
    strcpy(new -> msg, msg);

    new -> n_like = atoi(likes);

    new -> next = NULL;

    append(bacheca, new);
  }

  fclose(fp);
}

void print_nodes(struct Post **bacheca) {
  struct Post *temp = *bacheca;

  while (temp != NULL) {
    printf("\n----------------\n");
    printf("%s%d", temp->msg, temp->n_like);
    printf("\n----------------\n");
    temp = temp->next;
  }
}

void print(struct Post *post) {
  printf("\n------------------\n");
  printf("%s%d", post->msg, post->n_like);
  printf("\n------------------\n");
}


void share_post(struct Post *post) {
  FILE *fp = fopen("condivisi.txt", "a");

  if (fp == NULL) {
    printf("\nErrore nella lettura e scrittura del file condivisi.txt\n");
    return;
  }

  fprintf(fp, "%s%d\n", post->msg, post->n_like);

  fclose(fp);
}
