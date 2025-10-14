#include <stdio.h>

int main () {
    int matrixA[2][3] = {1, 5, -2, -3, 0, 6};
    int matrixT[3][2];
    int linha, coluna, n;
    
    printf("Matrix:\n");
    for (linha = 0; linha < 2; linha ++) {
        for (coluna = 0; coluna < 3; coluna ++) {
            printf("%d ", *(*(matrixA + linha) + coluna));
            if (coluna == 2)
                printf("\n");
        }
    }
    printf("\n");

    printf("Transposed Matrix:\n");
    for (linha = 0; linha < 3; linha ++) {
        for (coluna = 0; coluna < 2; coluna ++) {
            *(*(matrixT + linha) + coluna) = *(*(matrixA + coluna) + linha);
            printf("%d ", *(*(matrixT + linha) + coluna));
            if (coluna == 1)
                printf("\n");
        }
    }

    return 0;
}