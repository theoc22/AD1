#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFF_QUANTIDADE  0
#define OFF_TAMANHO     4
#define OFF_OPCAO       8
#define OFF_CONTADOR    12
#define OFF_RASC_NOME   16
#define OFF_RASC_EMAIL  66
#define OFF_PESSOAS     116


int verificaP( char *pBuffer, char *pNome ){

  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);

  int *pI = ( int * )(pBuffer + OFF_CONTADOR);
  *pI = 0;

  char *pCursor = pBuffer + OFF_PESSOAS;

  while ( *pI < *pQuantidade ){
    char *pNomeAtual = pCursor;
    pCursor += strlen(pCursor) + 1; //pulo nome
    pCursor += 4; //idade
    pCursor += strlen(pCursor) + 1; //email

  if ( strcmp(pNomeAtual, pNome) == 0){
    return 1;
  } 

  *pI += 1;
  }
  return 0;
}

//funcao pra adc pessoa
//nao pode ponteiro pra ponteiro, ent tenho q retornar o char e atualizar o buffer no main
char *adicionarP ( char *pBuffer ){

  char *pRascNome = pBuffer + OFF_RASC_NOME;
  char *pRascEmail = pBuffer + OFF_RASC_EMAIL;
  int *pTamanho = ( int * )(pBuffer + OFF_TAMANHO);
  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);

  printf("Nome: ");
    scanf("%s", pRascNome);

  if (verificaP(pBuffer, pRascNome) == 1){
    printf("pessoa ja adicionada na lista\n");

    return pBuffer;
  }

  printf("Email: ");
    scanf("%s", pRascEmail);

  //realloc com o novo tamanho
  // vou p \0 depois pulo a idade e depois vou p \0 do email
  pBuffer = (char *) realloc(pBuffer, *pTamanho + strlen(pRascNome) + 1 + 4 + strlen(pRascEmail) + 1);

  //recalculo os tamanhos depois do realloc
  pRascNome = pBuffer + OFF_RASC_NOME;
  pRascEmail = pBuffer + OFF_RASC_EMAIL;
  pTamanho = ( int * )(pBuffer + OFF_TAMANHO);
  pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);

  //pcursos aponta pro final do buffer, onde vai a proxima pessoa
  char *pCursor = pBuffer + *pTamanho;

  //copio o nome
  strcpy(pCursor, pRascNome);
  pCursor += strlen(pRascNome) + 1;

  //leio a idade
  //vou sempre somando o cursor, pra apontar o fim dessa pessoa
  int *pIdade = ( int * )pCursor;
  printf("Idade: ");
    scanf("%d", pIdade);
  pCursor += 4;

  //email
  strcpy(pCursor, pRascEmail);

  *pTamanho += strlen(pRascNome) + 1 + 4 + strlen(pRascEmail) + 1;
  *pQuantidade += 1;

    return pBuffer;
}


void listarP( char *pBuffer ){
  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);
  int *pI = ( int * )(pBuffer + OFF_CONTADOR); //reuso a memoria da opcao e uso como contador

  char *pCursor = pBuffer + OFF_PESSOAS; //deixo fora do while pra saber onde parou na pessoa

  *pI = 0;

  if (*pQuantidade == 0 ){
    printf("lista vazia\n");

    return;
  }

  //faco um while usando o indicie pI ate chegar no pQuantidade
  while ( *pI < *pQuantidade){

    //sempre somando o pcursor
    char *pNome = pCursor;
    pCursor += strlen(pCursor) + 1; //avanco o nome

    int *pIdade = ( int * ) pCursor;
    pCursor += 4; //avanco a idade

    char *pEmail = pCursor; //mesma coisa
    pCursor += strlen(pCursor) + 1;//avanco o email

    printf("\n");
    printf("Nome: %s\n",  pNome);
    printf("Idade: %d\n", *pIdade);
    printf("Email: %s\n", pEmail);

    *pI += 1;

  }
} 

