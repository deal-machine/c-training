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
  <strong>Definição - </strong> sequêcia de elementos do mesmo tipo que possuem estrutura de nós, associados internamente. A complexidade é facultativa e não afeta o funcionamento.
  <strong>Operações - </strong>
  <ul>
    <li>Criação</li>
    <li>Insersão</li>
    <li>Exclusão</li>
    <li>Acesso a um elemento</li>
    <li>Destruição de uma lista</li>
  </ul>
  <strong>Tipo de alocação em memória</strong>
  <ul>
    <li>Lista estática possui quantidade máxima(0 -> MAX-1) e o acesso é sequêncial. A desvantagem é alocação em memória mesmo sem o uso daquele espaço, pois é alicada em tempo de compilação.</li> 
    <li>Lista dinâmica aloca em tempo de execução, não precisa de tamanho máximo, trabalha com insersão e remoção liberando a memória. O acesso é encadeado, cada elemento aponta para outro elemento utilizando ponteiros.</li> 
  </ul>
  </dd>
</dl>
<dl>
  <dt>Fila</dt>
  <dd></dd>
</dl>
<dl>
  <dt>Pilha</dt>
  <dd></dd>
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
