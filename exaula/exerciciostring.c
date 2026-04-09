#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nome {
  char nome[100];
  struct nome *prox;
}Nome;

Nome* cabeca = NULL; //cabeca da lista encadeada

void inserir_nome(){
  Nome* novo = (Nome*)malloc(sizeof(Nome));
  if (novo == NULL){
    printf("erro ao alocar a memoria");
      return;
  }
  printf("Digite o nome: ");
    fgets(novo->nome, 100, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0'; //remove a nova linha
    novo->prox = cabeca;
    cabeca = novo;
      printf("nome adicionado com sucesso\n");
}
void remover_nome(){
  if (cabeca == NULL){
    printf("lista vazia!\n");
      return;
  }
    printf("digite o nome a ser removido: ");
    char nome_remover[100];
    fgets(nome_remover, 100, stdin);
    nome_remover[strcspn(nome_remover, "\n")] =  '\0'; //remove a nova linha

    Nome* atual = cabeca;
    Nome* anterior = NULL;

    while (atual != NULL){
      if (strcmp(atual->nome, nome_remover) == 0){
        if (anterior == NULL){
          cabeca = atual->prox;
        } else {
          anterior->prox = atual->prox;
        }
        free(atual);
        printf("nome removido com sucesso!\n");
        return;
      }
      anterior = atual;
      atual = atual->prox;
    }
    printf("nome nao encontrado\n");
  }
void listar(){
  if (cabeca == NULL){
    printf("lista vazia\n");
    return;
  }
  printf("nomes na lista:\n");
  Nome* atual = cabeca;
  int indice = 1;

  while(atual != NULL){
    printf("%d: %s\n", indice++, atual->nome);
    atual = atual->prox;
  }
}

int main(){

  int opcao;
do{
  printf("1: adicionar nome\n");
  printf("2: remover nome\n");
  printf("3: listar\n");
  printf("4: sair\n");
  scanf("%d", &opcao);
  getchar();

  switch(opcao){
    case 1: 
      inserir_nome();
        break;
    case 2:
      remover_nome();
        break;
    case 3:
      listar();
    case 4:
      break;
    default:
      printf("Opcao invalida!");
  }

}while(opcao != 4);

   Nome* atual = cabeca;
    while (atual != NULL) {
        Nome* temp = atual;
        atual = atual->prox;
        free(temp);
    }

  return 0;

}
