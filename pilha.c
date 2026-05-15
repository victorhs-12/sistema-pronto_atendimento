#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}

int pilhaVazia(Pilha *p) {
    return (p->topo == NULL);
}

void empilhar(Pilha *p, paciente p_dados) {
    NoPilha *novo = (NoPilha*)malloc(sizeof(NoPilha));
    if (novo == NULL) return;
    
    novo->dados = p_dados;
    novo->prox = p->topo;
    p->topo = novo;
}

paciente desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        paciente vazio = {0};
        return vazio;
    }
    NoPilha *temp = p->topo;
    paciente dados = temp->dados;
    
    p->topo = p->topo->prox;
    free(temp);
    return dados;
}

void mostrarPilha(Pilha *p) {
    NoPilha *aux = p->topo;
    printf("\n--- HISTÓRICO DE PACIENTES ATENDIDOS ---\n");
    while (aux != NULL) {
        printf("Nome: %-20s | Prioridade: %d\n", aux->dados.nome_paciente, aux->dados.prioridade);
        aux = aux->prox;
    }
}

void destruirPilha(Pilha *p) {
    while (!pilhaVazia(p)) {
        desempilhar(p);
    }
}