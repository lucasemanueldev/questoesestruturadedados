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

void inserir_no_inicio(Lista *lista, int num){
    No *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void inserir_no_fim(Lista *lista, int num){
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

void inserir_no_meio(Lista *lista, int num, int ant){
    No *aux, *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

No* remover(Lista *lista, int num){
    No *aux, *remover = NULL;

    if(lista->inicio){
        if(lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }

    return remover;
}

No* pertence(Lista *lista, int num){
    No *aux, *no = NULL;
    aux = lista->inicio;
    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux)
        no = aux;
    return no;
}

bool eh_ord(Lista *lista){
	No *aux = NULL;
	if(lista->inicio != NULL){
		aux = lista->inicio;
		while(aux->proximo != NULL){
			if(aux->valor > aux->proximo->valor){
				return false;
			}
			aux = aux->proximo;
		}
	}
	return true;
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

    int opcao, valor, anterior;
    Lista lista;
    No *removido;

    criar_lista(&lista);

    do{
    	system("cls");
        printf("\n\t0 - Sair\n\t1 - Inserir no Inicio\n\t2 - Inserir no Final\n\t3 - Inserir no Meio\n\t");
        printf("4 - Remover\n\t5 - Buscar Elemento\n\t6 - Ordenada?\n\t7 - Imprimir\n");
        scanf("%d", &opcao);
		printf("\n");
        switch(opcao){
        case 1:
        	system("cls");
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            system("pause");
            break;
        case 2:
        	system("cls");
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            system("pause");
            break;
        case 3:
        	system("cls");
            printf("Digite um valor: ");
            scanf("%d", &valor);
            printf("\n");
            imprimir(lista);
            printf("\n");
            printf("Digite o valor da posicao anterior: ");
            scanf("%d",&anterior);
            inserir_no_meio(&lista, valor, anterior);
            system("pause");
            break;
        case 4:
        	system("cls");
        	printf("\n");
            imprimir(lista);
            printf("\n");
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido){
                printf("Elemento removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("elemento inexistente!\n");
            system("pause");
            break;
        case 5:
        	system("cls");
        	printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = pertence(&lista, valor);
            if(removido){
            	printf("%d\n",true);
			}else{
				printf("%d\n",false);
			}
        	system("pause");
        	break;
        case 6:
        	system("cls");
        	printf("%d\n",eh_ord(&lista));
        	system("pause");
        	break;
        case 7:
        	system("cls");
            imprimir(lista);
            system("pause");
            break;
        default:
        	system("cls");
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}
