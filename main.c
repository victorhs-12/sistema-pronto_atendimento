#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fila.h"
#include "pilha.h"

// Função para processar o arquivo de texto
void processarArquivo(const char *dados, Fila *f) {
    FILE *arquivo = fopen(dados, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", dados);
        return;
    }

    char linha[256];
    // Ignorar a primeira linha se for cabeçalho (ID,Nome,Prioridade,Hora)
    // fgets(linha, sizeof(linha), arquivo); 

    while (fgets(linha, sizeof(linha), arquivo)) {
        paciente p;
        // Divide os dados separados por vírgula
        if (sscanf(linha, "%d,%99[^,],%d,%5s", &p.id, p.nome_paciente, &p.prioridade, p.hora_chegada) == 4) {
            strcpy(p.hora_atendimento, "");
            enfileirarPrioridade(f, p);
        }
    }
    fclose(arquivo);
}

int main() {
    Fila fila_espera;
    Pilha pilha_atendidos;
    
    inicializarFila(&fila_espera);
    inicializarPilha(&pilha_atendidos);

    // O nome do arquivo que será testado (Crie um arquivo dados.txt na mesma pasta)
    const char *arquivoTeste = "dados.csv"; 

    printf("=== INICIANDO PROCESSAMENTO: %s ===\n", arquivoTeste);
    
    // Inicia a marcação de tempo
    clock_t start_time = clock();

    // 1. Lê do arquivo e joga na Fila
    processarArquivo(arquivoTeste, &fila_espera);

    // 2. Simula o atendimento de todos os pacientes da fila
    while (!filaVazia(&fila_espera)) {
        paciente atendido = desenfileirar(&fila_espera);
        strcpy(atendido.hora_atendimento, "12:00"); // Simulação
        empilhar(&pilha_atendidos, atendido);
    }

    // Para a marcação de tempo
    clock_t end_time = clock();
    double tempo_gasto = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Teste da Regra: Desfazer o último atendimento
    desfazerAtendimento(&fila_espera, &pilha_atendidos);

    // Exibe histórico e performance
    mostrarPilha(&pilha_atendidos);
    printf("\nTempo de Execucao (%s): %f segundos\n", arquivoTeste, tempo_gasto);

    // Limpeza de memória estrita para o Valgrind
    liberarFila(&fila_espera);
    destruirPilha(&pilha_atendidos);

    return 0;
}