#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//delcaro os tamanhos
#define MAX_PESSOAS 10
#define TAM_NOME 50
#define TAM_IDADE 4
#define TAM_EMAIL 50
#define TAM_PESSOA (TAM_NOME + TAM_IDADE + TAM_EMAIL) //104

#define OFF_QUANTIDADE  0
#define OFF_OPCAO       4
#define OFF_BUSCA       8
#define OFF_PESSOAS    58

#define TAM_BUFFER  (OFF_PESSOAS + (TAM_PESSOA * MAX_PESSOAS))

int verificaP( char *pBuffer, char *pNome ){

  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);

  int *pI = ( int * )(pBuffer + OFF_OPCAO);
  *pI = 0;

  while ( *pI < *pQuantidade ){
    char *pPessoa = pBuffer + OFF_PESSOAS + (TAM_PESSOA * (*pI)); //uso o indice pra ir acessando as pessoas em sequencia
    char *pNomeAtual = pPessoa + 0;

  if ( strcmp(pNomeAtual, pNome) == 0){
    return 1;
  } 

  *pI += 1;
  }
  return 0;
}

//funcao pra adc pessoa

void adicionarP ( char *pBuffer ){
  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE); //faco o casting e aponto pro inicio do buffer

  if (*pQuantidade >= MAX_PESSOAS){
    printf("lista cheia");
    return;
  }

  char *pPessoa = pBuffer + OFF_PESSOAS + ( TAM_PESSOA * (*pQuantidade)); //pulo contador quantidade. ai eu vejo
  //quantas pessoas tem, e vou pulando. pq: nome[50], idade[4], email[50] = 104. pulo a pessoa assim

  //divido a pessoa em pedacos
  char *pNome = pPessoa + 0;
  int *pIdade = ( int * )( pPessoa + TAM_NOME ); //puclo 
  char *pEmail = pPessoa + TAM_NOME + TAM_IDADE; //pulo a memoria pra chegar no espaco do email

  printf("escreva o nome: ");
    scanf("%s", pNome);
//se eu tiver achado um nome igual
//passo os argumentos como o buffer (lista toda) e o nome
  if (verificaP(pBuffer, pNome) == 1){
    printf("essa pessoa ja esta na agenda\n");

    return;
  }

  printf("escreva a idade: ");
    scanf("%d", pIdade);

  printf("escreva o email: ");
    scanf("%s", pEmail);

  *pQuantidade += 1;
}

void listarP( char *pBuffer ){
  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);

  int *pI = ( int * )(pBuffer + OFF_OPCAO); //reuso a memoria da opcao e uso como contador

  *pI = 0;

  //faco um while usando o indicie pI ate chegar no pQuantidade
  while ( *pI < *pQuantidade){
    char *pPessoa = pBuffer + OFF_PESSOAS + (TAM_PESSOA * (*pI)); //uso o indice pra ir acessando as pessoas em sequencia
    char *pNome = pPessoa + 0;
    int *pIdade = ( int * )( pPessoa + TAM_NOME );
    char *pEmail = pPessoa + TAM_IDADE + TAM_NOME; //mesma coisa

    printf("Nome: %s\n",  pNome);
    printf("Idade: %d\n", *pIdade);
    printf("Email: %s\n", pEmail);

    *pI += 1;

  }
} 

void removerP( char *pBuffer ){

  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);
  
  int *pI = ( int * )(pBuffer + OFF_OPCAO);
  *pI = 0;

  char *pBusca = pBuffer + OFF_BUSCA;

  printf("escreva o nome para remover: ");
    scanf("%s", pBusca);

  //while pra percorrer a lista
  while ( *pI < *pQuantidade ){
    char *pPessoa = pBuffer + OFF_PESSOAS + (TAM_PESSOA * (*pI)); //uso o indice pra ir acessando as pessoas em sequencia
    char *pNome = pPessoa + 0;

    // se o nome for igual ao da minha busca
    if ( strcmp(pNome, pBusca) == 0){
      // ponteiro pra pessoa que achou
      char *pAchou  = pBuffer + OFF_PESSOAS + (TAM_PESSOA * (*pI));

      // ponteiro pra última pessoa
      char *pUltima = pBuffer + OFF_PESSOAS + (TAM_PESSOA * (*pQuantidade - 1));

      // copia a última pra o lugar da removida
      memcpy(pAchou, pUltima, TAM_PESSOA);

      // decrementa o contador  
      *pQuantidade -= 1;

      printf("pessoa removida com sucesso\n");

      return;
    }

    *pI += 1;

  }
}

void buscarP( char *pBuffer ){
  
  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);

  int *pI = ( int * )(pBuffer + OFF_OPCAO);
  *pI = 0;

  //ponteiro pra busca
  char *pBusca = pBuffer + OFF_BUSCA;

  printf("escreva o nome para buscar: ");
    scanf("%s", pBusca);

  while ( *pI < *pQuantidade ){
    char *pPessoa = pBuffer + OFF_PESSOAS + (TAM_PESSOA * (*pI)); //uso o indice pra ir acessando as pessoas em sequencia
    char *pNome = pPessoa + 0;

    if ( strcmp(pNome, pBusca) == 0){
    int *pIdade = ( int * )( pPessoa + TAM_NOME );
    char *pEmail = pPessoa + TAM_IDADE + TAM_NOME;

    printf("Nome: %s\n",  pNome);
    printf("Idade: %d\n", *pIdade);
    printf("Email: %s\n", pEmail);
    }
    
    *pI += 1;

  }

}

int main(){

  char *pBuffer = ( char * ) malloc (TAM_BUFFER); //aloco pra dez pessoas + a opcao do switch

  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);//inicio o contador antes de qlqr op
  *pQuantidade = 0;

  int *pOpcao = ( int *)(pBuffer + OFF_OPCAO);

  while (*pOpcao != 5){
    printf("1: adicionar\n");
    printf("2: remover\n");
    printf("3: buscar\n");
    printf("4: listar todos\n");
    printf("5: sair\n");
      scanf("%d", pOpcao);

    switch (*pOpcao){
      case 1: adicionarP(pBuffer); break;
      case 2: removerP(pBuffer); break;
      case 3: buscarP(pBuffer); break;
      case 4: listarP(pBuffer); break;
      case 5: break;
      default: printf("opcao invalida\n");
    }
  }

  free(pBuffer);

  return 0;
}