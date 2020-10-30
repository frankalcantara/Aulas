//em c para atender a solicitação dos alunos.
#include<stdlib.h>
#include<stdio.h>

//definindo um tipo para não ter que usar a palavra struct o tempo todo
typedef struct no {
    int dadoQualquer;
    int ordem;
    struct no * direita, * esquerda;
} vertice;

//protótipos
void inserirVertice( vertice **, int, int );

void displayPreOrder(vertice * ); //esquerda, raiz , direita
void displayInOrder(vertice * );  //raiz, esquerda, direita
void displayPostOrder(vertice *); //esquerda, direita, raiz

void apagarArvore(vertice * tree);

int busca(vertice *, int );

int main(){
    vertice *root;
    root = NULL;
    //inserindo nós e colocando um valor em cada um
    inserirVertice(&root, 9, 0);
    inserirVertice(&root, 4, 1);
    inserirVertice(&root, 15, 2);
    inserirVertice(&root, 6, 3);
    inserirVertice(&root, 12, 4);
    inserirVertice(&root, 17, 5);
    inserirVertice(&root, 2, 6);

    //imprimindo os nós da árvore
    printf("\n Pre-Order: \n");
    displayPreOrder(root);

    printf("\n In-Order: \n");
    displayInOrder(root);

    printf("\n Post-Order:\n");
    displayPostOrder(root);

    //busca nos nós da árvore
    int vertice = busca(root, 23);
    if (vertice >= 0){
        printf("\n\n Valor encontrado no vértice: %d", vertice);
    }else{
      printf("\n\n O valor não está na árvore");
    }

    // apagando todos os nós da árvore
    apagarArvore(root);
    return 0;
}

//observe que há uma regra de inserção
void inserirVertice( vertice ** tree, int val, int ordem){
    vertice *temp = NULL;
    if(!(*tree)){
        //malloc sempre devolve void então temos que explicitar
        temp = (vertice *)malloc(sizeof(vertice));
        temp->esquerda = temp->direita = NULL;
        temp->dadoQualquer = val;
        temp->ordem = ordem;
        *tree = temp;
        return;
    }

    if(val < (*tree)->dadoQualquer){
        inserirVertice(&(*tree)->esquerda, val, ordem);
    } else if(val > (*tree)->dadoQualquer){
        inserirVertice(&(*tree)->direita, val, ordem);
    }
}

int busca(vertice *raiz, int key){
    while (raiz != NULL){
        if (key > raiz->dadoQualquer){
            return busca(raiz->direita, key);
        } else if (key < raiz->dadoQualquer){
            return busca(raiz->esquerda, key);
        } else { 
            return raiz->ordem;
        }
    }
    return -1;
}

void displayPreOrder(vertice * tree){
    if (tree){
        printf("%d,\t",tree->dadoQualquer);
        displayPreOrder(tree->esquerda);
        displayPreOrder(tree->direita);
    }

}

void displayInOrder(vertice * tree){
    if (tree){
        displayInOrder(tree->esquerda);
        printf("%d,\t",tree->dadoQualquer);
        displayInOrder(tree->direita);
    }
}

void displayPostOrder(vertice * tree){
    if (tree){
        displayPostOrder(tree->esquerda);
        displayPostOrder(tree->direita);
        printf("%d,\t",tree->dadoQualquer);
    }
}

//remove todos os vertices da memória apagando a árvore
void apagarArvore(vertice * tree){
    if (tree){
        apagarArvore(tree->esquerda);
        apagarArvore(tree->direita);
        free(tree);
    }
}


