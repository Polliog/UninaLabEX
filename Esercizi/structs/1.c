
//Difficoltà: easy
//L'University of Street dispone le informazioni degli studenti del Corso di Laurea in Scienze informatiche in specifiche strutture dati formate dai seguenti campi:
//    matricola: campo di testo di al più 10 caratteri alfanumerici
//    nome: campo di testo di al più 20 caratteri alfabetici
//    cognome: campo di testo di al più 20 caratteri alfabetici
//    implementare una struttura dati Elenco con politica di accesso pila (Last In First Out) in grado di memorizzare le informazioni di tutti gli studenti. I dati dovranno essere memorizzati in un array di struct di dimensione fissata (50 elementi).
//    Implementare una funzione main() che dia all'utente la possibilità di inserire i dati di 3 studenti da tastiera.
//    visualizzare gli studenti caricati seguendo la politica di accesso.


#include <stdio.h>

struct Studente {
    char matricola[10];
    char nome[20];
    char cognome[20];
};

struct Elenco {
    struct Studente studenti[50];
    int n;
};

void push(struct Elenco *elenco, struct Studente studente) {
    elenco->studenti[elenco->n] = studente;
    elenco->n++;
}

void readElenco(struct Elenco elenco) {
    for (int i = elenco.n - 1; i >= 0; i--) {
        printf("%s %s %s\n", elenco.studenti[i].matricola, elenco.studenti[i].nome, elenco.studenti[i].cognome);
    }
}

int main() {
    struct Elenco elenco;
    struct Studente studente;

    elenco.n = 0;

    int idx = 0;

    while (idx != -1) {
        printf("Inserisci 1 per aggiungere uno studente, 2 per mostrare l'elenco, -1 per uscire: \n");
        scanf("%d", &idx);

        switch (idx) {
            case 1:
                printf("Inserisci matricola: ");
                scanf("%s", studente.matricola);
                printf("Inserisci nome: ");
                scanf("%s", studente.nome);
                printf("Inserisci cognome: ");
                scanf("%s", studente.cognome);
                push(&elenco, studente);
                break;
            case 2:
                readElenco(elenco);
                break;
            case -1:
                break;
            default:
                printf("Inserisci un valore valido\n");
                break;
        }
    }

}