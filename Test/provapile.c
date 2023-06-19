#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Match {
    int id;
    int points;
    char **match;
    struct Match *next;
};

void initStack(struct Match **actual) {
    *actual = NULL;
}

void addLifo(struct Match **actual, int id) {
    struct Match *new = malloc(sizeof(struct Match));
    new->id = id;
    new->points = rand() % 100;
    new->match = malloc(sizeof(char *) * 3);
    for (int i = 0; i < 3; i++) {
        new->match[i] = malloc(sizeof(char) * 3);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            new->match[i][j] = rand() % 2 == 0 ? 'X' : 'O';
        }
    }

    new->next = *actual;
    *actual = new;
}

void addFifo(struct Match **actual, int id) {
    struct Match *new = malloc(sizeof(struct Match));
    //new->id = id;
    //new->points = rand() % 100;
    //new->match = malloc(sizeof(char *) * 3);
    //new->next = NULL;
    //for (int i = 0; i < 3; i++) {
    //    new->match[i] = malloc(sizeof(char) * 3);
    //}

    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 3; j++) {
    //        new->match[i][j] = rand() % 2 == 0 ? 'X' : 'O';
    //    }
    //}

   // printf("%d\n", id);

    if (*actual == NULL) {
        *actual = new;
        return;
    }


    struct Match *temp = *actual;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new;
}

void printStack(struct Match *actual) {
    if (actual == NULL) {
        printf("vuota\n");
        return;
    }

    while (actual != NULL) {
        printf("id: %d\n", actual->id);
        printf("points: %d\n", actual->points);
        printf("match: \n");
        for (int i = 0; i < 3; i++) {
            printf("\t");
            for (int j = 0; j < 3; j++) {
                printf("%c ", actual->match[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        actual = actual->next;
    }
}

void purgeStack(struct Match **actual) {
    struct Match *temp = *actual;
    while (*actual != NULL) {
        *actual = (*actual)->next;
        free(temp);
        temp = *actual;
    }

    *actual = NULL;
}

void saveOnFile(struct Match *actual, char *filename) {

    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Errore nell'apertura del file\n");
        return;
    }

    while (actual != NULL) {
        fprintf(fp, "%d\n", actual->id);
        fprintf(fp, "%d\n", actual->points);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                fprintf(fp, "%c", actual->match[i][j]);
            }
            fprintf(fp, "\n");
        }
        fprintf(fp, "\n");
        actual = actual->next;
    }

    fclose(fp);
}

int main() {
    struct Match *m;

    initStack(&m);

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        addLifo(&m, i);
    }

    //printStack(m);

    saveOnFile(m, "matches1.txt");

    struct Match *m2;
    initStack(&m2);

    for (int i = 0; i < 10; i++) {
        addFifo(&m2, i);
    }

    printStack(m2);

    saveOnFile(m2, "matches2.txt");
}