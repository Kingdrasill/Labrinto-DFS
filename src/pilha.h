#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Item Item;
typedef struct Bloco Bloco;
typedef struct Pilha Pilha;

struct Item{
	int x;
	int y;
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

Item POP(Pilha *P);

void Imprimir(Pilha *P);