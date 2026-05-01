void reinserirComPrioridadeMaxima(Fila *f, Paciente *p) {
    p->prioridade = 1;
    p->prox = f->inicio;
    f->inicio = p;
}

void processarArquivo(Fila *fila, Pilha *pilha) {
    FILE *arq = fopen("entrada.txt", "r");

    if (!arq) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    char comando, nome[MAX_NOME];
    int prioridade;

    while (fscanf(arq, " %c", &comando) != EOF) {

        if (comando == 'I') {
            fscanf(arq, "%s %d", nome, &prioridade);
            inserirPaciente(fila, nome, prioridade);
        }
        else if (comando == 'A') {
            Paciente *p = atenderPaciente(fila);
            if (p) {
                printf("Atendido (arquivo): %s\n", p->nome);
                empilhar(pilha, p);
            }
        }
        else if (comando == 'D') {
            Paciente *p = desempilhar(pilha);
            if (p) {
                printf("Desfeito (arquivo): %s\n", p->nome);
                reinserirComPrioridadeMaxima(fila, p);
            }
        }
    }

    fclose(arq);
}

