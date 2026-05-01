#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializarPilha(Pilha *p) {
    p->topo = NULL; // Inicializa a pilha vazia
}

void empilhar(Pilha *p, paciente *paciente) {
    paciente->prox = p->topo; // O novo nó aponta para o antigo topo[cite: 18]
    p->topo = paciente;       // O topo agora é o novo nó[cite: 18]
}

paciente* desempilhar(Pilha *p) {
    if (p->topo == NULL) return NULL; // Proteção contra Underflow[cite: 18]
    
    paciente *temp = p->topo;
    p->topo = p->topo->prox; // Avança o topo para o próximo nó[cite: 18]
    temp->prox = NULL;       // Isola o nó removido
    return temp;             // Retorna o endereço para reinserção na fila[cite: 1]
}

void mostrarPilha(Pilha *p) {
    paciente *aux = p->topo;
    printf("\n--- HISTÓRICO DE PACIENTES ATENDIDOS ---\n");
    while (aux != NULL) {
        printf("Nome: %-20s | Prioridade: %d\n", aux->nome_paciente, aux->prioridade);
        aux = aux->prox; // Navegação sequencial[cite: 18]
    }
}

void destruirPilha(Pilha *p) {
    while (p->topo != NULL) {
        paciente *temp = desempilhar(p);
        free(temp); // Liberação sistemática de cada nó[cite: 18, 39]
    }
}