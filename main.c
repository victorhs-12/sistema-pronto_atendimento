#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nome_paciente[100];
    int prioridade;
    char hora_chegada[6];
    char hora_atendimento[6];
} paciente;

typedef struct no
{
    paciente dados;
    struct no *prox;
}no;

no* criar_no(paciente p){
    no *novo_no = (no*)malloc(sizeof(no));
    if (novo_no == NULL)
    {
       return NULL;
    }
    else
    {
        novo_no->dados = p;
    }

    return novo_no;
}

void liberar_no(no* n){
    if (n != NULL)
    {
        free(n);
    }
    
}
typedef struct
{
    no* inicio;
    no* fim;
} fila;

void inicializar_fila(fila* f){
    f->inicio = NULL;
    f->fim = NULL;
}


void enfileirar(fila* f, paciente p){
    no* novo_no = criar_no(p);
    if (novo_no == NULL)
    {
        printf("Erro ao alocar nó.\n");
        return;
    }
    if (f->fim == NULL)
    {
        f->inicio = novo_no;
        f->fim = novo_no;
    }
    else
    {
        f->fim->prox = novo_no;
        f->fim = novo_no;
    }
}

void desenfileirar(fila* f){
    if (f->inicio == NULL)
    {
        printf("Fila vazia.\n");
        return;
    }
    no* temp = f->inicio;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }
    liberar_no(temp);
}

void liberar_fila(fila* f){
    while (f->inicio != NULL)
    {
        desenfileirar(f);
    }
}

void mostrar_fila(fila* f){
    no* atual = f->inicio;
    while(atual != NULL)
    {
        printf("ID: %d, Nome: %s, Prioridade: %d, Hora Chegada: %s\n", atual->dados.id, atual->dados.nome_paciente, atual->dados.prioridade, atual->dados.hora_chegada);
        atual = atual->prox;
    }
}

int main(){
    paciente p;


    printf("Digite o ID do paciente: ");
    scanf("%d", &p.id);
    getchar(); 
    printf("Digite o nome do paciente: ");
    fgets(p.nome_paciente,sizeof(p.nome_paciente), stdin);
    printf("Digite a prioridade do paciente: ");
    scanf("%d", &p.prioridade);
    getchar();
    printf("Digite a hora de chegada do paciente: ");
    fgets(p.hora_chegada,sizeof(p.hora_chegada), stdin);
    printf("Digite a hora de atendimento do paciente: ");
    strcpy(p.hora_atendimento, "");

    no* paciente_no = criar_no(p);
    if (paciente_no != NULL)
    {
        printf("\n=== Dados do Paciente ===\n");
        printf("ID: %d\n", paciente_no->dados.id);
        printf("Nome: %s", paciente_no->dados.nome_paciente);
        printf("Prioridade: %d\n", paciente_no->dados.prioridade);
        printf("Hora chegada: %s", paciente_no->dados.hora_chegada);
        printf("\n======================\n");
        
        liberar_no(paciente_no);
        printf("Nó liberado com sucesso.\n");
    }
    else{
        printf("Erro ao alocar nó.\n");
    }

    fila f;
    inicializar_fila(&f);

    paciente p1 = {1, "João Silva", 2, "10:00", ""};
    paciente p2 = {2, "Maria Santos", 1, "10:15", ""};
    paciente p3 = {3, "Pedro Costa", 3, "10:30", ""};
    
    enfileirar(&f, p1);
    enfileirar(&f, p2);
    enfileirar(&f, p3);
    
    printf("\n=== Fila Atual ===\n");
    mostrar_fila(&f);
    
    printf("\nAtendendo primeiro paciente...\n");
    desenfileirar(&f);
    
    printf("\n=== Fila Após Atendimento ===\n");
    mostrar_fila(&f);
    
    liberar_fila(&f);

    return 0;
}