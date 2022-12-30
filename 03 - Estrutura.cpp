#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
}Lista;

void criar_lista(Lista *lista){
    lista->inicio = NULL;
}

void inserir_elemento(Lista *lista, int num){
    No *aux, *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(lista->inicio == NULL)
            lista->inicio = novo;
        else{
            aux = lista->inicio;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void imprimir(Lista lista){
    No *no = lista.inicio;
    printf("\n\tLista: ");
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(){

    int opcao, valor;
    Lista lista;

    criar_lista(&lista);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_elemento(&lista, valor);
            break;
        case 2:
            imprimir(lista);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

}
