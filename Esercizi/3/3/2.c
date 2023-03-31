//implementare una funzione che, data in input una stringa, restituisca due variabili, la prima contenente la prima consonante presente nell stringa, la seconda variabile contenente l'ultima vocale.

#include <stdio.h>

void checkString(char*, char*, char*);

int main() {

    printf("Inserisci una stringa:");
    char s[100];
    scanf("%s", s);

    char pc, lv;
    char *pc_p, *lv_p;

    pc_p = &pc;
    lv_p = &lv;

    checkString(s, pc_p, lv_p);
    printf("%c\n", pc);
    printf("%c\n", lv);
}

void checkString(char*s,char*pc,char*lv) {
    int pc_set = 0;

    for (int i = 0; i < sizeof(s);i++) {
        switch (s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                *lv = s[i];
                break;
            default:
                if (!pc_set) {
                    *pc = s[i];
                    pc_set = 1;
                }
                break;
        }
    }
}
