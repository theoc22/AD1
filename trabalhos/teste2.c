#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

  char *pBuffer = ( char * ) malloc(54); // 4 + 50

  int *pIdade = ( int * )( pBuffer + 0 ); //comeco no byte 0
  char *pNome = ( char * )( pBuffer + 4 ); //comeco no byte 4

  *pIdade = 25;

  strcpy(pNome, "Theo"); //nome

  printf("Idade: %d\n", *pIdade);
  printf("Nome: %s\n", pNome);

  free(pBuffer);

  return 0;

}