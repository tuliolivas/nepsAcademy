#include <stdio.h>

float lerNumero(int ordem, int naoNulo)
{
    float i;
    while (1)
    {
        switch (ordem)
        {
        case 1:
            printf("Digite o primeiro numero: ");
            break;
        case 2:
            printf("Digite o segundoo numero: ");
            break;
        default:
            break;
        }
        if (scanf(" %f", &i) != 1)
        {
            fprintf(stderr, "Opcao Invalida.\n");
            while (getchar() != '\n');
            continue;
        }
        if (naoNulo)
        {
            if (i == 0)
            {
                fprintf(stderr, "Erro: Divisao por zero não e permitida.\n");
                break;
            }
        }
        break;
    }
    return i;
}

void validarRepetir(char *repetir) {
    while(1)
    {
        printf("Deseja realizar outra operacao? (s/n) ");
        scanf(" %c", repetir);
        while (getchar() != '\n');
        if (*repetir == 's' || *repetir == 'n' || *repetir == 'S' || *repetir == 'N')
            break;
        else
        {
            printf("Entrada invalida. Por favor, digite 's' para sim ou 'n' para nao: \n");
            continue;
        }
	}
}

void adicao ()
{
    float a, b;
	a = lerNumero(1, 0);
	b = lerNumero(2, 0);
    printf("Resultado: %0.2f + %0.2f = %0.2f\n", a, b, a + b);
}

void subtracao ()
{
    float a, b;
    a = lerNumero(1, 0);
	b = lerNumero(2, 0);
    printf("Resultado: %0.2f - %0.2f = %0.2f\n", a, b, a - b);
}

void multiplicacao ()
{
    float a, b;
	a = lerNumero(1, 0);
	b = lerNumero(2, 0);
    printf("Resultado: %0.2f x %0.2f = %0.2f\n", a, b, a * b);
}

void divisao ()
{
    float a, b;
	a = lerNumero(1, 0);
	b = lerNumero(2, 1);
    if (b != 0)
        printf("Resultado: %0.2f / %0.2f = %0.2f\n", a, b, a / b);
}

int main ()
{
    int opcao;
    char repetir = 's';
    do
    {
        printf("===============================\n");
        printf("Calculadora Simples\n");
        printf("===============================\n");
        printf("Selecione uma operacao:\n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Sair\n");

        if (scanf(" %d", &opcao) != 1)
        {
            fprintf(stderr, "Opcao Invalida.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao)
        {
        case 1:
            adicao();
            break;
        case 2:
            subtracao();
            break;
        case 3:
            multiplicacao();
            break;
        case 4:
            divisao();
            break;
        case 5:
            break;
        default:
            fprintf(stderr, "Opcao Invalida.\n");
            continue;;
        }

        if (opcao != 5) validarRepetir(&repetir);
        else break;
    }
    while (repetir == 's' || repetir == 'S');
    
    printf("Obrigado por usar a calculadora! Ate a proxima.\n");
    
    return 0;
}
