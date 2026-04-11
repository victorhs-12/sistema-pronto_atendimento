#include "merge_sort.h"
#include "insertion_sort.h"
#include <stdlib.h>
#include <string.h>

void merge(Paciente arr[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    Paciente *L = malloc(n1 * sizeof(Paciente));
    Paciente *R = malloc(n2 * sizeof(Paciente));

    for (int i = 0; i < n1; i++) L[i] = arr[esq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (strcmp(L[i].nome, R[j].nome) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void hybrid_merge_sort(Paciente arr[], int esq, int dir) {

    if (dir - esq + 1 < 50) {
        insertion_sort(arr, esq, dir);
        return;
    }

    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

        hybrid_merge_sort(arr, esq, meio);
        hybrid_merge_sort(arr, meio + 1, dir);

        merge(arr, esq, meio, dir);
    }
}