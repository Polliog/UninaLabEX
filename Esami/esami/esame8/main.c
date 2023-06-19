#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Classe {
    char *classe;
    int studenti;
    int promossi;
    int bocciati;
    int rimandati;
    struct Classe *next;
};

void init_node(struct Classe **classi) {
    *classi = NULL;
}

void add_node(struct Classe **classi, struct Classe *classe) {
    if (*classi == NULL) {
        *classi = classe;
        return;
    } else {
        struct Classe *temp = *classi;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = classe;
    }
}

void print_nodes(struct Classe **classi) {
    struct Classe *temp = *classi;

    while (temp != NULL) {
        printf("\n------------\n");
        printf("\n%s %d %d %d %d\n", temp->classe, temp->studenti, temp->promossi, temp->bocciati, temp->rimandati);
        printf("\n------------\n");
        temp = temp->next;
    }
}

void load_from_file(char *filename, struct Classe **classi) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("\nErrore nella lettura del file: %s\n", filename);
        return;
    }

    char classe[255] = {0};
    int studenti, promossi, bocciati, rimandati;

    while (fscanf(fp, "%s %d %d %d %d", classe, &studenti, &promossi, &bocciati, &rimandati) != EOF) {
        struct Classe *new = malloc(sizeof(struct Classe));

        new->classe = malloc(sizeof(char) * sizeof(classe));
        strcpy(new->classe, classe);

        new->studenti = studenti;
        new->promossi = promossi;
        new->bocciati = bocciati;
        new->rimandati = rimandati;

        new->next = NULL;

        add_node(classi, new);
    }

    fclose(fp);
}

int rimuovi_incongruenze(struct Classe **classi) {
    struct Classe *temp = *classi;
    struct Classe *prev = NULL;

    while (temp != NULL) {
        if (temp->studenti != (temp->promossi + temp->bocciati + temp->rimandati)) {
            //printf("\n%s %d %d %d %d\n",temp->classe, temp->studenti, temp->promossi, temp->bocciati, temp->rimandati);
            if (prev == NULL) {
                *classi = temp->next;
            } else {
                prev->next = temp->next;
            }
        } else {
            prev = temp;
        }

        temp = temp->next;
    }
}

void save_on_file(char *filename, struct Classe **classi) {
    FILE * fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("\nErrore nella scrittura del file: %s\n", filename);
        return;
    }

    //in maniera che le classi siano
    //ordinate i maniera decrescente rispetto al numero di promossi, senza però modificare la lista o creare una nuova
    //lista d’appoggio.

    struct Classe *temp = *classi;
    struct Classe *prev = NULL;

    while (temp != NULL) {
        if (temp->promossi > temp->next->promossi) {
            if (prev == NULL) {
                *classi = temp->next;
            } else {
                prev->next = temp->next;
            }
        } else {
            prev = temp;
        }

        temp = temp->next;
    }

    //stampare la lista su file
    temp = *classi;

    while (temp != NULL) {
        fprintf(fp, "%s %d %d %d %d\n", temp->classe, temp->studenti, temp->promossi, temp->bocciati, temp->rimandati);
        temp = temp->next;
    }

    fclose(fp);
}

void free_nodes(struct Classe **classi) {
    struct Classe *temp = *classi;

    while (temp != NULL) {
        struct Classe *next = temp->next;
        free(temp->classe);
        free(temp);
        temp = next;
    }
}

int main() {
    struct Classe *c;
    init_node(&c);
    //a
    load_from_file("classi.txt", &c);
    //print_nodes(&c);
    //b
    rimuovi_incongruenze(&c);
    print_nodes(&c);
    //c
    save_on_file("classi2.txt", &c);

    //free_nodes(&c);
}









