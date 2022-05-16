#include "pilha.h"

void FPVazia(Pilha *P) {
	P->T = (Bloco*)malloc(sizeof(Bloco));
	P->T->ant = NULL;
	P->F = P->T;
}

void PUSH(Pilha *P, Item D) {
	Bloco *aux = (Bloco*)malloc(sizeof(Bloco));;
	aux->dado = D;
	aux->ant = P->T;
	P->T = aux;
};

Item POP(Pilha *P) {
	Bloco *tmp;
	Item aux;
	
	if (P->T == P->F) {
		printf("Vazia!");
		aux.x = -1;
		aux.y = -1;
	} else {
		tmp = P->T; 
		aux = P->T->dado;
		P->T = P->T->ant;
		free(tmp);
	}

	return aux;
};

void Imprimir(Pilha *P) {
	Bloco *aux;
	aux = P->T;
	while(aux->ant != NULL){
		printf("(%d,%d)\n", aux->dado.x, aux->dado.y);
		aux = aux->ant;
	}
}