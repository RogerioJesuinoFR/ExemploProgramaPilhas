/*1 - Implemente uma lista encadeada simples em C e escreva funções para inserir elementos no início, no final e em uma posição especifica da lista.*/
/*2 - Crie uma função para buscar um elemento em uma lista encadeada e retornar sua posição (ou -1 se não estiver presente)*/
/*3 - Escreva uma função para remover um elemento de uma lista encadeada com base em seu valor*/

#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

//inserir no inicio
void inserirInicio(No **lista, int num){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->prox = *lista;
        *lista = novo;
    } else {
        printf("Erro ao alocar memoria!\n");
    }
}

//inserir no final
void inserirFinal(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->prox = NULL;
        if(*lista == NULL){
            *lista = novo;
        } else {
            aux = *lista;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        
    } else {
        printf("Erro ao alocar memoria!\n");
    }
}

//inserir no meio
void inserirMeio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->prox = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while(aux->valor != ant && aux->prox){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    } else {
        printf("Erro ao alocar memoria!\n");
    }
}

//remover elemento da lista
No* removerElemento(No **lista, int num){
    No *aux, *remover = NULL;
    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->prox;
        } else {
            aux = *lista;
            while(aux->prox && aux->prox->valor != num){
                aux = aux->prox;
            }
            if(aux->prox){
                remover = aux->prox;
                aux->prox = remover->prox;
            } else if(aux->prox == NULL){
                printf("Nao foi encontrado esse elemento na lista.\n");
            }
        }
    }
    return remover;
}

//buscar elemento da lista
int buscarElemento(No *lista, int num, int *pos) {
    No *aux = lista;
    *pos = 0;
    while (aux != NULL && aux->valor != num) {
        aux = aux->prox;
        (*pos)++;
    }
    if (aux) {
        return 1;
    } else {
        
        return 0;
    }
}


//imprimir lista
void imprimirLista(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d ", no->valor);
        no = no->prox;
    }
    printf("\n\n");
}

int main(){

    int opcao, valor, ant, posicao;
    No *remover, *lista = NULL;

    do
    {
        printf("\n\t1 - Inserir no inicio\n\t2 - Inserir final\n\t3 - Inserir no meio\n\t4 - Buscar elemento\n\t5 - Remover elemento\n\t6 - Imprimir lista\n\t7 - Sair.\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                printf("Informe o valor que deseja inserir:\n");
                scanf("%d", &valor);
                inserirInicio(&lista, valor);
                break;
            case 2:
                printf("Informe o valor que deseja inserir:\n");
                scanf("%d", &valor);
                inserirFinal(&lista, valor);
                break;
            case 3:
                printf("Informe o valor que deseja inserir:\n");
                scanf("%d", &valor);
                printf("deseja inserir o %d apos qual elemento da lista?\n", valor);
                scanf("%d", &ant);
                inserirMeio(&lista, valor, ant);
                break;
            case 4:
                printf("Informe o valor que deseja buscar:\n");
                scanf("%d", &valor);
                if (buscarElemento(lista, valor, &posicao)){
                    printf("O elemento %d esta na posicao %d\n", valor, posicao+1);
                } else {
                    printf("O elemento nao foi encontrado.\n");
                }
                break;
            case 5:
                if(lista == NULL){
                    printf("\nA lista esta vazia.\n");
                } else {
                    printf("Informe o elemento que deseja remover:\n");
                    scanf("%d", &valor);
                    remover = removerElemento(&lista, valor);
                    if(remover){
                        printf("Elemento %d foi removido!\n", remover->valor);
                        free(remover);
                    }
                }
                break;
            case 6:
                imprimirLista(lista);
                break;
            case 7:
                printf("\n\nSaindo...\n\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
            }
    } while (opcao != 7);
    
    return 0;
}