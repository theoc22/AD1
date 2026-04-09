#include <stdio.h>
#include <stdlib.h>


typedef struct pessoa {
  char nome[30];
  int idade;
  float altura;
  struct pessoa *prox; 
} Pessoa;


Pessoa *lista = NULL; 

void inserir() {
  
  Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa)); 

  if (novo == NULL) {
    printf("Falha ao alocar a memoria\n");
    return;
  }

  printf("Insira um nome: ");
  scanf("%s", novo->nome); // char nn usa &
  printf("Insira idade: ");
  scanf("%d", &novo->idade);
  printf("Insira altura: ");
  scanf("%f", &novo->altura);

  
  novo->prox = lista; 
  lista = novo;      
  
  printf("Pessoa adicionada com sucesso!\n\n");
}

void listar() {
  if(lista == NULL){
    printf("Lista vazia!\n\n");
    return;
  }

  printf("Pessoas na lista: \n");
  
  //crio um ponteiro inicial pro inicio da lista
  Pessoa *p = lista; 
  int indice = 1; 

  
  while(p != NULL) {
    printf("Pessoa %d: %s | %d anos | %.2fm \n", indice, p->nome, p->idade, p->altura);
    p = p->prox;
    indice++;
  }
  printf("\n");
}

int main() {
  int opcao;
  do {
    printf("1: Adicionar pessoa \n");
    printf("2: Listar \n");
    printf("3: Sair \n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    getchar(); 

    switch(opcao) {
      case 1: 
        inserir();
        break;
      case 2:
        listar();
        break;
      case 3:
        printf("Saindo...\n");
        break;
      default:
        printf("Opcao invalida!\n");
    }
  } while(opcao != 3);
  
  return 0;
}