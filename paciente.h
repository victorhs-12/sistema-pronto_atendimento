#ifndef PACIENTE_H
#define PACIENTE_H

#define MAX_PRIORIDADE 5 // Supondo 5 como a maior urgência (Emergência)

typedef struct {
    int id;
    char nome_paciente[100];
    int prioridade;
    char hora_chegada[6];
    char hora_atendimento[6];
} paciente;

#endif