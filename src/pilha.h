#include <stdlib.h>
#include <stdio.h>

typedef struct Item Item;
typedef struct Bloco Bloco;
typedef struct Pilha Pilha;

struct Item{
	int value;
};

struct Bloco{
	Item dado;
	Bloco *ant;
};

struct Pilha{
	Bloco *F;
	Bloco *T;
};

void FPVazia(Pilha *P);

void PUSH(Pilha *P, Item D);

void POP(Pilha *P, Item *D);

void Remove(Pilha *P, int idx);

void Imprimir(Pilha *P);