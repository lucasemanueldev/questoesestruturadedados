#include<stdio.h>
#include<stdlib.h>
#define T 5

typedef struct Lista{
	int x[T]={1,2,3,4,5};
}Lista;

int percente (Lista *I, int v ){
	int i,cont=0;
	for(i=0;i<T;i++){
		if(I->x[i] == v){
			cont++;
		}
	}
	if(cont>0){
		return 1;
	}else{
		return 0;
	}
}
main(){
	Lista l;
	int n;
	printf("Digite um valor: ");
	scanf("%d",&n);
	printf("%d",percente(&l,n));
}
