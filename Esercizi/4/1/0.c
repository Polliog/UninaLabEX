//Data una matrice quadrata, scrivere le seguenti funzioni:
//exists_row_same_elements(...): restituisce 1 se esiste almeno una riga nella matrice avente tutti gli elementi uguali, 0 altrimenti;
//exists_col_same_elements(...): restituisce 1 se esiste almeno una colonna nella matrice avente tutti gli elementi uguali, 0 altrimenti;
//exists_diag_same_elements(...): restituisce 1 se esiste la diagonale principale o la secondaria ha tutti elementi uguali, 0 altrimenti;
//esists_something_same_elements(...): restituisce 1 se esiste una riga, o una colonna, o la diagonale principale, o la diagonale secondaria con tutti gli elementi uguali. Si possono sfruttare le funzioni definite nei punti precedenti.

#include <stdio.h>
#define row 5
#define col 5

int exists_row_same_elements(int M[][col]) {
    int e;
    int n;

    for (int i = 0; i < row; i++) {
        e = 1;
        n = M[i][0];
        for (int j = 0; j < col; j++) {
            if (M[i][j] != n) {
                e = 0;
            }
        }
        if (e) break;
    };

    return e;
}

int exists_col_same_elements(int M[][col]) {
    int e;
    int n;

    for (int i = 0; i < col; i++) {
        e = 1;
        n = M[0][i];
        for (int j = 0; j < row; j++) {
            if (M[j][i] != n) {
                e = 0;
            }
        }
        if (e) break;
    };

    return e;
}

int exists_diag_same_elements(int M[][col]) {
    int e = 1;
    int n = M[0][0];

    for (int i = 0; i < row; i++) {
        if (M[i][i] != n) {
            e = 0;
        }
    }

    if (e) return e;

    e = 1;
    n = M[0][row - 1];

    for (int i = 0; i < row; i++) {
        if (M[i][row - i - 1] != n) {
            e = 0;
        }
    }

    return e;
}

int esists_something_same_elements(int M[][col]) {
    return exists_row_same_elements(M) || exists_col_same_elements(M) || exists_diag_same_elements(M);
}

int main() {
    int M[row][col] = {
            {1,2,3,4,5},
            {6,1,8,5,10},
            {11,2,5,15,16},
            {17,5,19,1,21},
            {5,2,24,25,1}
    };

    printf("exists_row_same_elements: %d\n", exists_row_same_elements(M));
    printf("exists_col_same_elements: %d\n", exists_col_same_elements(M));
    printf("exists_diag_same_elements: %d\n", exists_diag_same_elements(M));
    printf("esists_something_same_elements: %d\n", esists_something_same_elements(M));
}