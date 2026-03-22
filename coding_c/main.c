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
        printf("Hora chegada: %s", paciente_no->dados.hora_chegada);;
        printf("\n======================\n");
        
        liberar_no(paciente_no);
        printf("Nó liberado com sucesso.\n");
    }
    else{
        printf("Erro ao alocar nó.\n");
    }
    return 0;
}