#include<stdio.h>
#include<stdlib.h>

typedef struct lista Lista;

typedef struct lista{
	
	int info;
	Lista* prox;
	
}Lista;

Lista* lst_cria(){
	return NULL;
}

int lst_vazia(Lista *l){
	return (l == NULL);
}

Lista* lst_insere(Lista* l, int info){
	
	Lista* lNew = (Lista *)malloc(sizeof(Lista));	
	lNew->info = info;
	lNew->prox = l;

	return lNew;
}

Lista* lst_busca(Lista *l, int info){
	
	Lista *lAux = l;
	
	while(lAux != NULL){
		
		if(lAux->info == info){
			return lAux;
		}
		
		lAux = lAux->prox;
	}
	return NULL;
}

void lst_imprime(Lista *l){
	
	Lista* lAux = l;
	
	while(lAux != NULL){
		printf("Info: %d\n", lAux->info);
		lAux = lAux->prox;
	}
	
}

Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
		Lista* lAux = l->prox;
		if(l->info == info){
			free(l);
			return lAux;
		}else{
			Lista* lAnt = l;
			while(lAux!=NULL){
				if(lAux->info == info){	
					lAnt->prox = lAux->prox;
					free(lAux);
					break;
				}else{
					lAnt = lAux;
					lAux = lAux->prox;
				}
			}
		}
	}
	return l;
}

void lst_libera(Lista* l){
	Lista* lProx;
	while(l!=NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}

Lista* lst_insere_ordenado(Lista* l, int info){
	Lista* lNew = (Lista *)malloc(sizeof(Lista));
	lNew->info = info;
	
	if(l==NULL){
		lNew->prox = NULL;
		return lNew;
	}else if(l->info>= info){
		lNew->prox = l;
		return lNew;
	}else{
		Lista* lAnt = l;
		Lista* lProx = l->prox;
		while(lProx != NULL && lProx->info < info){	
			lAnt = lProx;
			lProx = lProx->prox;
		}
		
		lAnt->prox = lNew;
		lNew->prox = lProx;
		return l;
	}	
}

void lst_imprime_rec(Lista* l){
	if(lst_vazia(l)){
		return;
	}else{
		printf("Info: %d\n", l->info);
		lst_imprime_rec(l->prox);
	}
}

void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l)){
		return;
	}else{
		lst_imprime_invertida_rec(l->prox);
		printf("Info: %d\n", l->info);
	}
}

Lista* lst_remove_rec(Lista *l, int info){
	if(!lst_vazia(l)){
		if(l->info == info){
			Lista *lAux = l;
			l = l->prox;
			free(lAux);
		}else{
			l->prox =  lst_remove_rec(l->prox, info);
		}
	}
	
	return l;
}

int comprimento(Lista *l){
	
	int contador = 0;
	
	Lista *lAux = l;
	
	if(lAux == NULL){
		return 0;
	}
	
	while(lAux != NULL){
		
		contador++;
		lAux = lAux->prox;
	}
	
	return contador;
}

int menores(Lista *l, int n){
	
	Lista *lAux = l;
	int contador = 0;
	
	if(lAux == NULL){
		return 0;
	}
	
	while(lAux!= NULL){
		
		if(lAux->info<n){
			contador++;
		}
		
		lAux = lAux->prox;
	}
	
	return contador;
}

int soma(Lista* l){
	
	int somatorio = 0;
	
	Lista *lAux = l;
	
	if(lAux == NULL){
		return 0;
	}
	
	while(lAux != NULL){
		
		somatorio = somatorio + lAux->info;
		
		lAux = lAux->prox;
		
	}
	
	return somatorio;
}

int primos(Lista *l){
	
	int contador, i;
	contador = 0;
	while(l!=NULL){
		int num = l->info;
		int primoVerificacao = 1;
		if(num<=1){
			primoVerificacao = 0;
		}else if(num <= 3){
			primoVerificacao = 1;
		}else if(num%2 == 0 || num % 3 == 0){
			primoVerificacao = 0;
		}else{
			
			for( i = 5; i*i <= num; i+= 6){
				if(num %i == 0 || num % (i+2) == 0){
					primoVerificacao = 0;
					break;
				}
			}	
		}
		
		if(primoVerificacao){
			contador++;
		}
		l = l->prox;
	}
	return contador;
}

Lista* lst_conc(Lista *l1, Lista* l2){
	
	Lista *lAux1 = l1;
	Lista *lAux2 = l2;
	
	if(lAux1 == NULL){
		return lAux2;
	}else if(lAux2 == NULL){
		return lAux1;
	}
	
	while(lAux1->prox != NULL){
		lAux1 = lAux1->prox;
	}
	
	lAux1->prox = lAux2;
	
	return l1;
}

Lista* lst_diferenca(Lista *l1, Lista *l2){
	
	Lista *lAux = l1;
	Lista *lAnt = NULL;
	
	while(lAux!=NULL){
		
		Lista *lAux2 = l2;
		int encontrou = 0;
		
		while(lAux2!=NULL){
			
			if(lAux->info == lAux2->info){
				encontrou = 1;
				break;
			}
			
			lAux2 = lAux2->prox;
		}
		
		
		if(encontrou){
			
			if(lAnt == NULL){
				Lista *lProx = lAux->prox;
				free(lAux);
				lAux = lProx;
				l1 = lAux;
			}else{
				Lista *lProx = lAux->prox;
				free(lAux);
				lAnt->prox = lProx;
				lAux = lProx;
			}	
		}else{
			lAnt = lAux;
			lAux = lAux->prox;
		}
	}
	
	
	return l1;
}


