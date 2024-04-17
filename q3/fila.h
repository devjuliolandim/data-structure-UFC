#include<stdio.h>
#include<stdlib.h>

typedef struct lista Lista;
typedef struct fila Fila;

struct lista{
	int info;
	Lista *prox;
};

struct fila{
	Lista *ini;
	Lista *fim;
};

Fila *fila_cria(void){
	Fila *f = (Fila *)malloc(sizeof(Fila));
	
	if(f == NULL){
		printf("Memoria insuficiente");
		exit(1);
	}
	
	f->ini = NULL;
	f->fim = NULL;
	
	return f;
}

int fila_vazia(Fila *f){
	return f->ini == NULL;
}

void fila_insere(Fila *f, int info){
	
	Lista *l = (Lista *)malloc(sizeof(Lista));
	
	if(l == NULL){
		printf("Memoria insuficiente!");
		exit(1);
	}
	
	l->prox = NULL;
	l->info = info;
	
	if(fila_vazia(f)){
		f->ini = l;
	}else{
		f->fim->prox = l;
	}
	
	f->fim = l;
}

int fila_remove(Fila *f){
	
	Lista *l;
	int a;
	
	if(fila_vazia(f)){
		printf("Fila Vazia!");
		exit(1);
	}
	
	a = f->ini->info;
	l = f->ini;
	f->ini = l->prox;
	free(l);
	
	if(fila_vazia(f)){
		f->fim = NULL;
	}
	
	return a;
}

void fila_imprime(Fila *f){
	Lista *l = f->ini;
	
	while(l!=NULL){
		printf("Info: %d\n", l->info);
		l = l->prox;
	}
}

void fila_libera(Fila *f){
	Lista *l = f->ini;
	Lista *lAux;
	
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	
	free(f);
}

int qtd_maior(Fila *f, int n){
	
	Lista *l = f->ini;
	int contador = 0;
	
	while(l!=NULL){	
		if(l->info > n){
			contador++;
		}
		l = l->prox;
	}
	
		
	return contador;
}

void inverte_rec(Fila *f2, Fila *f1){
	
	if(!fila_vazia(f1)){
		
		int valor_temp = fila_remove(f1);
		
		inverte_rec(f2,f1);
		
		fila_insere(f2,valor_temp);
		
	}
	
}

void *fila_copia(Fila *fOriginal, Fila *fCopia){
	
	Lista *lAux = fOriginal->ini;
	
	while(lAux != NULL){
		fila_insere(fCopia, lAux->info);
		lAux = lAux->prox;
	}
	
}

Fila* inverte(Fila *f){

	Fila *f2 = fila_cria();
	Fila *fReserva = fila_cria();
	
	fila_copia(f, fReserva);
	
	inverte_rec(f2,fReserva);
	
	fila_libera(fReserva);
		
	return f2;
}

int pares(Fila *f){
	
	Lista *l = f->ini;
	int contador = 0;
	
	while(l!=NULL){
		if((l->info)%2 == 0){
			contador++;
		}
		l = l->prox;
	}
	
	return contador;
}
