#include "insertion_sort.h"
#include <string.h>

void insertion_sort(Paciente arr[], int esq, int dir) {
    for (int i = esq + 1; i <= dir; i++) {
        Paciente chave = arr[i];
        int j = i - 1;

        while (j >= esq && strcmp(arr[j].nome, chave.nome) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}