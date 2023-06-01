//L'impiccato
//Scrivere un programma che effettui una simulazione del classico gioco dell'Impiccato su una frase, così definito:
//
//viene assegnato all'utente un numero massimo di tentativi con cui può indovinare una frase (e.g., 5)
//viene presentata all'utente una serie di asterischi che indicano la struttura della frase, i.e. da quante lettere ogni parola è composta e quante parole sono e.g. ** *** ****** indica che la frase è costituita da 3 parole rispettivamente di 2, 3 e 6 lettere. Eventuali lettere accentate, apostrofi, segni di punteggiatura e cifre numeriche devono essere visualizzati di default, e.g., la frase "l'anno è bisestile" dovrà essere presentata come
//*'**** è *********
//
//L'utente può quindi scegliere se:
//
//fornire una lettera: scegliere una lettera (maiuscola o minuscola non deve far differenza), se la lettera è contenuta nella frase, tutte le sue corrispondenze vengono svelate (ossia gli asterischi corrispondenti vengono tolti) altrimenti viene consumato un tentativo.
//provare a dare la soluzione: l'utente può provare a digitare la frase, se la soluzione è corretta il giocatore ha vinto, altrimenti viene consumato un tentativo
//Quando il numero dei tentativi raggiunge zero, l'utente ha perso ed il gioco termina.
//
//L'insieme delle frasi possibili è contenuto in un file di testo dizionario.txt contenente una sequenza di frasi (e null'altro). Ogni frase deve essere lunga al massimo 255 caratteri. All'inizio del gioco, il programma sceglierà casualmente una frase tra tutte le frasi disponibili.

#include <stdio.h>
#include <time.h>
#include <string.h>

#define TRIES 5;

void cerca_frase(char *frase) {
    FILE *fp = fopen("dizionario.txt", "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file");
        return;
    }

    int frasiTotali = 0;
    char tempFrase[255];

    while (fgets(tempFrase, sizeof(tempFrase), fp) != NULL) {
        frasiTotali++;
    }

    srand(time(NULL));
    int selezione =  0 + rand() % (frasiTotali - 0 + 1);

    int i = 0;

    FILE *fp2 = fopen("dizionario.txt", "r");
    if (fp2 == NULL) {
        printf("Errore nell'apertura del file");
        return;
    }

    while (fgets(tempFrase, sizeof(tempFrase), fp2) != NULL) {
        if (i == selezione) {
            break;
        }
        i++;
    }

    fclose(fp);
    fclose(fp2);

    for (int i = 0; i < sizeof(tempFrase); i++) {
        frase[i] = tempFrase[i];
    }


    //rendi minuscola frase

    for (int i = 0; i < sizeof(frase); i++) {
        if (frase[i] >= 'A' && frase[i] <= 'Z') {
            frase[i] = frase[i] + 32;
        }
    }
}

void censura_frase(char *frase, char *fraseCensurata) {
    int i = 0;
    //censura tutto tranne spazi, punteggiatura e apostrofi e lettere accentate
    while (frase[i] != '\0') {
        if (frase[i] == ' ' || frase[i] == ',' || frase[i] == '.' || frase[i] == '\'' || frase[i] == 'à' || frase[i] == 'è' || frase[i] == 'é' || frase[i] == 'ì' || frase[i] == 'ò' || frase[i] == 'ù') {
            fraseCensurata[i] = frase[i];
        } else {
            fraseCensurata[i] = '*';
        }
        i++;
    }

    fraseCensurata[strlen(fraseCensurata) - 1] = '\0';
}


void inserisci_lettera(char *frase, char *fraseCensurata, char lettera) {
    int i = 0;
    while (frase[i] != '\0') {
        //se la lettera e' presente nella frase anche se miniscula o maiuscola
        if (frase[i] == lettera || frase[i] == lettera - 32 || frase[i] == lettera + 32) {
            fraseCensurata[i] = frase[i];
        }
        i++;
    }
}

int tentativo_soluzione(char *frase, char *fraseTentativo) {
    int i = 0;
    while (frase[i] != '\0') {
        if (fraseTentativo[i] != frase[i] && fraseTentativo[i] != frase[i] - 32 && fraseTentativo[i] != frase[i] + 32) {

            if (fraseTentativo[i] == 10 || fraseTentativo[i] == 0) {
                i++;
                continue;
            }

            printf("%d\n", fraseTentativo[i]);
            printf("%d\n", frase[i]);
            return 1;
        }
        i++;
    }
    return 0;
}

int main() {
    char frase[255];
    cerca_frase(frase);

    printf("%s\n", frase);

    char fraseNascosta[255] = {'\0'};

    censura_frase(frase, fraseNascosta);
    printf("%s\n", fraseNascosta);

    int actualTries = TRIES;

    int scelta = 0;

    while (actualTries > 0) {
        printf("Tentativi rimasti: %d\n\n", actualTries);
        printf("1) Inserisci una lettera\n");
        printf("2) Prova a dare la soluzione\n");
        printf("0) Esci\n\n");

        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf("Inserisci una lettera: ");
                char lettera;
                scanf("%c", &lettera);
                inserisci_lettera(frase, fraseNascosta, lettera);
                printf("%s\n", fraseNascosta);
                actualTries--;
                break;
            case 2:
                printf("Inserisci la soluzione: ");
                char fraseTentativo[255];
                scanf(" %[^\n]s", fraseTentativo);
                switch (tentativo_soluzione(frase, fraseTentativo)) {
                    case 0:
                        printf("\n\nBravo hai vinto!\n\n");
                        return 0;
                    case 1:
                        printf("Frase errata, riprova\n");
                        printf("Frase inserita: %s\n", fraseTentativo);
                        actualTries--;
                        break;
                    default:
                        break;
                }
                break;
            case 0:
                return 0;
            default:
                printf("Scelta non valida\n");
                break;
        }
    }

    printf("Hai perso!\n");
    return 0;
}