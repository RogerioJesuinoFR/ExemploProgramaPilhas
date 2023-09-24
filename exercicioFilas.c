#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *prim;
    No *fim;
    int tam;
}Fila;

void criarFila(Fila *fila){
    fila->prim = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void inserirFila(Fila *fila, int num){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(fila->prim == NULL){
            fila->prim = novo;
            fila->fim = novo;
        } else {
            fila->fim->proximo = novo;
            fila->fim = novo;
        }
        fila->tam++;
    } else {
        printf("\nErro ao alocar memoria.\n");
    }
}

No* removerFila(Fila *fila){
    No *remover = NULL;
    if(fila->prim){
       remover = fila->prim;
       fila->prim = remover->proximo;
       fila->tam--; 
    } else{
        printf("\tFila vazia\n");
    }
    return remover;
}

void imprimir(Fila *fila){
    No *aux = fila->prim;
    printf("\t============== FILA ===============\n\t");
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n\t============ FIM FILA =============\n");
}

int main(){
    No *r;
    Fila fila;
    int opcao, valor, novaFila = 0;

    do{
        printf("\n\tSelecione a opcao desejada:\n\t1 - Criar fila\n\t2 - Inserir novo elemento\n\t3 - Remover elemento\n\t4 - Imprimir elementos da fila\n\t5 - Sair\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                if(novaFila == 0){
                    criarFila(&fila);
                    novaFila = 1;
                    printf("Fila criada!");
                } else {
                    printf("\nVoce ja possui uma fila criada!\n");
                }
                break;
            case 2:
                if(novaFila == 1){
                    printf("\nInforme o valor que deseja inserir:\n");
                    scanf("%d", &valor);
                    inserirFila(&fila, valor);
                    printf("\nElemento inserido.\n");
                } else {
                    printf("Erro: a fila nao foi criada!\n");
                }
                break;
            case 3:
                if(novaFila == 1){
                    r = removerFila(&fila);
                    if(r){
                        printf("Removido: %d\n", r->valor);
                        free(r);
                    }
                } else {
                    printf("\nErro: a fila nao foi criada!\n\n");
                }
                break;
            case 4:
                imprimir(&fila);
                break;
            case 5:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    }while(opcao != 5);
    return 0;
}