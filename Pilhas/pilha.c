#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}

void empilhar(Pilha *p, paciente *paciente) {
    paciente->prox = p->topo;
    p->topo = paciente; 
}

paciente* desempilhar(Pilha *p) {
    if (p->topo == NULL) return NULL;
    
    paciente *temp = p->topo;
    p->topo = p->topo->prox; 
    temp->prox = NULL;    
    return temp;        
}

void mostrarPilha(Pilha *p) {
    paciente *aux = p->topo;
    printf("\n--- HISTÓRICO DE PACIENTES ATENDIDOS ---\n");
    while (aux != NULL) {
        printf("Nome: %-20s | Prioridade: %d\n", aux->nome_paciente, aux->prioridade);
        aux = aux->prox;
    }
}

void destruirPilha(Pilha *p) {
    while (p->topo != NULL) {
        paciente *temp = desempilhar(p);
        free(temp);
    }
}