#ifndef PILHA_H
#define PILHA_H

#include "paciente.h" // Importante para usar a struct comum do projeto

typedef struct {
    paciente *topo; // Ponteiro para o nó do topo
} Pilha;

// Protótipos das operações[cite: 35]
void inicializarPilha(Pilha *p);
void empilhar(Pilha *p, paciente *paciente);
paciente* desempilhar(Pilha *p); // Vital para a função "Desfazer"
void mostrarPilha(Pilha *p);
void destruirPilha(Pilha *p); // Obrigatório para evitar vazamento de memória[cite: 18, 39]

#endif