Função calloc
A função calloc irá, assim como a função malloc, alocar um bloco de memória contíguo.
No entanto, diferentemente da malloc, a função calloc irá solicitar memória para um número específico de itens de um certo tamanho em bytes,
preencherá todo o bloco com o valor 0 e retornará um ponteiro para a primeira posição de memória
(ou um ponteiro nulo caso a alocação não seja possível, da mesma forma que na função malloc).

O protótipo da função (tipo de retorno, nome e parâmetros) é o seguinte:

void* calloc (size_t num, size_t size);
Para a utilização da função, são necessários dois parâmetros: o número de itens desejados e o número de bytes que cada item irá ocupar. Exemplos:

calloc(4, sizeof(int));
/*
    Aloca memoria para 4 itens que ocupam o mesmo espaco que um inteiro
    
    Dessa forma, foram alocados 16 bytes, ou 4 inteiros
*/

char *p = calloc(32, sizeof(char));
/*
    p recebe a primeira posicao de memoria do bloco
    de memoria alocado, que possui 32 bytes
*/

Observações:

Por mais que utilizemos a função calloc para alocar, por exemplo, 32 itens que tenham o mesmo tamanho de um char, ainda podemos utilizar esse bloco para armazenar inteiros.
No entanto, essa prática não é recomendada por ser contra intuitiva e, portanto, dificultar o entendimento do código.

Tendo em vista que a função calloc retorna um ponteiro do tipo void, pode ser necessário utilizar um casting de dados ao atribuir o endereço retornado pela função a um ponteiro,
assim como na função malloc:

char *ptr = (char*)calloc(7, sizeof(char));

A função free também pode ser utilizada para liberar a memória alocada pela função calloc:
double *ponteiro = (double*)calloc(8, sizeof(double));
free(ponteiro);

Malloc vs Calloc
Apesar das duas funções alocarem memória dinamicamente, existem diferenças:

Parâmetros: Enquanto a função malloc necessita apenas do tamanho em bytes do bloco,
a função calloc necessita da quantidade de elementos e do tamanho de cada elemento para realizar a alocação.
Dessa forma, recomenda-se a utilização da função calloc para a criação de vetores, pois é mais intuitivo e facilita o entendimento do código.
Observe:

int *p = calloc(9, sizeof(int));
/*
    Cria um vetor de inteiros com 9 posicoes, todas preenchidas com 0
*/

Inicialização: Enquanto a função malloc só aloca a memória, a função calloc inicializa todas as posições como zero.
Observação: Perceba que, utilizando a função calloc para tipos numéricos, todos os valores serão 0.
No entanto, para caracteres os valores não serão correspondentes a '0', e sim a ' '(o caractere de espaço),
ainda que seu valor numérico (aquele encontrado na tabela ASCII) seja igual a 0.