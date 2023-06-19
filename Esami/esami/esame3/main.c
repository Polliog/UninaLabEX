#include <stdio.h>
#include "functions.h"

int main() {
  struct Bacheca *b;

  init_bacheca(&b);

  load_user_from_file(&b, "utente42.txt");

  printf("\nSeleziona un opzione per ognuno dei seguenti post:\n1: Fermarsi\n2: Prossimo Post\n3: Aggiungi Like\n4: Condividi\n");

  while (b != NULL) {
   printf("\nContenuto: %sLikes: %i\n", b -> msg, b -> n_like);
   int i = -1;
   scanf("%d", &i);

   switch (i) {
     case 1:
       return 0;
     case 2:
       break;
     case 3:
       b -> n_like += 1;
       break;
     case 4:
       condividi(b);
       break;
   }
   
   b = b->next;
  }

  free_memory(&b);

  printf("\nFinito\n");
}
