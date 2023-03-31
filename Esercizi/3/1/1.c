//Vettori
//il vettore somma \mathbf{s}\in \mathbb{R}^N tra due vettori \mathbf{v} \in \mathbb{R}^N e \mathbf{w}\in \mathbb{R}^N è definito formalmente come: s_{i} = v_i + w_i, \forall_{ 1\leq i \leq R}
//in altri termini:
//\mathbf{s} = (v_1+w_1, v_2+w_2, \dots , v_N+ w_n) scrivere un programma che, dati due vettori, calcoli e visualizzi il vettore somma risultante

#include <stdio.h>

int main() {
    int v1[3] = {1,2,3};
    int v2[3] = {4,5,6};
    int v3[3];

    for (int i = 0; i < 3; i++) {
        v3[i] = v1[i] + v2[i];
    }

    for (int i = 0; i < 3; i++) {
        printf("%d ", v3[i]);
    }
}