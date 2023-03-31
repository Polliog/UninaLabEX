//il prodotto scalare $p\in \mathbb{R}$ tra due vettori $\mathbf{v} \in \mathbb{R}^N$ e $\mathbf{w}\in \mathbb{R}^N$ è definito formalmente come:
//$$p = \sum\limits_{i=1}^N v_i\cdot w_i$$
//scrivere un programma che, dati due vettori, calcoli e visualizzi il loro prodotto scalare

#include <stdio.h>

int main() {
    int v1[3] = {1,2,3};
    int v2[3] = {4,5,6};
    int s = 0;

    for (int i = 0; i < 3; i++) {
        s += v1[i] * v2[i];
    }

    printf("%d", s);
}