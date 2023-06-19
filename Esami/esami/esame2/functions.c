#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init_node(struct Elenco **elenco) {
  *elenco = NULL;
}


void append(struct Elenco **elenco, char *titolo, char *autore, int durata) {
  //trasformo la prima lettera del titolo in maiscuolo;
  if (titolo[0] >= 'a' && titolo[0] <= 'z') {
     titolo[0] -= 32;
  }

  //cerco un titolo uguale
  struct Elenco *tmp = *elenco;

  while(tmp != NULL) {
    if (strcmp(tmp->titolo, titolo) == 0) {
      tmp->rips++;
      return;
    }

    tmp = tmp->next;
  }

  //salvo in un nuovo nodo
  struct Elenco *new = malloc(sizeof(struct Elenco));

  new -> titolo = malloc(sizeof(char) * (strlen(titolo) + 1));
  strcpy(new->titolo, titolo);
  
  new-> autore = malloc(sizeof(char) * (strlen(autore) + 1));
  strcpy(new->autore, autore);

  new -> durata_in_sec = durata;
  new -> rips = 1;
 
  new -> next = *elenco;
  *elenco = new;

  printf("\nCaricato:\n %s\n %s \n %d \n", titolo, autore, durata);
}

int parse_seconds(char *durata) {
  char *minuti = strtok(durata, ":");
  char *secondi = strtok(NULL, ":");
  
  int minuti_int = atoi(minuti);
  int secondi_int = atoi(secondi);

  return (minuti_int * 60) + secondi_int;
}

void load_music_from_file(char *nome_file, struct Elenco **elenco) {
  FILE *fp = fopen(nome_file, "r");
 
  if (fp == NULL) {
    printf("\nErrore nella lettura del file\n");
    return;
  }

  char titolo[30] = {0};
  char autore[30] = {0};
  char durata[30] = {0};

  while (fgets(titolo, 30, fp) != NULL) {
    fgets(autore, 30, fp);
    fgets(durata, 30, fp);
    append(elenco, titolo, autore, parse_seconds(durata));
  }

  fclose(fp);
}

void write_music_on_file(char *nome_file, struct Elenco **elenco) {
  FILE *fp = fopen(nome_file, "w");
  if (fp == NULL) {
    printf("\nErrore nella scrittura del file\n");
  }

  struct Elenco *tmp = *elenco;

  while(tmp != NULL) {
    fprintf(fp,"%s%s%d\n%d\n",tmp->titolo, tmp->autore, tmp->durata_in_sec, tmp->rips);
    tmp = tmp->next;
  }

  fclose(fp);
}


void free_memory(struct Elenco *elenco) {
  struct Elenco *tmp = elenco;
  while (tmp != NULL) {
    free(tmp->titolo);
    free(tmp->autore);
    struct Elenco *tmp2 = tmp;
    tmp = tmp->next;
    free(tmp2);
  }
}
