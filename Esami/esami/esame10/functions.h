#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Post {
  char *msg;
  int n_like;
  struct Post *next;
};

void init_node(struct Post **bacheca);

struct Post * pop(struct Post **bacheca);

int len(struct Post **bacheca);

int is_empty(struct Post **bacheca);

void load_user_from_file(struct Post **bacheca, char *nomefile);

void print_nodes(struct Post **bacheca);

void print(struct Post *post);

void share_post(struct Post *post);

#endif
