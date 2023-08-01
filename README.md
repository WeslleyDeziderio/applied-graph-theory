<h1>Teoria dos Grafos Aplicada - Trabalho 1</h1>

<div>

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

<h1>Execução</h1>

<div>

Na raíz do projeto, execute o comando `make`. Para executar uma instância basta passar o comando ./concepts instances/\<instancia_a_ser_executada\>

</div>