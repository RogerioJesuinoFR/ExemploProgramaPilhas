#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct no{
    int info;
    struct no *prox;
} No;

No *criarPilha(){
    return NULL;
}

void empilhar(No **topo, int valor){
    No *novo = malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro: falha na alocação de memória.\n");
        return;
    }

    novo->info = valor;
    novo->prox = *topo;
    *topo = novo;
}

void retirar(No **topo){
    if(*topo == NULL){
        printf("\nA pilha ja esta vazia!\n\n");
        return;
    }

    No *aux = *topo;
    *topo = (*topo)->prox;
    free(aux);
    printf("Elemento do topo retirado.\n");
}

imprimirPilha(No *topo){
    No *atual = topo;
    while(atual != NULL){
        printf("%d\n", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}

int main(){
    int opcao, valor;
    No *topo = NULL;
    bool pilhaCriada = false;
    
    do{
        printf("\nSelecione a opcao desejada:\n\t1 - Criar uma pilha\n\t2 - Incluir elemento\n\t3 - Excluir elemento\n\t4 - Consultar elementos da pilha\n\t5 - Sair\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                printf("\n\n=============================================\n\n");
                if(pilhaCriada == false){
                    topo = criarPilha();
                    pilhaCriada = true;
                    printf("Pilha criada.\n");         
                    break;
                } else {
                    printf("\nVoce ja possui uma fila criada!\n");
                }
            case 2:
                printf("\n\n=============================================\n\n");
                if(pilhaCriada){
                    printf("\nInforme o valor que deseja incluir na pilha:\n");
                    scanf("%d", &valor);
                    empilhar(&topo, valor);
                    printf("\nElemento empilhado.\n");
                } else {
                    printf("Erro: A pilha nao foi criada.\n");
                }
                break;
            case 3:
                printf("\n\n=============================================\n\n");
                if(pilhaCriada){
                    retirar(&topo);
                } else {
                    printf("\nA pilha ja esta vazia!\n\n");
                }
                break;
            case 4:
                printf("\n\n=============================================\n\n");
                if(topo != NULL){
                    printf("\nOs elementos da pilha sao:\n");
                } else {
                    printf("\nNao ha elementos na pilha.\n");
                }
                imprimirPilha(topo);
                break;
            case 5:
                printf("\n\n=============================================\n\n");
                printf("\n\nSaindo...\n\n");
                break;
            default:
                printf("\n\n=============================================\n\n");
                printf("Opcao invalida!");
                break;
        }
        printf("\n\n=============================================\n\n");
    }while(opcao != 5);

    while (topo != NULL){
        retirar(&topo);
    }
    return 0;
}