#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include <string.h>


void choseWord(char *word) {
   //int selezione =  0 + rand() % (frasiTotali - 0 + 1);
   FILE *fp = fopen("dizionario.txt", "r");

   if (fp == NULL) {
     printf("\nErrore nella lettura del file\n");
     return;
   }

   int frasiTotali = 0;
   char tempFrase[255] = {0};
   
   while (fgets(tempFrase, 255, fp) != NULL) {
     frasiTotali++;
   }

   srand(time(NULL));
   int selezione =  0 + rand() % (frasiTotali - 0 + 1);
   
   fclose(fp);

   FILE *fp2 = fopen("dizionario.txt", "r");

   if (fp2 == NULL) {
     printf("\nErrore nell'apertura del file n2\n");
     return;
   }

   int i = 0;
   while (fgets(tempFrase, 255, fp2) != NULL) {
      if (i = selezione) {
        break;
      }
      i++;
   }

   fclose(fp2);
   
   for (int i = 0; i < sizeof(tempFrase); i++) {
     word[i] = tempFrase[i];
   }

   for (int i = 0; i < sizeof(word); i++) {
     if (word[i] >= 'A' && word[i] <= 'Z') {
        word[i] = word[i] + 32;
     }
   }
}

void censura_frase(char *frase, char *fraseCensurata) {
  int i = 0;

  while (frase[i] != '\0') {
     if (frase[i] == ' ' || frase[i] == ',' || frase[i] == '.' || frase[i] == '\'' || frase[i] > 128) {
        fraseCensurata[i] = frase[i];
     } else {
        fraseCensurata[i] = '*';
     }
     i++;
  }

  fraseCensurata[strlen(fraseCensurata) - 1] = '\0';
}

void inserisci_lettera(char *frase, char *censurata, char lettera) {
  int i = 0;

  while (frase[i] != '\0') {
    if (frase[i] == lettera || frase[i] == lettera - 32 || frase[i] == lettera + 32) {
      censurata[i] = frase[i];
    }
    i++;
  }
}

int tentativo_soluzione(char *frase, char *tentativo) {
  int i = 0;
  while(frase[i] != '\0') {
   if (tentativo[i] != frase[i] && tentativo[i] != frase[i] - 32 && tentativo != frase[i] + 32) {
      if (tentativo[i] == 10 || tentativo[i] == 0) {
        i++;
        continue;
      }

      return 1;
   }

   i++;
  }

  return 0;
}
