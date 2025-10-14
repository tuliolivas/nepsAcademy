#include <stdio.h>  // Biblioteca com funções de entrada e saída
#include <stdlib.h> // Biblioteca com funções de alocação dinâmica e EXIT_SUCCESS/EXIT

int main() {
    int *p = NULL, n;
    char r;

    while (1)
    {
        printf("Quantos elementos no vetor? ");
        if ((scanf(" %d", &n) != 1 ) || (n <= 0))
        {
            fprintf(stderr, "Insira uma quantidade valida\n");
            while (getchar() != '\n');
            continue;
        }

        break;
    }

    p = (int*) calloc(n, sizeof(int));
    
    if (p != NULL)
    {
        printf("Vetor alocado com sucesso para %d elementos.\n", n);
        printf("Endereco inicial do vetor na memoria: %p\n", (void *)p);
    }

    else
    {
        fprintf(stderr, "Falha ao alocar memoria.\n");
        return EXIT_FAILURE;
    }

    free(p);
    p = NULL;
    return EXIT_SUCCESS;
}