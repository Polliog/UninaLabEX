#include "funzioni.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void initStack(struct Bacheca **actual) {
    *actual = NULL;
}

void append(struct Bacheca **actual, char *content, int likes) {
    struct Bacheca *new = malloc(sizeof(struct Bacheca));
    strcpy(new->content, content);
    new->likes = likes;
    new->next = *actual;
    *actual = new;
}

void pop(struct Bacheca **actual) {
    struct Bacheca *temp = *actual;
    *actual = (*actual)->next;
    free(temp);
}

void printStack(struct Bacheca *actual) {
    if (actual == NULL) {
        printf("La bacheca e' vuota\n");
        return;
    }

    int i = 1;

    while (actual != NULL) {
        printf("\n\nPost n: %d\nContenuto: %s\nLikes: %d\n\n", i, actual->content, actual->likes);
        actual = actual->next;
        i++;
    }
}

void printPost(struct Bacheca *actual, int n) {
    if (actual == NULL) {
        printf("La bacheca e' vuota\n");
        return;
    }

    int i = 1;

    while (actual != NULL) {
        if (i == n) {
            printf("\n\nPost n: %d\nContenuto: %s\nLikes: %d\n\n", i, actual->content, actual->likes);
            break;
        }
        actual = actual->next;
        i++;
    }
}

int len(struct Bacheca *actual) {
    int i = 0;

    while (actual != NULL) {
        actual = actual->next;
        i++;
    }

    return i;
}


int is_empty(struct Bacheca *actual) {
    if (actual == NULL) {
        return 0;
    } else {
        return 1;
    }
}

void load_user_from_file(struct Bacheca **actual, char *filename) {
    printf("Loading from file: %s\n", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("\nSi e' verificato un errore nell'apertura del file\n");
        return;
    }

    char content[255] = {0};
    char likes[255] = {0};

    while (fgets(content, 255, fp) != NULL) {
        fgets(likes, 255, fp);
        append(actual, content, atoi(likes));
    }

    fclose(fp);
}

void add_like(struct Bacheca *actual, int n) {
        if (actual == NULL) {
        printf("La bacheca e' vuota\n");
        return;
    }

    int i = 1;

    while (actual != NULL) {
        if (i == n) {
            printf("\n\nPost n: %d\nContenuto: %s\nLikes: %d\n\n", i, actual->content, actual->likes);
            actual->likes++;
            break;
        }
        actual = actual->next;
        i++;
    }
}

void save_on_file(struct Bacheca *actual, char *filename) {
    printf("Saving on file: %s\n", filename);

    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("\nSi e' verificato un errore nell'apertura del file\n");
        return;
    }

    while (actual != NULL) {
        fprintf(fp, "%s", actual->content);
        fprintf(fp, "%d\n", actual->likes);
        actual = actual->next;
    }

    fclose(fp);
}

void share_post(struct Bacheca *actual, int n) {
    FILE *fp = fopen("condivisi.txt", "a");

    if (fp == NULL) {
        printf("\nSi e' verificato un errore nell'apertura del file\n");
        return;
    }

    if (actual == NULL) {
        printf("La bacheca e' vuota\n");
        return;
    }

    int i = 1;

    while (actual != NULL) {
        if (i == n) {
            fprintf(fp, "%s", actual->content);
            fprintf(fp, "%d\n", actual->likes);
            break;
        }
        actual = actual->next;
        i++;
    }

    fclose(fp);
}