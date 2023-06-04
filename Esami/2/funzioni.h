#ifndef UNINALABEX_FUNZIONI_H
#define UNINALABEX_FUNZIONI_H

struct Bacheca {
    char content[255];
    int likes;
    struct Bacheca *next;
};

void initStack(struct Bacheca **actual);

void append(struct Bacheca **actual, char *content, int likes);

void pop(struct Bacheca **actual);

void printStack(struct Bacheca *actual);

int len(struct Bacheca *actual);

int is_empty(struct Bacheca *actual);

void load_user_from_file(struct Bacheca **actual, char *filename);

void printPost(struct Bacheca *actual, int n);

void add_like(struct Bacheca *actual, int n);

void save_on_file(struct Bacheca *actual, char *filename);

void share_post(struct Bacheca *actual, int n);
#endif
