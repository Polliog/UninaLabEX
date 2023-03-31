//mplementare due funzioni:
//
//lock(...): accetta come parametro una variabile di tipo int; se questa variabile è ≠0,la mette a 0 e restituisce 1
//(ossia operazione andata a buon fine); se è ==0 la si lascia a zero e si restituisce 0 (ossia operazione non effettuata perchè, appunto, inutile in quanto la variabile già è a 0 )
//unlock(...): accetta una variabile di tipo int; se questa variabile è ==0, la mette a 1 e si restituisce 1 ; se la variabile è ≠0
//la si lascia al valore che ha e si restituisce 0. Esempio di main():

#include <stdio.h>

int lock(int*);
int unlock(int*);

int main() {
    int v = 0;
    int *v_p = &v;
    printf("%d", lock(v_p));
    printf("%d", lock(v_p));
    printf("%d", unlock(v_p));
    printf("%d", unlock(v_p));
    return 0;
}

int lock(int *v) {
    if (*v == 0) {
        *v = 1;
        return 1;
    } else {
        return 0;
    }
}

int unlock(int *v) {
    if (*v == 1) {
        *v = 0;
        return 1;
    } else {
        return 0;
    }
}