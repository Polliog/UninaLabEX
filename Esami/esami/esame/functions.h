#ifndef FUNZIONI_H
#define FUNZIONI_H

struct Elenco {
  char *titolo;
  char *autore;
  int durata_in_sec;
  int rips;
  struct Elenco *next;
};

void init_stack(struct Elenco **elenco);

void load_music_from_file(char *nome_file, struct Elenco **elenco);

void print_list(struct Elenco *elenco);

void write_music_on_file(char *nome_file, struct Elenco *elenco);

#endif
