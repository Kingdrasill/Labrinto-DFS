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

void POP(Pilha *P, Item *D) {
	Bloco *tmp;
	
	if (P->T == P->F) {
		printf("Vazia!");
		D = NULL;
	} else {
		tmp = P->T; 
		*D = P->T->dado;
		P->T = P->T->ant;
		free(tmp);
	}
};

void Remove(Pilha *P, int idx) {
	Pilha aux;
	Bloco *P2;
	Item tmp;
	FPVazia(&aux);
	
	while(P->T->dado.value != idx) {
		POP(P, &tmp);
		PUSH(&aux, tmp);
		
	}
	
	if(P->T != P->F) {
		P2 = P->T;
		P->T = P->T->ant;
		free(P2);
	}
	
	while(aux.T != aux.F) {
		POP(&aux, &tmp);
		PUSH(P, tmp);
	}
}

void Imprimir(Pilha *P) {
	Bloco *aux;
	aux = P->T;
	while(aux->ant != NULL){
		printf("%d\n", aux->dado.value);
		aux = aux->ant;
	}
}