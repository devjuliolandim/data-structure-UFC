#include<stdio.h>
#include<stdlib.h>

typedef struct lista Lista;
typedef struct pilha Pilha;

typedef struct lista{
	
	int info;
	Lista *prox;
	
}Lista;

typedef struct pilha{
	
	Lista *prim;
	
}Pilha;

int topo(Pilha *p){
	
	if(p->prim == NULL){
		printf("Pilha Vazia!\n");
		exit(1);
	}
	
	int topo = p->prim->info;
	
	return topo;
}

int impares(Pilha *p){
	
	if(p->prim == NULL){
		printf("Pilha Vazia!\n");
		exit(1);
	}
	
	int contador = 0;
	
	Lista *l = p->prim;
	
	while(l != NULL){
		if((l->info%2) != 0){
			contador++;
		}
		l = l->prox;
	}
	
	return contador;
	
}

Pilha* empilha_pares(Pilha *p1, Pilha *p2){
	
	if(p1->prim == NULL){
		printf("Pilha Vazia!!!");
		exit(1);
	}

	Lista* l1 = p1->prim;
	
	while(l1 != NULL){
		
		if((l1->info%2)== 0){
			
			Lista *novoNo = (Lista *)malloc(sizeof(Lista));
			
			if(novoNo == NULL){
				printf("Memoria insuficiente ao criar no!");
				exit(1);
			}
			
			novoNo->info = l1->info;
			novoNo->prox = p2->prim;
			p2->prim = novoNo;
			
		}
		
		
		l1 = l1->prox;
	}

	return p2;
}

Pilha* pilha_cria(void){
	
	Pilha *p = (Pilha *)malloc(sizeof(Pilha));
	
	if(p == NULL){
		printf("Memoria Insuficiente\n");
		exit(1);
	}
	
	p->prim = NULL;
	
	return p;
}

void pilha_push(Pilha *p, int info){
	Lista *l = (Lista *)malloc(sizeof(Lista));
	
	if(l == NULL){
		printf("Memoria insuficiente");
		exit(1);
	}
	
	l->info = info;
	l->prox = p->prim;
	
	p->prim = l;
}

int pilha_pop(Pilha *p){
	
	int a;
	Lista *l = p->prim;
	
	if(p->prim == NULL){
		printf("Pilha Vazia\n");
		exit(1);
	}
	
	a = l->info;
	p->prim = l->prox;
	free(l);
	
	return a;
}

void pilha_imprime(Pilha *p){
	
	Lista *l = p->prim;
	
	while(l!=NULL){
		printf("%d\n", l->info);		
		l = l->prox;
	}
}

void pilha_libera(Pilha *p){
	
	Lista *l = p->prim;
	Lista *lAux;
	
	while(l != NULL){
		
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	
	free(p);
}


