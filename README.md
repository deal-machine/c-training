# Data structure in C :white_check_mark:

<hr>
<h3>Implementation some exercises :bulb:</h3>

<h3>Complexity</h3>

<dl>
  <dt>BubbleSort</dt>
  <dd>
    Compara os elementos sequencialmente, e troca de lugar se não estiverem ordenados.
    Melhor caso <strong>O(N)</strong> - para todos os elementos já ordenados.
    Pior caso <strong>O(N^2)</strong> - não recomendado para vetores grandes.
  </dd>

  <dt>InsertionSort</dt>
  <dd>
    Compara o elemento e insere em seu devido lugar.
    É capaz de ordenar dados em tempo real, no momento em que são inseridos.
    Melhor caso <strong>O(N)</strong> - vetor já ordenado.
    Pior caso <strong>O(N^2)</strong> - perde desempenho em grande quantidade de dados desordenados.
  </dd>
  <dt>SelectionSort</dt>
  <dd>
    Procura em todas as posições o menor valor e ordena dessa forma.
    Melhor caso <strong>O(N^2)</strong>.
    Pior Caso<strong>O(N^2)</strong>.
  </dd>
  <dt>MergeSort</dt>
  <dd>
    Divide recursivamente o conjunto pela metade, e ordena os subconjuntos.
    Melhor caso <strong>O(N log N)</strong>.
    Pior Caso<strong>O(N log N)</strong> por ser recursivo e criar um vetor auxiliar na ordenação.
  </dd>
  <dt>QuickSort</dt>
  <dd>
    Possui a ideia em dividir o vetor e selecionar um elemento como pivô, usa recursividade para ordenar valores.
    Melhor caso <strong>O(N log N)</strong> - seleciona sempre o meio para dividir, as partições tem o mesmo tamanho.
    Caso médio <strong> O()</strong> - divide por um valor qualquer no vetor.
    Pior caso <strong> O(N^2)</strong> - caso o pivô seja o maior ou menor elemento.
  </dd>
</dl>

<h3>Data Structure</h3>
<dl>
  <dt>Ponteiros</dt>
  <dd>É um tipo simples de referência, indica um endereço de memória, para qual ele aponta.
  Em C são declarados com *, o uso pode ser de ponteiro para ponteiro **, aumentando operadores de indireção.
  
  </dd>
</dl>
<dl>
  <dt>Lista</dt>
  <dd>
  Sequêcia de elementos do mesmo tipo que possuem estrutura de nós, associados internamente. A complexidade é facultativa e não afeta o funcionamento.

  <ul>
    <li>Lista estática possui quantidade máxima(0 -> MAX-1) e o acesso é sequêncial. A desvantagem é alocação em memória mesmo sem o uso daquele espaço, pois é alicada em tempo de compilação.</li> 
    <li>Lista dinâmica aloca em tempo de execução, não precisa de tamanho máximo, trabalha com insersão e remoção liberando a memória. O acesso é encadeado, cada elemento aponta para outro elemento utilizando ponteiros.</li> 
  </ul>
  
  </dd>
</dl>
<dl>
  <dt>Fila</dt>
  <dd>
  É uma sequência de elementos do mesmo tipo. Sua complexidade é variável e não afeta o funcionamento.
  Resumindo é um tipo especial de Lista, pois as inserções e exclusões acontecem nas extremidades, entra de um lado(fim), sai pelo outro(inicio), utilizado em transações em banco de dados, fila de recursos compartilhados, etc.
  <ul>
    <li>Fila estática - 
    precisa de um tamanho máximo, sua alocação é em momento de compilação.
    </li> 
    <li>Fila dinâmica - 
    espaço em memória é definido em tempo de execução, itens são inseridos no fim e saem do inicio.
    </li>
  </ul>
  </dd>
</dl>
<dl>
  <dt>Pilha</dt>
  <dd>
    É um tipo especial de lista. Os itens inseridos e excluidos são apenas o do topo(inicio) da pilha.

    <ul>
      <li>
      Pilha estática é alocada com tamanho fixo em momento de compilação. O acesso é sequencial pois os elementos são consecultivos.
      <li>
      Pilha dinâmica aloca a memória em momento de execução, ou seja, acompanha insersão e remoção de elementos para definir seu tamanho. Para acessar um elemento é preciso conhecer seus antecessores na Pilha, mesmo estando em locais diferentes da memória, através de ponteiros. 
      </li>
    </ul>
  </dd>
</dl>
<dl>
  <dt>Operações</dt>
<dd>
    <ul>
      <li>Criação</li>
      <li>Insersão</li>
      <li>Exclusão</li>
      <li>Acesso a um elemento</li>
      <li>Destruição de uma lista</li>
    </ul>
</dd>
</dl>

<h3>To compile and run :electric_plug:</h3>
<dl>
<dt>Linux</dt> 
  <dd>you need to open <strong>src/{folder}</strong> and run the command to compile <strong>gcc {file}.c</strong>, after that, you can run with <strong>./a.out</strong></dd>
<dt>
Windows
</dt>
<dd>
Compile and run with <strong>gcc {file}.c -o {file}.exe</strong>
*you need to have the MinGW installed*
</dd>
