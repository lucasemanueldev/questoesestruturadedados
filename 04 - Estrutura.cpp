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

void imprimir(No *no){
	printf("\n\tLista: ");
	while(no){
		printf("%d ",no->valor);
		no = no->prox;
	}
	printf("\n\n");
}
main(){
	int valor;
	char opcao;
	No *lista = NULL;
	
	do{
		printf("\n\tsaia - Sair\n\ta - Inserir\n\tb - Imprimir\n");
		printf("Digite uma opcao: ");
		scanf(" %c",&opcao);
		switch(opcao){
			case 'a':
				printf("Digite um valor: ");
				scanf("%d",&valor);
				inserirNoInicio(&lista, valor);
				break;
			case 'b':
				imprimir(lista);
				break;
			default:
				opcao = 's';
		}
	}while(opcao != 's');
}
