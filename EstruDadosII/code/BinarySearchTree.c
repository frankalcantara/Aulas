/**
 * @file BinarySearchTree.c
 * @author Frank de Alcantara
 * @brief Exemplo de BST, com funções utilitárias
 * @version 0.1
 * @date 2021-02-16
 */
#include<stdio.h>
#include<stdlib.h>
#include <time.h> //só para gerar os randômicos

/**
 * @brief estrutura para a árvore com um único dado
 * 
 */
typedef struct vertice{
  int dado;
  struct vertice *esquerda;
  struct vertice *direita;
}vertice;

/**
 * @brief para usar cores no terminal linux 
 * disponível em: https://github.com/sol-prog/ansi-escape-codes-windows-posix-terminals-c-programming-examples/blob/master/ansi_escapes.h
 */
enum Colors {
    RESET_COLOR,
    BLACK_TXT = 30,
    RED_TXT,
    GREEN_TXT,
    YELLOW_TXT,
    BLUE_TXT,
    MAGENTA_TXT,
    CYAN_TXT,
    WHITE_TXT,

    BLACK_BKG = 40,
    RED_BKG,
    GREEN_BKG,
    YELLOW_BKG,
    BLUE_BKG,
    MAGENTA_BKG,
    CYAN_BKG,
    WHITE_BKG    
};

/**
 * @brief Apenas para determinar as cores no terminal
 * 
 * @param code 
 */
static inline void setTextColor(int code) {
    printf("\x1b[%dm", code);
}

//protótipos das funções utilitárias
vertice* minimo(vertice *);
vertice* maximo(vertice *);
vertice * inserirVertice(vertice *, int );
//para apagar um vértice que contenha um valor específico
vertice * apagarVertice(vertice *, int );
//para ver se um determinado valor está na árvore
vertice * buscarVertice(vertice *, int );

//só para mostrar na tela
void displayInOrder(vertice *);
void displayPreOrder(vertice *);
void displayPostOrder(vertice *);

int main(){
  //criando o primeiro nó e apontando para nada
  vertice * arvore = NULL;
  //quantos vertices a árvore vai ter
  int numeroVertices = 15;
  // Semente para o gerador de randômicos
  srand(time(0)); 
  //gerando a árvore de forma aleatória con numeroVertices nós
  for (int i = 0; i < numeroVertices; i++){
    arvore = inserirVertice(arvore, (rand() % 100)+1);  
  }
  
  //mostrar a árvore
  displayPreOrder(arvore);
  printf("\n\n");
  
  //testando a função para apagar nós
  int node;
  printf( "Escolha um dos vértices para apagar: ");
  scanf("%d", &node);
  printf("\n");

  //para apagar o vértice selecionado
  arvore = apagarVertice(arvore,node);
  
  //arvore com o nó apagado.
  displayPreOrder(arvore);
  printf("\n");
  printf("\n");
  
  //testando as funções de mínimo e máximo
  vertice * temp;
  
  temp = minimo(arvore);
  printf("O menor elemento é: %d\n",temp->dado);

  temp = maximo(arvore);
  printf("O maior elemento é: %d\n", temp->dado);
  
  //testando a função de busca
  printf( "Escolha um dos vértices que exista: ");
  scanf("%d", &node);
  printf("\n");
 
  temp = buscarVertice(arvore,node);
  if(temp==NULL){
    printf("Vértice não encontrado!\n");
  } else {
    printf("Vértice encontrado!\n");
  }
  
  //testando a função de busca
  printf( "Escolha um vértice que não exista: ");
  scanf("%d", &node);
  printf("\n");
 
  temp = buscarVertice(arvore,node);
  if(temp==NULL){
    printf("Vértice não encontrado!\n");
  } else {
    printf("Vértice encontrado!\n");
  }
  return 0;
}//fim do main

/**
 * @brief Encontra o menor vértice
 * 
 * @param node - ponteiro para estrutura da árvore
 * @return vertice* 
 */
vertice* minimo(vertice *node){
  if(node==NULL){
    //nenhum elemento na árvore
    return NULL;
  }
    
  if(node->esquerda){ 
    // tentar encontrar o valor mínimo a esquerda recursivamente
      return minimo(node->esquerda);
  } else{
       return node;
  } 
}

/**
 * @brief Encontra o maior vértice 
 * 
 * @param node - ponteiro para a estrutura da árvore
 * @return vertice* 
 */
vertice* maximo(vertice *node){
  if(node==NULL){
    //nenhum elemento na árvore
    return NULL;
  }
    
  if(node->direita){ 
    // tentar encontrar o valor mínimo a esquerda recursivamente
      return maximo(node->direita);
  } else{
       return node;
  } 
}

/**
 * @brief Insere um nó na estruturada árvore
 * 
 * @param node - ponteiro para estrutura da árvore
 * @param dado - dado que será inserido
 * @return vertice* 
 */
vertice * inserirVertice(vertice *node, int dado){
  if(node==NULL){
    //a árvore está vazia
    vertice * temp;
    //aloca memória para um nó
    temp = (vertice *)malloc(sizeof(vertice));
    temp -> dado = dado;
    //nós da esquerda e direita apontando para lugar nenhum
    temp -> esquerda = temp -> direita = NULL;
    return temp;
  }

  if(dado > (node->dado)){
    //o dado que será inserido é menor
    node->direita = inserirVertice(node->direita,dado);
  } else if(dado < (node->dado)){
    //o dado que será inserido é maior
    node->esquerda = inserirVertice(node->esquerda,dado);
  }
  //não é maior, nem menor, não temos nada para fazer
  return node;
}

