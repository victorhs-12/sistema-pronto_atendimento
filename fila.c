#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->total_entradas = 0;
}

int filaVazia(Fila *f) {
    return (f->inicio == NULL);
}

// Função interna para reordenar a fila caso as prioridades mudem (Bubble Sort em Lista Encadeada)
void ordenarFila(Fila *f) {
    if (f->inicio == NULL || f->inicio->prox == NULL) return;
    
    int trocou;
    NoFila *atual;
    NoFila *ultimo = NULL;
    
    do {
        trocou = 0;
        atual = f->inicio;
        
        while (atual->prox != ultimo) {
            // Se o atual tem prioridade menor que o próximo, troca os dados
            if (atual->dados.prioridade < atual->prox->dados.prioridade) {
                paciente temp = atual->dados;
                atual->dados = atual->prox->dados;
                atual->prox->dados = temp;
                trocou = 1;
            }
            atual = atual->prox;
        }
        ultimo = atual;
    } while (trocou);
}

// Função interna: Aumenta a prioridade a partir do 6º paciente
void aumentarPrioridade(Fila *f) {
    NoFila *atual = f->inicio;
    int pos = 1;
    
    while (atual != NULL) {
        if (pos >= 6 && atual->dados.prioridade < MAX_PRIORIDADE) {
            atual->dados.prioridade++;
        }
        atual = atual->prox;
        pos++;
    }
    ordenarFila(f); // Reordena para refletir as novas prioridades
}

void enfileirarPrioridade(Fila *f, paciente p) {
    NoFila *novo = (NoFila*)malloc(sizeof(NoFila));
    if (novo == NULL) return;
    
    novo->dados = p;
    novo->prox = NULL;
    f->total_entradas++;

    // Lógica de inserção mantendo a ordem de prioridade
    if (filaVazia(f) || p.prioridade > f->inicio->dados.prioridade) {
        novo->prox = f->inicio;
        f->inicio = novo;
        if (f->fim == NULL) f->fim = novo;
    } else {
        NoFila *atual = f->inicio;
        while (atual->prox != NULL && atual->prox->dados.prioridade >= p.prioridade) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
        if (novo->prox == NULL) f->fim = novo;
    }

    // Regra do PDF: A cada 5 novos pacientes, aumentar a prioridade
    if (f->total_entradas % 5 == 0) {
        aumentarPrioridade(f);
    }
}

paciente desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        paciente vazio = {0};
        return vazio;
    }
    NoFila *aux = f->inicio;
    paciente p = aux->dados;
    
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(aux);
    return p;
}

// Regra do PDF: Retirar do histórico e jogar para o início da fila
void desfazerAtendimento(Fila *f, Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Nao ha atendimentos para desfazer.\n");
        return;
    }
    
    paciente p_desfeito = desempilhar(p);
    p_desfeito.prioridade = MAX_PRIORIDADE; // Ganha prioridade máxima
    
    NoFila *novo = (NoFila*)malloc(sizeof(NoFila));
    novo->dados = p_desfeito;
    
    // Força a inserção no início absoluto da fila
    novo->prox = f->inicio;
    f->inicio = novo;
    if (f->fim == NULL) f->fim = novo;
    
    printf(">> Atendimento de %s desfeito. Movido para o topo da fila!\n", p_desfeito.nome_paciente);
}

void liberarFila(Fila *f) {
    while (!filaVazia(f)) {
        desenfileirar(f);
    }
}