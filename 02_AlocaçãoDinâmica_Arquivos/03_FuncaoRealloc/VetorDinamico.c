#include <stdio.h>
#include <stdlib.h> // Biblioteca com funções de alocação dinâmica e EXIT_SUCCESS/EXIT_FAILURE

void redimensionarVetor(int **p, int *n)
{
    int novoN, *aux = NULL;

    while (1)
    {
        printf("Qual tamanho do novo vetor? ");
        if ((scanf(" %d", &novoN) != 1 ) || (novoN <= 0))
        {
            fprintf(stderr, "Insira uma quantidade valida\n");
            while (getchar() != '\n');
            continue;
        }

        break;
    }

    if (novoN == *n)
    {
        printf("Tamanho igual ao atual (%d). Nenhuma alteracao realizada.\n", *n);
        return;
    }

    aux = realloc(*p, novoN * sizeof(int));

    if (aux == NULL)
    {
        fprintf(stderr, "Falha ao redimensionar o vetor. Mantendo tamanho anterior (%d).\n", *n);
        return;
    }

    *p = aux;

    if (novoN > *n)
    {
        for (int i = *n; i < novoN; ++i)
            *(*p + i) = 0;
    }

    *n = novoN;

    printf("Vetor alocado com sucesso para %d elementos.\n", *n);    
    printf("Novo endereco do vetor na memoria: %p\n", (void *)*p);
}

int main(void)
{
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

    while (1)
    {
        printf("Voce deseja alterar o tamanho do vetor? (s/n) ");
        
        if (scanf(" %c", &r) != 1)
        {
            fprintf(stderr, "Insira uma resposta valida\n");
            while (getchar() != '\n');
            continue;
        }

        if (r == 's' || r == 'S')
        {
            redimensionarVetor(&p, &n);
        }
        
        else if (r == 'n' || r == 'N')
        {
            printf("Obrigado!\n");
            break;
        }

        else
        {
            fprintf(stderr, "Erro: Resposta invalida. Por favor, digite 's' ou 'n'.\n");
            while (getchar() != '\n');
        }
    }

    free(p);

    return EXIT_SUCCESS;
}