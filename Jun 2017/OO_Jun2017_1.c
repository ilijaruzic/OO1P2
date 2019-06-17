#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK_ALLOC(x) if(!(x)) { puts("Memory allocation error!"); exit(1); }

char **allocate(int m, int n) {
    char **table;
    
    table = (char **) malloc(m * sizeof(char*));
    CHECK_ALLOC(table);
    for (int i = 0; i < m; i++) {
        table[i] = (char *) malloc(n * sizeof(char));
        CHECK_ALLOC(table[i]);
        memset(table[i], 'O', n * sizeof(char));
    }

    return table;
}

void load(char **table, int m, int n) {
    int k, x, y;
    char type;

    printf("\nHow many figures you want to load? ");
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        do {
            printf("Figure position and type? [King=K, Queen=Q, Rook=R, Bishop=B, Knight=N, Pawn=P\n");
            scanf("%d%d %c", &x, &y, &type); 
            fflush(stdin);
            if (x < 0 || x >= m) continue;
            if (y < 0 || y >= n) continue;
            if (type == 'K' || type == 'Q' || type == 'R' || type == 'B' || type == 'N' || type == 'P') break;
        } while (1);
        table[x][y] = type;
    }
}

int check(int x, int y, int m, int n) {
    if (x < 0 || x >= m) return 0;
    if (y < 0 || y >= n) return 0;
    return 1;
}

void proccess(char **attacker, char **defender, int m, int n) {
    static const int displacement[][2] = { { 1, -2 }, { -1, -2 }, { 1, 2 }, { -1, 2 }, { -2, 1 }, { -2, -1 }, { 2, 1 }, { 2, -1 } };

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (attacker[i][j] == 'N')
                for (int k = 0; k < 8; k++) {
                    int x = i + displacement[k][0];
                    int y = j + displacement[k][1];
                    if (check(x, y, m, n) && defender[x][y] != 'O') {
                        printf("\nMoves:\n");
                        printf("N(%d,%d) -> %c(%d,%d)\n", i, j, defender[x][y], x, y);
                    }                
                }
}

void deallocate(char **table, int m) {
    for (int i = 0; i < m; i++) 
        free(table[i]);
    free(table);
}

int main() {
    char **white, **black, color;
    int m, n;

    printf("m, n? ");
    scanf("%d%d", &m, &n);

    white = allocate(m, n);
    black = allocate(m, n);

    printf("\nLoading white figures positions...");
    load(white, m, n);
    printf("\nLoading black figures positions...");
    load(black, m, n);

    fflush(stdin);

    printf("\nColor of the knight which is going to be checked? [w/W for white or b/B for black]\n");
    scanf("%c", &color);
    if (color == 'W' || color == 'w')
        proccess(white, black, m, n);
    else
        proccess(black, white, m, n);    

    deallocate(white, m);
    deallocate(black, m);

    return 0;
}