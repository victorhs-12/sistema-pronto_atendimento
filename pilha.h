#ifndef PILHA_H
#define PILHA_H

#include "paciente.h"

typedef struct no_pilha {
    paciente dados;
    struct no_pilha *prox;
} NoPilha;

typedef struct {
    NoPilha *topo;
} Pilha;

void inicializarPilha(Pilha *p);
int pilhaVazia(Pilha *p);
void empilhar(Pilha *p, paciente p_dados);
paciente desempilhar(Pilha *p);
void mostrarPilha(Pilha *p);
void destruirPilha(Pilha *p);

#endif