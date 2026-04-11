#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "paciente.h"

#include <stdio.h>
#include <string.h>
#include "utils.h"

Paciente ler_paciente() {
    Paciente p;
    char linha[150];

    printf("Digite (ID, Nome Completo, Idade):\n> ");
    
    if (fgets(linha, sizeof(linha), stdin) != NULL) {

        int lidos = sscanf(linha, "%d , %49[^,] , %d", &p.id, p.nome, &p.idade);

        if (lidos < 3) {
            printf("Erro: Use o formato 'ID, Nome, Idade'\n");
            p.id = -1;
        } else {

        }
    }
    return p;
}

void imprimir_paciente(Paciente p) {
    printf("ID: %03d | Nome: %-20s | Idade: %d\n", p.id, p.nome, p.idade);
}

void imprimir_lista_pacientes(Paciente lista[], int tam) {
    printf("\n--- Lista de Pacientes ---\n");
    for (int i = 0; i < tam; i++) {
        imprimir_paciente(lista[i]);
    }
    printf("--------------------------\n");
}