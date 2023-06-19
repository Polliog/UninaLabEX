#include <stdio.h>
#include "functions.h"

int main() {
  char word[255] = {0};
  choseWord(word);

  char censurata[255] = {0};
  censura_frase(word, censurata);

  //printf("\n%s\n", word);
  //printf("\n%s\n", censurata);

  int tentativi = 5;

  while (tentativi > 0) {
    printf("\n------------------------\n");
    printf("\n%s\n", censurata);
    printf("\nTentativi Residui: %d\n", tentativi);
    printf("\nScegli: \n 1: Do una lettera \n 2: Do soluzione \n 0: Esci\n");
    printf("\n------------------------\n");

    int selezione = -1;
    scanf("%d", &selezione);

    getchar();
    
    switch (selezione) {
      case 0:
        return 0;
      case 1:
       printf("\nDigita una lettera: ");
       char lettera;
       scanf("%c", &lettera);
       inserisci_lettera(word, censurata, lettera);
       tentativi--;
       break;
      case 2:
       printf("\nDigita frase: ");
       char tentativo[255];
       scanf(" %[^\n]s", tentativo);

       
    }
  }

  printf("\nFinito\n");
}
