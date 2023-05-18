//Un amministrativo dell' University of Street a memorizzato i dati di tutti gli studenti in un file di testo così formato:
//ascii
//matricola1
//nome1
//cognome1
//matricola2
//nome2
//cognome2
//    scrivere una funzione load_students_from_file(Elenco,nomefile) in grado di caricare tutti i dati contenuti nel file di testo di nome nomefile all'interno dell' Elenco. Il file di testo ha nome "iscritti.txt".
//    nella funzione main(), caricare tutti gli studenti presenti nel file di testo iscritti.txt in un elenco di studenti utilizzando la funzione load_students_from_file(Elenco,nomefile).
//    visualizzare gli studenti caricati seguendo la politica di accesso.
//    scrivere una funzione write_students_on_file(Elenco, nomefile, start_letter, stop_letter) che scriva all'interno di nomefile tutti e soli gli studenti dell'Elenco aventi cognome con prima lettera nell'intervallo [start_letter,stop_letter]
//    . Il formato di memorizzazione deve essere lo stesso del file di input.
//Considerare la seguente suddivisione in gruppi:
//   primo gruppo: studenti con cognomi dalla A alla G
//secondo gruppo: studenti con cognomi dalla H alla P
//terzo gruppo: studenti con cognomi dalla Q alla Z
//Memorizzare i tre gruppi su memoria di massa rispettivamente nei file gruppo1.txt gruppo2.txt, gruppo3.txt
//visualizzare gli studenti nei 3 file sfruttando le funzioni implementate.


//nel caso non sia stato considerato, modificare l'esercizio precedente affinchè permetta di avere nomi e cognomi contenente spazi
//nel caso non sia stato considerato, modificare l'esercizio precedente affinchè la funzione write_students_on_file(Elenco, nomefile, start_letter, stop_letter) funzioni correttamente sia con cognomi inizianti con lettere maiuscole che minuscole.


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

void load_students_from_file(struct Elenco *elenco, char *nomefile) {
    FILE *fp = fopen(nomefile, "r");

    if (fp == NULL) {
        printf("Errore nell'apertura del file");
        return;
    }
    struct Studente studente;
    while (fscanf(fp, "%s %s %s", studente.matricola, studente.nome, studente.cognome) != EOF) {
        push(elenco, studente);
    }
    fclose(fp);
}

void write_students_on_file(struct Elenco elenco, char *nomefile, char start_letter, char stop_letter) {
    FILE *fp = fopen(nomefile, "w");
    for (int i = 0; i < elenco.n; i++) {
        if (elenco.studenti[i].cognome[0] >= start_letter && elenco.studenti[i].cognome[0] <= stop_letter) {
            fprintf(fp, "%s %s %s\n", elenco.studenti[i].matricola, elenco.studenti[i].nome, elenco.studenti[i].cognome);
        }
    }
    fclose(fp);
}

int main() {
    struct Elenco elenco;
    elenco.n = 0;
    //vanno messi nel cmake-build-debug
    load_students_from_file(&elenco, "iscritti.txt");
    readElenco(elenco);
    write_students_on_file(elenco, "gruppo1.txt", 'A', 'G');
    write_students_on_file(elenco, "gruppo2.txt", 'H', 'P');
    write_students_on_file(elenco, "gruppo3.txt", 'Q', 'Z');
    return 0;
}
