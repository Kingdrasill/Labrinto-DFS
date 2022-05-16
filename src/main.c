#include "labirinto.h"

int main() {
    Labirinto L;
    Pilha P;
    Item I;
    int iteracoes=0, l=0, c=0;

    I.x = 0;
    I.y = 0;
    FPVazia(&P);
    PUSH(&P, I);

    printf("Quantidade de linhas do labirinto: ");
    scanf("%d", &l);
    printf("Quantidade de colunas do labirinto: ");
    scanf("%d", &c);
    
    Inicializar(&L, l, c);

    LerArquivo(&L);

    printf("\n");
    ImprimirLab(&L);

    iteracoes = DFS(&L, &P);

    printf("\nNumero de iteracoes: %d\n", iteracoes);

    Finalizar(&L);

    return 0;
}