#include "pilha.h"

int main() {
    Pilha P;
    Item D;
    FPVazia(&P);
    D.value = 5;
    PUSH(&P, D);
    D.value = 3;
    PUSH(&P, D);
    D.value = 6;
    PUSH(&P, D);
    Imprimir(&P);
    Remove(&P, 3);
    Imprimir(&P);

    return 0;
}