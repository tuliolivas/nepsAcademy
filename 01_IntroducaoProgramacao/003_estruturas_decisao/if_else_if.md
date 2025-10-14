I. Exemplo de problema
Um aluno tem média x, e gostaria de saber se está aprovado, reprovado ou de avaliação final.
Considere que um aluno está aprovado se sua média for maior ou igual à 7,
reprovado se sua média for menor que 4 e de avaliação final se não estiver nem aprovado nem reprovado.
Para resolver este problema, temos as seguintes 2 opções:

i. Fazer três if's: um perguntando a média é maior ou igual à 7,
outro perguntando se ela é menor que 4 e outro perguntando se ela é menor que 7 e maior ou igual à 4.

if( x >= 7 ){ // checa se x eh maior ou igual a 7
    printf("Aprovado!\n");
}

if( x < 4 ){ // checa se x eh menor que 4
    printf("Reprovado!\n");
}

if( x < 7 && x >= 4 ){ // checa se x eh menor que 7 e maior ou igual a 4
    printf("Avaliacao final!\n");
}

ii. Utilizar a estrutura if-else-if.

*Estrutura if-else-if*
Para utilizar a segunda opção apresentada, precisaremos aprender o que é e como utilizar a estrutura if-else-if.
É uma estrutura que especifica um passo a passo caso uma condição seja verdadeira e
outro passo a passo caso a primeira condição seja falsa e uma segunda condição seja verdadeira.
Essa estrutura segue o template abaixo:

if( condicao1 ){
    // se condicao1 for verdadeira
}

else if( condicao2 ){
    // se condicao1 for falsa e condicao2 for verdadeira
}

Na estrutura acima, o bloco de código contido dentro do primeiro if será executado apenas se a condição 1 for verdadeira.
Se, e apenas se, a condição 1 for falsa, então a condição 2 será testada e, caso seja verdadeira,
então o bloco de código contido dentro do else if será executado.
Perceba que a segunda condição é testada apenas se a primeira for falsa.
Assim sendo, podemos ler o código acima da seguinte forma: "Se esta condição for verdadeira, execute isto.
Caso contrário, se esta outra condição for verdadeira, execute isto."
Esta estrutura ainda pode ser expandida, utilizando múltiplos else if's e terminando com um else, como mostrado abaixo:

if( condicao1 ){
    // se condicao1 for verdadeira
}

else if( condicao2 ){
    // se condicao1 for falsa e condicao2 for verdadeira
}

else if( condicao3 ){
    // se condicao2 for falsa e condicao3 for verdadeira
}

else if( condicao4 ){
    // se condicao3 for falsa e condicao4 for verdadeira
}

else{
    // se condicao4 for falsa
}

No código acima, a primeira condição será testada.
Caso seja verdadeira, seu respectivo código será executado e toda a cadeia de if-else-if será interrompida,
pois a próxima condição nem mesmo será testada. Caso contrário, então a segunda condição será testada.
Se ela for verdadeira, então seu respectivo código será executado e a cadeia será interrompida.
Senão, então a terceira condição será testada, e assim por diante.
Se todas as condições forem falsas, então o código contido dentro do else será executado.
Dessa forma, para resolver o exercício apresentado acima pelo segundo método, teremos o seguinte código:

if( x >= 7){ // checa se x eh maior ou igual a  7
    printf("Aprovado!\n");
}

else if( x < 4 ){ // caso a condicao acima seja falsa, testa se x eh menor que 4
    printf("Reprovado!\n");
}

else{ // caso todas as condicoes acima sejam falsas
    printf("Avaliacao final!\n");
}