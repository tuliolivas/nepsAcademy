I. Operador E
Imagine o seguinte problema: como descobrir se um número inteiro é par e positivo?

Para resolver este problema, primeiro precisamos saber quais são as condições necessárias
para que um inteiro x seja par e positivo:
Par: x % 2 == 0
Positivo: x>0

Sabendo essas condições, podemos prosseguir com duas abordagens:

Fazer dois if's, um dentro do outro.

if( x % 2 == 0 ){ // checa se x eh par
    if( x > 0){ // se x for par, entao checa se ele eh positivo
        printf("Par e positivo!\n"); // se x for par e positivo, executa o printf
    }
}

Fazer apenas um if utilizando o operador lógico E.
Para não termos que usar um if dentro do outro, podemos utilizar o operador lógico E.
Este operador é representado pela junção de dois e-comerciais (&&) e apenas terá valor
verdadeiro se as duas afirmações a serem analisadas forem verdadeiras. Sua sintaxe é a seguinte:

<afirmacao1> && <afirmacao2>

Portanto, para a resolução do nosso problema, onde x deve ser par e positivo, podemos utilizar
este operador da seguinte maneira:

if( x % 2 == 0 && x > 0 ){
    printf("Par e positivo!\n");
}

Dessa forma, a condição analisada pelo if só será verdadeira se as duas afirmações (par e positivo) forem verdadeiras.

II. Operador OU
Agora, imagine outro problema: como descobrir se um número é par ou positivo?
Neste caso, temos novamente duas abordagens:

Fazer dois if's.

if( x % 2 == 0 ){ // checa se x eh par
    printf("Par ou positivo!\n"); // se x for par, executa o printf
}

if( x > 0){ // checa se x eh positivo
    printf("Par ou positivo\n"); // se x for positivo, executa o printf
}

Fazer apenas um if utilizando o operador lógico OU.
Para não termos que usar dois if's, podemos utilizar o operador lógico OU.
Este operador é representado pela junção de duas barras verticais (||) e terá valor
verdadeiro se ao menos uma das duas afirmações a serem analisadas forem verdadeiras.
Sua sintaxe é a seguinte:

<afirmacao1> || <afirmacao2>

Portanto, para a resolução do nosso problema, onde x deve ser par ou positivo, podemos
utilizar este operador da seguinte maneira:

if( x % 2 == 0 || x > 0 ){
    printf("Par ou positivo!\n");
}

Dessa forma, a condição analisada pelo if será verdadeira se ao menos uma das duas afirmações (par ou positivo) for verdadeira.
Isto é, se o número for par, ou positivo, ou par e positivo.

III. Precedência
Em operações onde vários operadores lógicos são utilizados, tem-se que os operadores E são verificados antes dos operadores OU. 
Para facilitar o entendimento, analise este exemplo:

Exemplo:

// falso  falso verdadeiro
if( 2<1 && 2<0 || 1<2 ){
    printf("Entrou no IF\n");
}
/* Saída: 
Entrou no IF

*/

Perceba que, como comentado no código, a primeira afirmação é falsa, a segunda é falsa e a terceira é verdadeira.
Para facilitar a visualização, podemos representar da seguinte forma:

if(falso && falso || verdadeiro){
    printf("Entrou no IF\n");
}

De acordo com a precedência, tem-se que o operador E será analisado primeiro.
Como as duas afirmações que ele analisa são falsas, logo seu valor também será falso. Dessa forma, podemos reduzir a condição:

if(falso || verdadeiro){
    printf("Entrou no IF\n");
}

Analisando o operador OU, tem-se que seu valor é verdadeiro, pois a segunda a firmação também é.
Logo, a condição analisada pelo if tem valor verdadeiro e o printf é executado.

IV. Parênteses
Assim como nos operadores aritméticos, podemos utilizar parênteses para alterar a ordem de execução dos operadores.
Dessa forma, se o código acima for escrito da seguinte forma, teremos um resultado completamente diferente:

Exemplo:

if(2<1 && (2<0 || 1<2) ){
    printf("Entrou no IF\n");
}
/* Saída: 

*/

Perceba que, ao analisar primeiramente o OU, obteremos valor verdadeiro, pois sua segunda afirmação é verdadeira.
Após isso, o operador E será analisado e resultará em falso, pois, por mais que sua segunda afirmação seja verdadeira,
a primeira é falsa.
Portanto, o printf dentro do if não será executado e nada será impresso na tela.