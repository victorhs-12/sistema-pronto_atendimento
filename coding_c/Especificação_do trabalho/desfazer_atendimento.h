#ifndef DESFAZER_ATENDIMENTO_H
#define DESFAZER_ATENDIMENTO_H

#include "paciente.h"
#include "fila_prioridade.h" 


void reinserirComPrioridadeMaxima(Fila *f, Paciente *p);
void processarArquivo(Fila *fila, Pilha *pilha);

#endif