#include "labirinto.h"

void Inicializar(Labirinto *lab, int l, int c) {
    lab->coluna = c;
    lab->linha = l;
    lab->map = malloc(l * sizeof(Cell*));

    for(int i=0; i<l; i++) {
        lab->map[i] = malloc(c *sizeof(Cell));
    }
}

void Finalizar(Labirinto *lab) {
    for(int i=0; i<lab->linha; i++) {
        free(lab->map[i]);
    }
    free(lab->map);
}

void ImprimirLab(Labirinto *lab) {
    for(int i=0; i<lab->linha; i++) {
        for(int j=0; j<lab->coluna; j++) {
            printf("%c ", lab->map[i][j].value);
        }
        printf("\n");
    }
}

int DFS(Labirinto *lab, Pilha *p) {
    bool cont = true, try = true;
    Item aux, tmp;
    int count = -2;
    int x=0, y=0;

    while (cont) {
        aux = POP(p);
        count++;
        x = aux.x;
        y = aux.y;

        if(x == (lab->linha - 1) && y == (lab->coluna - 1)) {
            cont = false;
        } else {
            if((x+1) < lab->linha && lab->map[x+1][y].value != '#' && !lab->map[x][y].bottom) {
                lab->map[x][y].bottom = true;
                while(try) {
                    tmp.x = x;
                    tmp.y = y;
                    PUSH(p, tmp);
                    count++;
                    if((x+1) >= lab->linha || lab->map[x+1][y].value == '#') {
                        try = false;
                    }
                    x++;
                }
                try =true;
                x = aux.x;
                y = aux.y;
            } else if((y+1) < lab->coluna && lab->map[x][y+1].value != '#' && !lab->map[x][y].right) {
                lab->map[x][y].right = true;
                while(try) {
                    aux.x = x;
                    aux.y = y;
                    PUSH(p, aux);
                    count++;
                    if((y+1) >= lab->coluna || lab->map[x][y+1].value == '#') {
                        try = false;
                    }
                    y++;
                }
                try =true;
                x = aux.x;
                y = aux.y;
            } else if((y-1) > 0 && lab->map[x][y-1].value != '#' && !lab->map[x][y].left) {
                lab->map[x][y].left = true;
                while(try) {
                    aux.x = x;
                    aux.y = y;
                    PUSH(p, aux);
                    count++;
                    if((y-1) < 0 || lab->map[x][y-1].value == '#') {
                        try = false;
                    }
                    y--;
                }
                try =true;
            } else {
                lab->map[x][y].bottom = true;
                lab->map[x][y].right = true;
                lab->map[x][y].left = true;   
            }
        }
    }

    return count;
}

bool LerArquivo(Labirinto *lab) {
    FILE *fp;
    char arquivo[ARQ_MAXTAM];
    char cell;
    int i=0, j=0;

    scanf("%c", (char *) stdin);
    printf("Nome do arquivo onde esta o  labirinto(com extensao): ");
	fgets(arquivo, ARQ_MAXTAM, stdin);
	strtok(arquivo, "\n");

    fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("\nErro!Nao foi possivel abrir o arquivo!\n");
        exit(1);
    } else {
        while((cell = (char)fgetc(fp)) != EOF) {
            if(cell == '\n') {
                i++;
                j = 0;
            }
            else {
                lab->map[i][j].value = cell;
                lab->map[i][j].left = false;
                lab->map[i][j].right = false;
                lab->map[i][j].bottom = false;
                j++;
            }
        }
    }
    fclose(fp);

    return true;
}