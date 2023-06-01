//Si vuole realizzare un programma che simuli una cassaforte i cui dati sono contenuti in un file binario.
//
//Tale cassaforte sarà costituita da:
//
//una combinazione (numero intero)
//un ammontare di denaro
//All'utente deve essere presentato un menù in cui può scegliere se:
//
//creare una nuova cassaforte
//aprire la cassaforte
//inserire denaro
//prelevare denaro
//visualizzare il denaro
//cambiare la combinazione
//chiudere la cassaforte
//uscire dal programma
//La creazione di una nuova cassaforte distruggerà i dati della precedente e darà la possibilità all'utente di impostare una combinazione.
//
//Tutte le operazioni potranno essere effettuate solo se la cassaforte è aperta. Una volta chiusa la cassaforte, il file binario dovrà essere aggiornato con le nuove informazioni.

#include <stdio.h>


void crea_cassaforte() {
    FILE *fp = fopen("cassaforte.txt", "w");
    int codice;
    printf("Inserisci un codice per la cassaforte:\n");
    scanf("%d", &codice);

    fprintf(fp, "%d\n", codice);

    int ammontare;
    printf("Inserisci l'ammontare di denaro:\n");
    scanf("%d", &ammontare);

    fprintf(fp, "%d", ammontare);

    fclose(fp);

}

int apri_cassaforte() {
    FILE *fp = fopen("cassaforte.txt", "r");
    if (fp == NULL) {
        printf("Cassaforte non esistente");
        return -1;
    }

    int codice;
    printf("Inserisci il codice per la cassaforte:\n");
    scanf("%d", &codice);

    int codiceSalvato;
    fscanf(fp, "%d", &codiceSalvato);

    if (codice == codiceSalvato) {
        printf("Cassaforte aperta\n");
        return 1;
    } else {
        printf("Codice errato\n");
        return 0;
    }
}

void view_cassaforte() {
    FILE *fp = fopen("cassaforte.txt", "r");
    if (fp == NULL) {
        printf("Cassaforte non esistente");
        return;
    }

    int codice;
    fscanf(fp, "%d", &codice);

    int ammontare;
    fscanf(fp, "%d", &ammontare);

    printf("Codice: %d\nAmmontare: %d\n", codice, ammontare);
}

void gestisci_denaro(int mode) {
    FILE *fp = fopen("cassaforte.txt", "r");
    if (fp == NULL) {
        printf("Cassaforte non esistente");
        return;
    }

    int codice;
    int ammontare;
    fscanf(fp, "%d", &codice);
    fscanf(fp, "%d", &ammontare);

    int deposito;

    if (mode == 0) {
        printf("Inserisci l'ammontare da depositare:\n");
    } else {
        printf("Inserisci l'ammontare da prelevare:\n");
    }

    scanf("%d", &deposito);

    if (mode == 0) {
        ammontare += deposito;
    } else {
        ammontare -= deposito;
    }

    fclose(fp);

    fp = fopen("cassaforte.txt", "w");

    fprintf(fp, "%d\n", codice);
    fprintf(fp, "%d", ammontare);

    fclose(fp);

    printf("Ammontare: %d\n", ammontare);
}

int main() {
    int status = 0;

    printf("Benvenuto, scegli un opzione:\n");
    int option = -1;
    while (option != 0) {
        printf(
                "1. crea nuova cassaforte (eventuale cassaforte già esistente sarà distrutta)\n"
                "2. apri cassaforte\n"
                "3. visualizza lo stato della cassaforte\n"
                "4. visualizza ammontare\n"
                "5. deposita somma\n"
                "6. preleva somma\n"
                "7. chiudi cassaforte\n"
                "0. esci (eventuali modifiche a cassaforte aperta andranno perse)\n");

        scanf("%d", &option);


        switch (option) {
            case 0:
                return 0;
            case 1:
                crea_cassaforte();
                break;
            case 2:
                if (status == 1) {
                    printf("Cassaforte già aperta\n");
                    break;
                } else {
                    status = apri_cassaforte();
                    break;
                }
            case 3:
            case 4:
                if (status == 1) {
                    view_cassaforte();
                } else {
                    printf("Cassaforte chiusa o inesistente\n");
                }
                break;
            case 5:
                if (status == 1) {
                    gestisci_denaro(0);
                } else {
                    printf("Cassaforte chiusa o inesistente\n");
                }
                break;
            case 6:
                if (status == 1) {
                    gestisci_denaro(1);
                } else {
                    printf("Cassaforte chiusa o inesistente\n");
                }
                break;
            case 7:
                if (status == 1) {
                    status = 0;
                    printf("Cassaforte chiusa\n");
                } else {
                    printf("Cassaforte già chiusa o inesistente\n");
                }
                break;
        }
    }
}