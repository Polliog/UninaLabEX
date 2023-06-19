#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_stack(struct Elenco **elenco) {
  *elenco = NULL;
}

void insert(char *titolo, char *autore, int durata, struct Elenco **elenco) {
    if (titolo[0] >= 'a' && titolo[0] <= 'z') {
	    titolo[0] -= 32;
    }


    //cerco se esiste già una canzone con quel titolo all'interno della lista elenco

    struct Elenco *tmp = *elenco;

    while (tmp != NULL) {
        if (strcmp(tmp->titolo, titolo) == 0) {
            tmp->rips++;
            return;
        }
        tmp = tmp->next;
    }

    //se non esiste, creo un nuovo nodo e lo inserisco in testa alla lista

    struct Elenco *new = malloc(sizeof(struct Elenco));

    new -> titolo = malloc(sizeof(char) * (strlen(titolo) + 1));
    strcpy(new->titolo, titolo);

    new -> autore = malloc(sizeof(char) * (strlen(autore) + 1));
    strcpy(new->autore, autore);

    new -> durata_in_sec = durata;
    new -> rips = 1;

    new -> next = *elenco;
    *elenco = new;

}

int minutes_to_seconds(char *durata) {
   //durata = "3:30"

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
  }

  char titolo[30] = {0};
  char autore[30] = {0};
  char durata[30] = {0};


  while (fgets(titolo, 30, fp) != NULL) {
    fgets(autore, 30, fp);
    fgets(durata, 30, fp);
    int durata_int = minutes_to_seconds(durata);

    insert(titolo, autore, durata_int, elenco);
  }
}

void print_list(struct Elenco *elenco) {
  if (elenco == NULL) {
    printf("\nElenco Vuoto\n");
    return;
  }

  while (elenco != NULL) {
   printf("\n\n Titolo: %s\n Autore: %s\n Durata: %d\n Riproduzione: %d\n\n", elenco->titolo, elenco->autore, elenco->durata_in_sec, elenco->rips);
   elenco = elenco->next;
  }
}

void write_music_on_file(char *nome_file, struct Elenco *elenco) {
    FILE *fp = fopen(nome_file, "w");
    if (fp == NULL) {
         printf("\nErrore nella scrittura del file\n");
    }

    while (elenco != NULL) {
        fprintf(fp,"%s %s %d\n%d\n", elenco->titolo, elenco->autore, elenco->durata_in_sec, elenco->rips);
        elenco = elenco->next;
    }
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








