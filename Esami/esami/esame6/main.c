#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Utente {
  char *nome;
  char *cognome;
  int peso;
  int altezza;
  int eta;
  struct Utente *next;
};

void init_node(struct Utente **utenti) {
  *utenti = NULL;
}

void add_node(struct Utente **utenti, struct Utente *utente) {
  if (*utenti == NULL) {
    *utenti = utente;
    return;
  } else {
    struct Utente *temp = *utenti;
    while (temp -> next != NULL) {
      temp = temp -> next;
    }
    temp -> next = utente;
  }
}

void load_from_file(char *filename, struct Utente **utenti) {
  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("\nErrore nella lettura del file\n");
    return;
  }

  char nome[255] = {0};
  char cognome[255] = {0};
  int peso = 0;
  int altezza = 0;
  int eta = 0;
  
  while (fscanf(fp, "%s %s %d %d %d", nome, cognome, &peso, &altezza, &eta) != EOF) {
    struct Utente *new = malloc(sizeof(struct Utente));

    new -> nome = malloc(sizeof(char) * sizeof(nome));
    new -> cognome = malloc(sizeof(char) * sizeof(cognome));

    strcpy(new -> nome, nome);
    strcpy(new -> cognome, cognome);

    new -> peso = peso;
    new -> altezza = altezza;
    new -> eta = eta;
    new -> next = NULL;

    add_node(utenti, new);
  }

  fclose(fp);
}

void print_nodes(struct Utente **utenti) {
  struct Utente *temp = *utenti;

  while (temp != NULL) {
    printf("\n--------------\n");
    printf("%s %s %d %d %d", temp->nome, temp -> cognome, temp->peso, temp->altezza, temp->eta);
    printf("\n--------------\n");
    temp = temp->next;
  }
}

void delete_by_weight(struct Utente **utenti, int limit) {
  struct Utente *temp = *utenti;
  struct Utente *prev = NULL;

  while (temp != NULL) {
    if (temp -> peso < limit) {
      if (prev == NULL) {
        *utenti = temp->next;
      } else {
        prev -> next = temp -> next;
      }
    } else {
     prev = temp;
    }

    temp = temp->next;
  }
}

void dup_by_age(struct Utente **utenti) {
  struct Utente *temp = *utenti;

  while (temp != NULL) {
    int dup = 0;
  
    if (temp->eta % 2 == 0) {
      struct Utente *new = malloc(sizeof(struct Utente));
      new -> nome = malloc(sizeof(char) * sizeof(temp -> nome));
      strcpy(new->nome,temp->nome);

      new -> cognome = malloc(sizeof(char) * sizeof(temp -> cognome));
      strcpy(new->cognome,temp->cognome);

      new -> peso = temp -> peso;
      new -> altezza = temp -> altezza;
      new -> eta = temp -> eta;

      new -> next = temp -> next;
      temp -> next = new;
      dup = 1;
    }

    temp = temp->next;

    if (dup) {
      temp = temp->next;
    }
  }
}

void save_on_file(char *filename, struct Utente **utenti) {
  FILE *fp = fopen(filename, "w");

  if (fp == NULL) {
    printf("\nErrore nella scrittura del file: %s\n", filename);
    return;
  }

  struct Utente *temp = *utenti;

  while (temp != NULL) {
    fprintf(fp,"%s %s %d %d %d\n",temp->nome, temp->cognome, temp->peso, temp->altezza, temp->eta);
    temp = temp->next;
  }

  fclose(fp);

}

int main() {
  struct Utente *u;
  init_node(&u);
  //a
  load_from_file("utenti.txt", &u);

  //print_nodes(&u);
  //b
  delete_by_weight(&u, 12);
  //print_nodes(&u);
  //c
  dup_by_age(&u);
  print_nodes(&u);
  //d
  save_on_file("utenti_riscritti.txt", &u);
  //print_nodes(&u);
  printf("\nFinito\n");
}
