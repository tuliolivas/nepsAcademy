#include <stdio.h>
#include <stdlib.h> // Biblioteca com Funções de Alocação Dinâmica! EXIT_SUCCESS e EXIT_FAILURE!

int main ()
{
    int *p, n;
    
    while (1)
    {
        printf("Quantos Jogadores? (1-4) ");
        if (scanf("%d", &n) != 1)
        {
            fprintf(stderr, "Insira uma quantidade valida de jogadores. (1-4)\n");
            while (getchar() != '\n');
            continue;
        }
        if (n < 1 || n > 4)
        {
            fprintf(stderr, "Insira uma quantidade valida de jogadores. (1-4)\n");
            continue;
        }
        break;
    }

    p = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            printf("Sexo do jogador %d? (0 para masculino / 1 para feminino) ", i + 1);
            if (scanf("%d", (p + i)) != 1)
            {
                fprintf(stderr, "Insira uma opcao valida. (0/1)\n");
                while (getchar() != '\n');
                continue;
            }
            if (*(p + i) != 0 && *(p + i) != 1)
            {
                fprintf(stderr, "Insira uma opcao valida. (0/1)\n");
                continue;
            }
            break;
        }
    }

    for (int i = 0; i < n; i++)
        printf("Sexo Personagem %d: %d\n", i + 1, *(p + i));

    free(p);

    return EXIT_SUCCESS;
}