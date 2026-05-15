#ifndef FILA_H
#define FILA_H

#include "paciente.h"
#include "pilha.h" // Necessário para a função de desfazer

typedef struct no_fila {
    paciente dados;
    struct no_fila *prox;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
    int total_entradas; // Contador para a regra dos 5 pacientes
} Fila;

void inicializarFila(Fila *f);
int filaVazia(Fila *f);
void enfileirarPrioridade(Fila *f, paciente p);
paciente desenfileirar(Fila *f);
void desfazerAtendimento(Fila *f, Pilha *p);
void liberarFila(Fila *f);

#endif