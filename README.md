<h1>Teoria dos Grafos Aplicada - Trabalho 1</h1>

[![author](https://img.shields.io/badge/author-WeslleyDeziderio-blue.svg)](https://github.com/WeslleyDeziderio)
[![](https://img.shields.io/badge/C++-navy.svg)](https://en.cppreference.com/w/cpp/23)

<div>

O programa de vocês fará a leitura de um grafo informado através de um arquivo de texto. O formato do arquivo é o seguinte:

![Figura 1](assets/file_format.png)

![Figura 1](assets/figura1.png)

![Figura 1](assets/file.png)


 1 - **Leitura e representação do grafo**

Faça um código que leia o grafo de um arquivo e o represente nas duas formas vistas em sala: matriz de adjacências e lista de adjacências. Nas próximas questões, leve em conta que as duas representações do grafo estarão disponı́veis para tornar as implementações mais eficientes. 

</div>

<div>

2 - **Graus mínimo e máximo**

Escreva uma função que calcule os graus mínimo δ(G) e máximo Δ(G) de G. Para o grafo da Figura 1 (instance_1.txt), temos que δ(G)=2 e Δ(G)=5.

</div>

<div>

3 - **Sequência de graus**

Escreva uma função que determine a sequência de graus de G. 

</div>

<div>

4 - **Grau e vizinhanças de um vértice v**

Escreva uma função que determine o grau e as vizinhanças aberta e fechada de um vértice v.

</div>

<div>

5 - **Adjacência**

Escreva uma função que que determine se dois vértices distintos u e v são vizinhos (ou adjacentes). Lembrando que eles são vizinhos se a aresta entre eles existir, ou seja, se (u,v)∈E. Em caso afirmativo, diz-se que u e v são os extremos de tal aresta. 

</div>

<div>

6 - **Regularidade**

Um grafo é regular se todos os seus vértices possuem o mesmo grau. Se o grau de todos os vértices for igual a k, diz-se que o grafo é k-regular. Escreva uma função que informe se G é regular, deixando claro o valor do grau em caso afirmativo. Abaixo segue um exemplo de um grafo 5-regular.

![Regularidade](assets/q6.png "Grafo 5-regular")


</div>

<div>

7 -**Completude**

Escreva uma função que informe se G é completo, ou seja, se ele possui todas as arestas possíveis. Sendo n o número de vértices de G, vimos em sala que um grafo simples pode ter de 0 a n(n−1)/2 arestas. Portanto, o grafo completo com n vértices, denotado por Kn, possui n(n−1)/2 arestas. Abaixo ilustra-se o grafo K7.

![Completude](assets/q7.png)


</div>

<div>

8 - **Vértices Universais**

Escreva uma função que liste todos os vértices universais de G, que são os vértices que estão ligados a todos os outros vértice do grafo. O grau de um vértice universal é, portanto, igual a n−1.


</div>

<div>

9 - **Vértices Isolados**

Escreva uma função que liste todos os vértices isolados de G, que são os vértices que não possuem vizinhos. O grau de um vértice isolado é, portanto, igual a 0.

</div>

<div>

10 - **Subgrafos**

Escreva uma função que determine se uma lista de vértices e uma lista de arestas informadas pelo usuário representam um subgrafo H de G. Para H ser subgrafo de G, todos os seus vértices e suas arestas devem estar contidos, respectivamente, nos conjuntos de vértices e arestas de G. Além disso, os extremos de todas as arestas listadas pelo usuário devem estar contidos no conjunto de vértices informado, do contrário não se trata de um grafo pois teríamos uma aresta sem os dois extremos.

</div>

<div>

11 - **Passeios**

Uma sequência de k vértices v1,v2,...,vk é um passeio em G se, para todo 1≤i≤k−1, vale que vi e vi+1 são vizinhos. Isso equivale a dizer que vértices adjacentes na sequência devem ser vizinhos. Não há outra restrição a ser considerada na definição de passeio, sendo possível, por exemplo, repetir vértices e arestas. Um exemplo de passeio no grafo da Figura 1 é 1,2,3,4,3,6.

Escreva uma função que determine se uma sequência de vértices constitui um passeio em G.

</div>

<div>

12 - **Caminhos**

Um caminho é um passeio que não repete vértices. O passeio 1,2,3,4 é um caminho no grafo da Figura 1.

Escreva uma função que determine se uma dada sequência de vértices constitui um caminho em G.

</div>

<div>

13 - **Ciclos**

Um ciclo é um passeio que não repete vértices, com exceção do primeiro e último vértices, que são iguais. O passeio 1,2,4,3,1 é um ciclo no grafo da Figura 1.

Escreva uma função que determine se uma dada sequência de vértices constitui um ciclo em G.

<div>

<div>

14 - **Trilhas**

Uma trilha é um passeio que não repete arestas.

Escreva uma função que determine se uma dada sequência de vértices constitui uma trilha em G.

<div>

<div>

15 - **Cliques**

Um subconjunto de vértices S⊆V é um clique de G se, para quaisquer dois vértices distintos i,j∈S, existe a aresta (i,j) no grafo. Portanto, os vértices de um clique estão dois a dois conectados por uma aresta. Os seguintes conjuntos são exemplos de clique do grafo da Figura 1: {1,2},{1,2,3},{1,2,3,4}.

Escreva uma função que determine se um dado conjunto de vértices constitui um clique de G.

<div>

<div>

16 - **Clique Maximal**

Um clique S⊆V é dito maximal se não houver outro clique S′ tal que S′⊇S. Isto é, se não for possível expandir o conjunto S através da inserção de um ou mais vértices de modo que o conjunto resultante ainda seja um clique. Os seguintes conjuntos são exemplos de cliques maximais do grafo da Figura 1: {1,2,3,4},{5,6,7}. Observe que o conjunto {1,2,3}, apesar de ser clique, não é maximal pois ele poderia ser estendido através da adição do vértice 4.

Escreva uma função que determine se um dado conjunto de vértices constitui um clique maximal de G.

<div>

17 - **Complemento**

O complemento de G é um grafo G¯=(V,E¯) que possui os mesmos vértices de G, mas cujo conjunto de arestas é o complemento do conjunto de arestas de G. Portanto, uma aresta (i,j) pertence a E¯ se, e somente se, ela não pertece a E. O grafo abaixo corresponde ao complemento do grafo ilustrado na Figura 1.

![Complemento](assets/q17.png)

</div>

<div>

18 - **Conjunto Indenpendente**

Um subconjunto de vértices S⊆V é um conjunto independente de G se, para quaisquer dois vértices distintos i,j∈S, não existe a aresta (i,j) no grafo. O conjunto {1,7} é um exemplo de conjunto independente do grafo da Figura 1.

Usando suas respostas dos itens 15 e 17, escreva uma função que determine se um dado conjunto de vértices constitui um conjunto independente de G.

<div>

<h1>Execução</h1>

<div>

Na raíz do projeto, execute o comando `make`. Para executar uma instância basta passar o comando ./concepts instances/\<instancia_a_ser_executada\>

</div>