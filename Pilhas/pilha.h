#ifndef PILHA_H
#define PILHA_H

#include "paciente.h"

typedef struct {
    paciente *topo; 
} Pilha;

void inicializarPilha(Pilha *p);
void empilhar(Pilha *p, paciente *paciente);
paciente* desempilhar(Pilha *p);
void mostrarPilha(Pilha *p);
void destruirPilha(Pilha *p);

#endif