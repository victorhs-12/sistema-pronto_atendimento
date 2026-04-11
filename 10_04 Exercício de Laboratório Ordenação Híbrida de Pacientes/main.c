#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "utils.h"
#include "merge_sort.h"

#define TOTAL_PACIENTES 20

int main() {
    Paciente lista[TOTAL_PACIENTES];
    int i;

    printf("=== Cadastro de %d Pacientes ===\n", TOTAL_PACIENTES);
    printf("Formato esperado: ID, Nome Completo, Idade\n\n");

    // 1. Coleta de dados
    for (i = 0; i < TOTAL_PACIENTES; i++) {
        printf("[%d/%d] ", i + 1, TOTAL_PACIENTES);
        lista[i] = ler_paciente();

        // Tratamento simples caso o sscanf falhe (definido no utils.c)
        if (lista[i].id == -1) {
            printf("Por favor, repita a entrada para este paciente.\n");
            i--; 
        }
    }

    // 2. Exibição antes da ordenação
    printf("\n--- Lista Original (Ordem de Entrada) ---\n");
    imprimir_lista_pacientes(lista, TOTAL_PACIENTES);

    // 3. Execução da Ordenação Híbrida (Merge + Insertion)
    // Ordena de 0 até TOTAL_PACIENTES - 1
    hybrid_merge_sort(lista, 0, TOTAL_PACIENTES - 1);

    // 4. Exibição após a ordenação
    printf("\n--- Lista Ordenada Alfabeticamente ---\n");
    imprimir_lista_pacientes(lista, TOTAL_PACIENTES);

    return 0;
}