#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct alocador{
	int val;
	
	struct alocador * proximo;
} a_loc;

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");
	
	int tam;
	a_loc *inicioloc;
	a_loc *proximoLoc;
	
	inicioloc = (a_loc *)malloc(sizeof(a_loc));
	proximoLoc = inicioloc;
	
	printf("Digite o tamanho da lista: ");
	scanf("%d", &tam);
	
	system("cls");
	
	for(int i = 0; i < tam; i++){
		printf("Digite o %dº valor:", i);
		scanf("%d", &proximoLoc->val);
		
		if(i != tam - 1){
			proximoLoc->proximo = (a_loc *)malloc(sizeof(a_loc));
			proximoLoc = proximoLoc->proximo;
		}	
	}
	
	system("cls");
	
	proximoLoc->proximo = NULL; 
	proximoLoc = inicioloc;
	
	printf("Valores da lista: ");
	
	int j = 0;
	while(proximoLoc != NULL){
		printf("[%d] - %d\n", j, proximoLoc->val);
		
		proximoLoc = proximoLoc->proximo;
		j++;
	}
	
	return -1;
}