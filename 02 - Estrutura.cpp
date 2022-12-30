#include<stdio.h>
#include<stdlib.h>
#define T 5

typedef struct Fila{
	int dados[T];
	int fim;
}Fila;

void inserir(int a, int b, Fila *f){
	int i;
	printf("Inicio da fila\n");
	for(i=a;i<=b;i++){
		f->dados[i] = i;
		printf("%d\n",f->dados[i]);
	}
	printf("\nFim da fila");
}

main(){
	int m, n, i;
	Fila A;
	
	printf("Digite dois numero de ate um intervalo de 10 numeros\n");
	printf("Ex: 0 a 9; 1 a 10\n");
	printf("Digite o inicio da fila: ");
	scanf("%d",&m);
	printf("Digite o final da fila: ");
	scanf("%d",&n);
	printf("\n");
	inserir(m, n, &A);
	printf("\n");
	
}
