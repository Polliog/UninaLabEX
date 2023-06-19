#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Luogo {
  char *nome;
  float x;
  float y;
  struct Luogo *next;
};

void init_stack(struct Luogo **luogo) {
  *luogo = NULL;
}

void append_stack(struct Luogo **luoghi, struct Luogo *luogo) {
  if (*luoghi == NULL) {
    *luoghi = luogo;
    return;
  } else {
    struct Luogo *temp = *luoghi;
    while (temp -> next != NULL) {
      temp = temp->next;
    }
    temp->next = luogo;
  }
}

void load_from_file(struct Luogo **luoghi) {
  FILE *fp = fopen("coordinate.txt", "r");

  if (fp == NULL) {
    printf("\nErrore nella lettura del file\n");
    return;
  }

  char nome[255] = {0};
  float x, y;

  while (fscanf(fp, "%s %f %f", nome, &x, &y) != EOF) {
    struct Luogo *new = malloc(sizeof(struct Luogo));

    new -> nome = malloc(sizeof(char) * 255);
    strcpy(new -> nome, nome);
    new -> x = x;
    new -> y = y;

    append_stack(luoghi, new);
  }
}

void print_list(struct Luogo **luoghi) {
   struct Luogo *temp = *luoghi;

   while (temp != NULL) {
     printf("\n%s, %f, %f\n", temp->nome, temp->x,temp->y);
     temp = temp->next;
   }
}

void delete_dup(struct Luogo **luoghi) {

    struct Luogo *temp = *luoghi;

    while (temp != NULL) {
        struct Luogo *temp2 = temp->next;
        struct Luogo *prev = temp;
        while (temp2 != NULL) {
            if (strcmp(temp->nome, temp2->nome) == 0) {
                prev->next = temp2->next;
                free(temp2);
                temp2 = prev->next;
            } else {
                prev = temp2;
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}

int len_stack(struct Luogo **luoghi) {
  int i = 0;

  struct Luogo *temp = *luoghi;

  while (temp != NULL) {
    i++;
    temp = temp -> next;
  }

  return i;
}


//d) scriva un file dove a ognuna delle città presenti nella lista viene associata la città ad essa più vicina e la relativa
//distanza.

void scrivi_matrix(struct Luogo **luoghi, float **A, int n) {
    //l file prodotto deve essere, ad esempio, il seguente:
    //Harad Erebor 28.1114

    FILE *fp = fopen("distanze.txt", "w");

    if (fp == NULL) {
        printf("\nErrore nella scrittura del file\n");
        return;
    }

    struct Luogo *temp = *luoghi;

   

    fclose(fp);
}

int main() {
  struct Luogo *l;

  init_stack(&l);

  load_from_file(&l);

  print_list(&l);

  delete_dup(&l);

  printf("\n------\n");
  
  print_list(&l);

  printf("\n------\n");

  float **A;

  int n = 0;

  n = len_stack(&l);

    A = malloc(sizeof(float *) * n);

    for (int i = 0; i < n; i++) {
        A[i] = malloc(sizeof(float) * n);
    }

    struct Luogo *temp = l;


    //c) costruisca una matrice quadrata A di dimensione nxn (n è il numero di città differenti presenti nella lista) dove
    //A(i,j) è la distanza fra la città i-esima e la città j-esima; ricordate che il quadrato della distanza fra due punti (x1,
    //y1), (x2, y2) sul piano è data da (x1-x2)2 + (y1-y2)2 ; stampare la matrice a schermo;
    //d) scriva un file dove a ognuna delle città presenti nella lista viene associata la città ad essa più vicina e la relativa
    //distanza.

    int i = 0;

    while (temp != NULL) {
        struct Luogo *temp2 = l;
        int j = 0;
        while (temp2 != NULL) {
            A[i][j] = sqrt(pow(temp->x - temp2->x, 2) + pow(temp->y - temp2->y, 2));
            j++;
            temp2 = temp2->next;
        }
        i++;
        temp = temp->next;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%f ", A[i][j]);
        printf("\n");
    }

    scrivi_matrix(A, n);


  printf("\nFinito\n");

  return 0;
}
