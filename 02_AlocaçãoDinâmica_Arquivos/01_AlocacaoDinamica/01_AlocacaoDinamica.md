O que é alocação dinâmica de memória?
Até agora, só utilizamos o espaço de memória estático do computador, isto é, todos os espaços de memória utilizados foram definidos antes da execução do programa.
Porém, podemos solicitar espaços de memória durante a execução do programa.
Essa memória solicitada durante a execução do programa é chamada de memória dinâmica, e o processo para solicitá-la é chamado de alocação dinâmica de memória.
Dessa forma, podemos trabalhar com uma quantidade de memória sob demanda, sem precisar predefini-la.

Biblioteca stdlib.h
As bibliotecas que utilizamos até agora não possuem as funções necessárias para a alocação dinâmica. Portanto, precisaremos utilizar a biblioteca stdlib.h, que possui tais funções.
Dentre as funções necessárias para a alocação dinâmica de memória, iremos começar estudando a malloc e a free.

Função malloc
A função malloc irá alocar (solicitar) um número específico e contíguo de bytes de memória.
Ela retorna para o programa um ponteiro que aponta para a primeira posição desse bloco de memória caso a alocação seja possível, ou um ponteiro nulo caso não seja possível realizar a alocação.
O protótipo da função (tipo de retorno, nome e parâmetros) é o seguinte:

void* malloc(size_t size);

Para a utilização da função, é necessário apenas um parâmetro: o número de bytes desejados. Exemplos:

malloc(4); // tenta alocar 4 bytes de memoria
malloc(16); // tenta alocar 16 bytes de memoria

Em ambos os exemplos acima, a função irá retornar um ponteiro apontando para a primeira posição de memória do bloco solicitado.
Caso não seja possível alocar a quantidade de bytes especificada, a função retornará um ponteiro nulo.

Observe o que acontece ao tentarmos alocar uma quantidade pequena e uma grande de memória:

#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("%d\n", malloc(4));

    printf("%d\n", malloc(2147483647));
}

/* Saída:
12325944
0
*/

Perceba que o primeiro printf imprimiu uma posição de memória válida para a solicitação de alocação de 4 bytes, enquanto que o segundo imprimiu 0, o correspondente a um valor nulo.
Isso ocorreu porque a quantidade de bytes solicitada é muito grande e a alocação não foi possível.
No entanto, para realmente podermos utilizar a memória alocada deveremos trabalhar com ponteiros.
Isto pois, como visto acima, a função irá retornar um ponteiro para a primeira posição de memória do bloco solicitado (quando possível).
Tendo isso em vista, devemos criar um ponteiro de algum tipo escolhido para receber a primeira posição de memória do bloco.
Observação: defina a quantidade de bytes a ser solicitada com base no tipo do ponteiro que irá ser utilizado.

Exemplo:

int *p;
p = malloc(4);

/*
p aponta para a primeira posição de um bloco com 4 bytes de memoria.
Logo, p aponta para exatamente um inteiro
*/

Para definir o tamanho do bloco de memória a ser solicitado, podemos utilizar o operador sizeof, que retorna o tamanho em bytes de um tipo de dado:

ponteiro = malloc(sizeof(int)); // aloca espaço para um inteiro
ponteiro = malloc(sizeof(int)*5); // aloca espaço para 5 inteiros
ponteiro = malloc(sizeof(char)*10); // aloca espaço para 10 caracteres
ponteiro = malloc(sizeof(int)*N); // aloca espaço para N inteiros

Ao alocarmos memória para, por exemplo, 5 inteiros, podemos utilizar o ponteiro que receberá a primeira posição de memória do bloco como um vetor. Observe:

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p = malloc(sizeof(int) * 5);

    for(int i = 0; i < 5; i++)
        p[i] = i + 2;

    for(int i = 0; i < 5; i++)
        printf("%d\n", *(p + i));
    
    // tanto o acesso via colchetes quanto a aritmética de ponteiros podem ser utilizados
}

/* Saída:
2
3
4
5
6
*/

Observações:Não faz sentido solicitarmos memória para o computador e não utilizarmos ela.

Tendo em vista que a função malloc retorna um ponteiro do tipo void, alguns compiladores podem gerar um erro de compilação ao tentar atribuir um ponteiro void para um ponteiro de algum outro tipo de dado
Sendo, então, necessário utilizar um casting de dados(converter um tipo de dado em outro):

int *p;
p = malloc(sizeof(int)*5); // possível erro de compilação
p = (int*)malloc(sizeof(int)*5); // ok

Função free
A função free irá receber um ponteiro para a primeira posição de um bloco de memória alocado previamente, e irá liberar (desalocar) toda essa região de memória.
Isso irá permitir que todas essas posições possam ser utilizadas novamente.
Exemplo:

int *p = (int*)malloc(sizeof(int) * 10); // aloca 40 bytes de memoria
free(p); // libera os 40 bytes alocados