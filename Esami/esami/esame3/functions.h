#ifndef FUNZIONI_H
#define FUNZIONI_H

struct Bacheca {
  char *msg;
  int n_like;
  struct Bacheca *next;
};

void init_bacheca(struct Bacheca **post);

void append(struct Bacheca **bacheca, struct Bacheca *post);

void pop(struct Bacheca **bacheca);

int len(struct Bacheca **bacheca);

int is_empty(struct Bacheca **bacheca);

void load_user_from_file(struct Bacheca **bacheca, char *nomefile);

void condividi(struct Bacheca *post);

void free_memory(struct Bacheca **bacheca);

#endif
