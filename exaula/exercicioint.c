#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int numeros; //nao precisa colocar um array, ja q ele vai ser armazenado na memoria.
  struct Node* prox; //apontando pro proximo numero
}Numero;

Numero* cabeca = NULL; //inicializar a lista encadeada

void inserir_numero(){
  Numero* novo = (Numero*)malloc(sizeof(Numero)); //aloca dinamicamente memoria pros numeros
    if(novo == NULL){
      //verifica se nao conseguiu alocar memoria
      printf("falha ao alocar memoria: ");
        return;
    }
    //le o numero e armazena no campo numero do novo nó
  printf("digite o numero: ");
    scanf("%d", &novo->numeros);

  //faz o novo nó apontar para o nó atual da cabeça
  //aponta pro oq eu botei agora
  novo->prox = cabeca;

  //atualiza o ponteiro cabeca para apontar para o novo no
  cabeca = novo;

  printf("numero inserido com sucesso\n");
}

void remover_numero(){
  if(cabeca == NULL){
    printf("lista vazia\n");
      return;
  }
  printf("digite o numero para remover: ");
  int numero_remover;
    scanf("%d", &numero_remover);
  //uso um ponteiro chamado atual para percorrer a lista
  //uso um ponteiro anterior para manter o no anterior ao no atual(necessario caso o numero seja encontrado no meio ou final)

  //inicio o ponteiro para apontar para a cabeca(primeiro no da lista)
    Numero* atual = cabeca;//comeca na cabeca da lista
    Numero* anterior = NULL;//nao tem no anterior no inicio

  //percorre a lista

  while (atual!= NULL){
  //enquanto o atual n for NULL, significa o fim da lista:
    if (atual->numeros == numero_remover){
      //encontrou o numero, agora remove o no
      if (anterior == NULL){
        //o numero ta no primeiro no
        cabeca = atual->prox;

      } else {
        //o numero ta no meio ou no final
        anterior->prox = atual->prox;
      }
      free(atual); //libera a memoria do no removido
      printf("numero removido\n");
      return;
    }
    //avanca os ponteiros
    anterior = atual;
    atual = atual->prox;
  }
  //se chegou ate aqui, o numero nao esta na lista.
    printf("numero nao encontrado\n");
}

void listar(){
  if(cabeca == NULL){
    printf("lista vazia\n");
    return;
  }

  printf("numeros na lista: \n");
  Numero* atual = cabeca;//comeca na cabeca da lista
  int indice = 1; //para numerar os itens(opcional)

  while(atual != NULL){
    //enquanto o atual n for o fim da lista
    printf("%d: %d\n", indice, atual->numeros);//percorre a lista ate o fim imprimindo o indice e o numero
    indice++;
    atual = atual->prox; // avanca para o proximo no
  }
}

void liberar_lista(){
  Numero* atual = cabeca; //o numero atual aponta pro inicio da lista, q no while vai liberando tudo
  while (atual != NULL){
    Numero* temp = atual; //armazena o no atual temporariamente
    atual = atual->prox; //avanca para o proximo no
    free(temp);
  }
  cabeca = NULL; //garante q a lista esteja vazia
  printf("lista liberada\n");
}

int main(){
  int opcao;

  do{
    printf("1) adicionar numero\n");
    printf("2) remover numero\n");
    printf("3) listar numeros\n");
    printf("4) liberar a lista\n");
    printf("5) sair\n");
    scanf("%d", &opcao);

    switch (opcao){
      case 1:
        inserir_numero();
        break;
      case 2:
        remover_numero();
        break;
      case 3:
        listar();
        break;
      case 4:
        liberar_lista();
      case 5:
        break;
      default:
        printf("opcao invalida\n");
    }
  } while(opcao != 5);
}