/**
 * @brief Apaga um nó específico
 * 
 * @param node - ponteiro para estrutura da árvore
 * @param dado - valor que será apagado
 * @return vertice* 
 */
vertice * apagarVertice(vertice *node, int dado){
  vertice * temp;

  if(node==NULL){
    printf("\nEste nó não Existe\n");
  } else if(dado < node->dado){
    node->esquerda = apagarVertice(node->esquerda, dado);
  } else if(dado > node->dado) {
    node->direita = apagarVertice(node->direita, dado);
  } else {
    //podemos apagar o nó e colocar o nó do valor mínimo ou máximo
    
    if(node->direita && node->esquerda){
      // o menor valor que estiver a direita
      temp = minimo(node->direita);
      node -> dado = temp->dado; 
      // temos que apagar o nó de onde tiramos esta dado                  
      node -> direita = apagarVertice(node->direita,temp->dado);
    } else {
      //mas se tiver nenhum filho, ou apenas um, podemos remover 
      //diretamente e conectar o filho deste nó no pai deste nó
      temp = node;
      
      if(node->esquerda == NULL)
        node = node->direita;
      else if(node->direita == NULL)
        node = node->esquerda;
      
      free(temp); //libera o no temporário
    }
  }
  
  return node;
}

/**
 * @brief busca na árvore um dado específico
 * 
 * @param node - ponteiro para estrutura da árvore
 * @param dado - dado a ser encontrado
 * @return vertice* 
 */
vertice * buscarVertice(vertice *node, int dado){
  if(node==NULL){
    //árvore vazia, não vai encontar nada
    return NULL;
  }
  
  if(dado > node->dado){
    //procura a direita
    return buscarVertice(node->direita,dado);
  }else if(dado < node->dado){
    //busca a esquerda
    return buscarVertice(node->esquerda,dado);
  } else {
    //se encontrar algo retorna o vertice
    return node;
  }
}

/**
 * @brief Rotina de pesquisa transversal in-order
 * 
 * @param node - ponteiro para estrutura da árvore
 */
void displayInOrder(vertice *node){
  if(node==NULL){
    //árvore vazia    
    return;
  }
  displayInOrder(node->esquerda);
  //para apresentar
  if ((node->esquerda == NULL)&&(node->direita == NULL)){
    setTextColor(GREEN_TXT);  
    printf("%d",node->dado);
    setTextColor(RESET_COLOR);
  } else{
    printf("%d",node->dado);
  }
  
  if(node->esquerda != NULL){
    setTextColor(RED_TXT);
    printf("(E:%d)",node->esquerda->dado);
    setTextColor(RESET_COLOR);
  }
      
  if(node->direita != NULL){
    setTextColor(BLUE_TXT);
    printf("(D:%d)",node->direita->dado);
    setTextColor(RESET_COLOR);
  }
  printf("\n");
  displayInOrder(node->direita);
}

/**
 * @brief Rotina de pesquisa transversal pre-order
 *
 * @param node - ponteiro para estrutura da árvore
 */
void displayPreOrder(vertice *node){
  if(node==NULL){
    //árvore vazia
    return;
  }
  //para apresentar
  if ((node->esquerda == NULL)&&(node->direita == NULL)){
    //esta é uma folha
    setTextColor(GREEN_TXT);  
    printf("%d",node->dado);
    setTextColor(RESET_COLOR);
  } else{
    //não é uma folha
    printf("%d",node->dado);
  }
 
  if(node->esquerda != NULL){
    //existe um filho e está na esquerda
    setTextColor(RED_TXT);
    printf("(E:%d)",node->esquerda->dado);
    setTextColor(RESET_COLOR);
  }
      
  if(node->direita != NULL){
    //um filho e está na direita
    setTextColor(BLUE_TXT);
    printf("(D:%d)",node->direita->dado);
    setTextColor(RESET_COLOR);
  }
  printf("\n");
  displayPreOrder(node->esquerda);
  displayPreOrder(node->direita);
}

/**
 * @brief Rotina de pesquisa transversal post-order
 *
 * @param node - ponteiro para estrutura da árvore
 */
void displayPostOrder(vertice *node){
  if(node==NULL){
    //árvore vazia
    return;
  }
  displayPostOrder(node->esquerda);
  displayPostOrder(node->direita);
  //para apresentar
   if ((node->esquerda == NULL)&&(node->direita == NULL))
  {
    setTextColor(GREEN_TXT);  
    printf("%d",node->dado);
    setTextColor(RESET_COLOR);
  } else{
    printf("%d",node->dado);
  }
  
  if(node->esquerda != NULL){
    setTextColor(RED_TXT);
    printf("(E:%d)",node->esquerda->dado);
    setTextColor(RESET_COLOR);
  }
      
  if(node->direita != NULL){
    setTextColor(BLUE_TXT);
    printf("(D:%d)",node->direita->dado);
    setTextColor(RESET_COLOR);
  }
  printf("\n");
}