char *removerP( char *pBuffer ){

  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);
  
  int *pI = ( int * )(pBuffer + OFF_CONTADOR);
  *pI = 0;

  char *pBusca = pBuffer + OFF_RASC_NOME;

  char *pCursor = pBuffer + OFF_PESSOAS;

  printf("escreva o nome para remover: ");
    scanf("%s", pBusca);

  //while pra percorrer a lista
  while ( *pI < *pQuantidade ){
    char *pNome = pCursor;
    pCursor += strlen(pCursor) + 1;

    int *pIdade = (int *) pCursor;
    pCursor += 4;

    char *pEmail = pCursor;
    pCursor += strlen(pCursor) + 1;

    // se o nome for igual ao da minha busca
    if ( strcmp(pNome, pBusca) == 0){
    char *pAchou = pNome; //guardo onde comeca a pessoa

    int  *pTamUlt = (int *)(pBuffer + OFF_TAMANHO); //ponteiro p tam atual

    char *pEmailAchou = pNome + strlen(pNome) + 1 + 4; // vou ate o email da pessoa

    int  *pTamRemovida = (int *)(pBuffer + OFF_CONTADOR);
    *pTamRemovida = strlen(pNome) + 1 + 4 + strlen(pEmailAchou) + 1; //guardo o tamanho da pessoa

    memmove(pAchou, pCursor, pBuffer + *pTamUlt - pCursor);//movo tudo, melhor q memcpy

    *pTamUlt -= *pTamRemovida;
    *pQuantidade -= 1;

    pBuffer = (char *) realloc(pBuffer, *pTamUlt);
    //atualizo os tamanhos
    printf("pessoa removida com sucesso\n");

    return pBuffer;
    }

    *pI += 1;

  }

  printf("pessoa nao encontrada\n");

  return pBuffer;

}

void buscarP( char *pBuffer ){
  
  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);

  int *pI = ( int * )(pBuffer + OFF_CONTADOR);
  *pI = 0;

  //ponteiro pra busca
  char *pBusca = pBuffer + OFF_RASC_NOME;

  char *pCursor = pBuffer + OFF_PESSOAS;

  printf("escreva o nome para buscar: ");
    scanf("%s", pBusca);

  while ( *pI < *pQuantidade ){
    char *pNome = pCursor;
    pCursor += strlen(pCursor) + 1;

    int *pIdade = ( int *) pCursor;
    pCursor += 4;

    char *pEmail = pCursor;
    pCursor += strlen(pCursor) + 1;

    if ( strcmp(pNome, pBusca) == 0){
    printf("Nome: %s\n",  pNome);
    printf("Idade: %d\n", *pIdade);
    printf("Email: %s\n", pEmail);

    return;

    }
    
    *pI += 1;

  }

  printf("pessoa nao encontrada!\n");

}

int main(){

  char *pBuffer = ( char * ) malloc (116); //uso malloc fixo, pra depois usar realloc

  int *pTamanho = ( int * )(pBuffer + OFF_TAMANHO);
  int *pQuantidade = ( int * )(pBuffer + OFF_QUANTIDADE);//inicio o contador antes de qlqr op
  *pQuantidade = 0;
  *pTamanho = 116;

  int *pOpcao = ( int * )(pBuffer + OFF_OPCAO);

  *pOpcao = 0;

  while (*pOpcao != 5){
    printf("1: adicionar\n");
    printf("2: remover\n");
    printf("3: buscar\n");
    printf("4: listar todos\n");
    printf("5: sair\n");
      scanf("%d", pOpcao);

      //atualizo o endereco dps do realloc
    switch (*pOpcao){
      case 1:
          pBuffer = adicionarP(pBuffer);
          pOpcao = (int * )(pBuffer + OFF_OPCAO); //recalculo
          break;
      case 2:
          pBuffer = removerP(pBuffer);
          pOpcao = (int * )(pBuffer + OFF_OPCAO); //recalculo
          break;
      case 3: buscarP(pBuffer); break;
      case 4: listarP(pBuffer); break;
      case 5: break;
      default: printf("opcao invalida\n");
    }
  }

  free(pBuffer);

  return 0;
}