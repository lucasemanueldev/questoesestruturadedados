#include<stdio.h>
#include<stdlib.h>

typedef struct No{
	int valor;
	struct No *prox;
}No;

void inserirNoInicio(No **lista, int num){
	No *novo = (No*)malloc(sizeof(No));
	if(novo){
		novo->valor = num;
		novo->prox  = *lista;
		*lista = novo;
	}else{
		printf("Erro ao alocar memoria!\n");
	}
}

void inserirNoFim(No **lista, int num){
	No *aux, *novo = (No*)malloc(sizeof(No));
	if(novo){
		novo->valor = num;
		novo->prox  = NULL;
		if(*lista == NULL){
			*lista = novo;
		}else{
			aux = *lista;
			while(aux->prox){
				aux = aux->prox;
			}
			aux->prox = novo;
		}
			
	}else{
		printf("Erro ao alocar memoria!\n");
	}
}

void inserirNoMeio (No **lista, int num, int ant){
	No *aux, *novo = (No*)malloc(sizeof(No));
	if(novo){
		novo->valor = num;
		if(*lista == NULL){
			novo->prox == NULL;
			*lista = novo;
		}else{
			aux = *lista;
			while(aux->valor != ant && aux->prox){
				aux = aux->prox;
			}
			novo->prox = aux->prox;
			aux->prox = novo;
		}
	}else{
		printf("Erro ao alocar memoria!\n");
	}
}

void imprimir(No *no){
	printf("\n\tLista: ");
	while(no){
		printf("%d ",no->valor);
		no = no->prox;
	}
	printf("\n\n");
}
main(){
	int opcao, valor, anterior;
	No *lista = NULL;
	
	do{
		system("cls");
		printf("\n\t0 - Sair\n\t1 - Inserir no Inicio\n\t2 - Inserir no Final\n\t3 - Inserir no Meio\n\t4 - Imprimir\n");
		printf("Digite uma opcao: ");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				system("cls");
				printf("Digite um valor: ");
				scanf("%d",&valor);
				inserirNoInicio(&lista, valor);
				system("pause");
				break;
			case 2:
				system("cls");
				printf("Digite um valor: ");
				scanf("%d",&valor);
				inserirNoFim(&lista, valor);
				system("pause");
				break;
			case 3:
				system("cls");
				printf("Digite um valor: ");
				scanf("%d",&valor);
				imprimir(lista);
				printf("Digite o valor da posicao anterior: ");
				scanf("%d",&anterior);
				inserirNoMeio(&lista, valor, anterior);
				system("pause");
				break;
			case 4:
				system("cls");
				imprimir(lista);
				system("pause");
				break;
			default:
				if(opcao != 0){
					printf("Opcao invalida\n");
				}
		}
	}while(opcao != 0);
}
