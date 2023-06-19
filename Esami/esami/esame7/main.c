#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Studente {
  char *nome;
  char *cognome;
  int matricola;
  char *esame;
  int voto;
  struct Studente *next;
};

void init_node(struct Studente **studenti) {
  *studenti = NULL;
}

void add_node(struct Studente **studenti, struct Studente *studente) {
  if (*studenti == NULL) {
    *studenti = studente;
    return;
  } else {
    struct Studente *temp = *studenti;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp -> next = studente;
  }
}

void load_from_file(char *filename, struct Studente **studenti) {
  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("\nErrore nella lettura del file: %s\n", filename);
    return;
  }

  char nome[255] = {0};
  char cognome[255] = {0};
  int matricola = 0;
  char esame[255] = {0};
  int voto = 0;
  
  while (fscanf(fp, "%s %s %d %s %d", nome, cognome, &matricola, esame, &voto) != EOF) {
    struct Studente *new = malloc(sizeof(struct Studente));

    new -> nome = malloc(sizeof(char) * sizeof(nome));
    new -> cognome = malloc(sizeof(char) * sizeof(cognome));
    new -> esame = malloc(sizeof(char) * sizeof(esame));

    strcpy(new->nome, nome);
    strcpy(new->cognome, cognome);
    strcpy(new->esame, esame);

    new -> matricola = matricola;
    new -> voto = voto;

    add_node(studenti, new);
  }
}

void print_nodes(struct Studente **studenti) {
  struct Studente *temp = *studenti;

  while (temp != NULL) {
   printf("\n---------------\n");
   printf("%s %s %d %s %d", temp->nome, temp->cognome, temp->matricola, temp->esame, temp->voto);
   printf("\n---------------\n");
   temp = temp->next;
  }
}

void remove_by_vote(struct Studente **studenti, int vote) {
   struct Studente *temp = *studenti;
   struct Studente *prev = NULL;

   while (temp != NULL) {
     if (temp->voto < vote) {
       if (prev == NULL) {
          *studenti = temp->next;
       } else {
          prev->next = temp->next;
       }
     } else {
       prev = temp;
     }

     temp = temp->next;
   }
}

int len_nodes(struct Studente **studenti) {
  int i = 0;

  struct Studente *temp = *studenti;
  while (temp != NULL) {
    i++;
    temp = temp->next;
  }

  return i;
}

void save_on_file(char *filename, struct Studente **studenti) {
  FILE *fp = fopen(filename, "w");

  if (fp == NULL) {
    printf("\nErrore nella scrittura del file: %s\n", filename);
    return;
  }

  int n = len_nodes(studenti);

  int idx = 0;
  
  int *matricole_registrate;
  matricole_registrate = malloc(sizeof(int) * n);

  struct Studente *studente = *studenti;
  while (studente != NULL) {
     struct Studente *temp = *studenti;

     int registrato = 0;
     for (int i = 0; i < idx; i++) {
        if (matricole_registrate[i] == studente->matricola) {
          registrato = 1;
        }
     }

     if (!registrato) {
        matricole_registrate[idx] = studente->matricola;
        idx++;
     }

     while (temp != NULL && !registrato) {
       if (temp->matricola == studente->matricola) {
         fprintf(fp, "%s %s %d %s %d\n", temp->nome, temp->cognome, temp->matricola, temp->esame, temp->voto);
       }
       temp = temp->next;
     }
     studente = studente->next;
  }

  fclose(fp);
}

void free_memory(struct Studente **studenti) {
  //delete all nodes

    struct Studente *temp = *studenti;
    while (temp != NULL) {
      struct Studente *next = temp->next;
      free(temp->nome);
      free(temp->cognome);
      free(temp->esame);
      free(temp);
      temp = next;
}

int main() {
  //a
  struct Studente *s;
  init_node(&s);
  load_from_file("studenti.txt", &s);
  //print_nodes(&s);
  //b
  remove_by_vote(&s, 18);
  //print_nodes(&s);
  //c
  save_on_file("studenti2.txt", &s);
  //print_nodes(&s);

  free_memory(&s);
}
