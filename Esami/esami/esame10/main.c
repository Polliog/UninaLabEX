#include <stdio.h>
#include "functions.h"

//prova

int main() {
  struct Post *p;
  init_node(&p);

  load_user_from_file(&p, "messaggi.txt");

  print_nodes(&p);

  struct Post *temp = p;

  while (temp != NULL) {
    print(temp);

    printf("Scegliere un opzione:\n0: fermati\n1: prossimo post\n2: aggiungi like\n3: condividi\n");

    int scelta = -1;
    scanf("%d", &scelta);

    switch (scelta) {
      case 0:
        return 0;
      case 1:
        break;
      case 2:
        temp -> n_like += 1;
        printf("\nNuovi likes: %d\n", temp -> n_like);
        break;
      case 3:
        share_post(temp);
        printf("\nPost condiviso!\n");
        break;
    }

    temp = temp->next;
  }
  printf("\nFinito\n");
}
     
