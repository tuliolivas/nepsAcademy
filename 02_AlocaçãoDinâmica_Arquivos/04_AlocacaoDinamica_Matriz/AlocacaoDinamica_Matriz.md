# Funcionamento de alocação
Ao solicitar um espaço de memória por alocação dinâmica, uma porção sequencial de memória é alocada.
Essa faixa sequencial, como visto em aulas anteriores, pode ser utilizada como um vetor.

Mas como utilizar isso para alocar uma matriz? Primeiramente, precisamos entender como é a estrutura de uma matriz.

# Estrutura de uma matriz
Uma matriz pode ser entendida como um vetor de vetores.
Dessa forma, podemos interpretar uma matriz como um vetor de ponteiros, onde cada ponteiro aponta para o início de um outro vetor.

Uma explicação mais detalhada e aprofundada sobre isso pode ser encontrada na aula de Matrizes do curso de Introdução à Programação.

Então, para alocar uma matriz N×M, devemos seguir os seguintes passos:
1. Alocar memória para um vetor de N vetores, isto é, um vetor que armazene N ponteiros.
2. Para cada elemento (ponteiro) desse primeiro vetor, alocar um vetor de M elementos e atribuir o endereço de sua primeira posição a esse ponteiro.

# Ponteiro para ponteiro
Para alocar um vetor de inteiros, utilizamos um ponteiro.
Analogamente, para alocar um vetor de vetores, isto é, um vetor de ponteiros, precisamos utilizar um ponteiro que aponte para ponteiros.

Para criar um ponteiro que aponte para ponteiros, basta utilizar dois asteriscos ao invés de apenas um.
Assim, o primeiro asterisco irá indicar que estamos trabalhando com um ponteiro, e o segundo irá indicar que o dado apontado pelo ponteiro também é um ponteiro.

### Exemplos:

```c
int **p; // ponteiro para ponteiro de inteiro`
char **ptr; // ponteiro para ponteiro de caractere`
````

# Alocação de uma matriz dinâmica

Para alocar nossa matriz dinâmica, vamos seguir os dois passos citados acima:
Alocar memória para um vetor de N vetores, isto é, um vetor que armazene N ponteiros.

```c
int **p = (int**)malloc(N * sizeof(int*));
```

A função malloc foi chamada com o parâmetro N * sizeof(int*), pois queremos um bloco de memória com capacidade para armazenar N ponteiros do tipo inteiro, que por sua vez possuem o tamanho em bytes de sizeof(int*) cada.
Após isso, o endereço de memória retornado pela função foi atribuído ao ponteiro para ponteiros p, utilizando um casting de dados para prevenir erros.

Dessa forma, cada posição do vetor criado armazena um ponteiro para inteiros.
Devemos, então, alocar um vetor de inteiros para cada um desses ponteiros, criando assim uma matriz.

Para cada elemento(ponteiro) desse primeiro vetor, alocar um vetor de M elementos e atribuir o endereço de sua primeira posição a esse ponteiro.

```c
for(int i = 0; i < N; i++)
    p[i] = (int*)malloc(M * sizeof(int));
```

Perceba que, para cada posição do nosso vetor de ponteiros, atribuímos o endereço da primeira posição de um bloco de memória que foi alocado para armazenar M inteiros.

### Observações:

* Quando criamos matrizes estáticas, isto é, com tamanho predefinido, todos os elementos são armazenados em um único bloco de memória sequencial. 
* No entanto, ao criar matrizes dinâmicas, cada vetor da matriz poderá estar armazenado em regiões completamente separadas, visto que a alocação de cada vetor é feita separadamente.
* Para tornar o código mais intuitivo, é possível utilizar a função calloc ao invés da malloc.
* Como cada vetor da matriz é criado e alocado separadamente, é totalmente válido criar cada vetor com um tamanho diferente. Observe:

```c
int **m = (int**)calloc(4, sizeof(int*));

m[0] = (int*)calloc(5, sizeof(int));
m[1] = (int*)calloc(7, sizeof(int));
m[2] = (int*)calloc(6, sizeof(int));
m[3] = (int*)calloc(9, sizeof(int));
```

* É uma boa prática, para evitar erros inesperados, checar se a alocação do vetor de vetores foi realizada antes de alocar cada um dos vetores da matriz. 
* O mesmo é válido para cada um dos vetores:

```c
int **m = (int**)malloc(5*sizeof(int*));

if(m != NULL) // checa se a alocacao de m foi realizada
    for(int i = 0; i < 5; i++)
    {
        m[i] = (int*)malloc(6 * sizeof(int));
        
        if(m[i] != NULL) // checa se a alocacao de m[i] foi realizada
            for(int j = 0; j < 6; j++)
                m[i][j] = 42; // preenche toda a matriz com o valor 42
    }
```

* Para desalocar a memória alocada durante a criação de uma matriz dinâmica, novamente utilizaremos a função free.
* No entanto, como cada vetor da matriz foi alocado separadamente, devemos primeiro desalocar cada um desses vetores e, em seguida, desalocar o vetor responsável por armazenar os outros vetores.
* Observe como seria feita a desaloção da matriz dinâmica criada logo acima:

```c
for(int i = 0; i < 4; i++)
    free(m[i]);

free(m);
```

# Alterando as dimensões de uma matriz dinâmica

Uma das maiores vantagens de utilizar matrizes dinâmicas é a possibilidade de alterar tanto a quantidade de vetores armazenadas por elas, quanto a quantidade de elementos de cada um desses vetores.
Isso é possível graças a função realloc, aprendida previamente. Observe:

```c
// Aloca memoria para um vetor de 4 ponteiros inteiros
int **m = (int**)calloc(4, sizeof(int*));

// Utiliza cada elemento/ponteiro do vetor criado
// para alocar um vetor de 3 inteiros em cada
for(int i = 0; i < 3; i++)
    m[i] = (int*)calloc(3, sizeof(int));

// Altera a capacidade do segundo vetor da matriz de 3 para 5 inteiros
m[1] = (int*)realloc(m[1], 5*sizeof(int));

// Altera a capacidade do quarto vetor da matriz de 3 para 9 inteiros
m[3] = (int*)realloc(m[3], 9*sizeof(int));

// Altera a capacidade da matriz de 4 para 6 vetores
m = (int**)realloc(m, 6*sizeof(int*));
```

### Observações:

* Como a quantidade de vetores da matriz pode variar, é uma boa prática manter uma variável que armazene essa quantidade.
* Isso é importante para possibilitar a desalocação adequada da matriz:
  
```c
int **p = (int**)calloc(2, sizeof(int*));

int qtd = 2;

p[0] = (int*)calloc(3, sizeof(int));
p[1] = (int*)calloc(3, sizeof(int));

p = (int**)realloc(p, 4*sizeof(int));

qtd = 4;

p[2] = (int*)calloc(3, sizeof(int));
p[3] = (int*)calloc(3, sizeof(int));

for(int i = 0; i < qtd; i++)
    free(p[i]);

free(p);
```

* Ao diminuir o tamanho da matriz, lembre-se de desalocar os vetores que serão excluídos:

```c
// Y è uma matriz dinamica 7x4

// Para diminuir sua quantidade de vetores para 5, é
// importante desalocar os 2 últimos vetores antes:

free(Y[5]);
free(Y[6]);

Y = (int**)realloc(Y, 5*sizeof(int*));
```

* Assim como em qualquer utilização da função realloc, é importante checar se a realocação foi possível:

```c
// H é uma matriz dinamica 5x3

int **aux = (int**)realloc(H, 7*sizeof(int*));

if(aux != NULL) // checa se a realocacao foi realizada
    H = aux;
```