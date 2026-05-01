int main() {
    Fila fila;
    Pilha pilha;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    int op;
    char nome[MAX_NOME];
    int prioridade;

    do {
        printf("\n1 - Inserir\n2 - Atender\n3 - Mostrar Pilha\n0 - Sair\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
            printf("Nome: ")
            scanf("%s", nome);
            printf("Prioridade: ");
            scanf("%d" , &prioridade);
            inserirPaciente(&fila, nome, prioridade);
            break;

            case 2: {
                Paciente *p = atenderPaciente(&fila);
                if (p) {
                    printf("Atendido: %s\n", p->nome);
                    empilhar(&pilha, p);
                } else {
                    printf("Fila vazia!\n");
                }
                break;
            }

            case 3:
                mostrarPilha(&pilha);
                break;
        }
    } while(op != 0);
    
    return 0;
}