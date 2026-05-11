#include <stdio.h>
#include <stdlib.h>

int main(){

  char *pBuffer = ( char * ) malloc(4); //reservo a memoria pro buffer, de 4 bytes. mais 
  //conveniente ser um char

  int *pIdade = ( int * ) pBuffer; //casting do pBuffer

  *pIdade = 25; // coloco 25

  printf("Idade: %d\n", *pIdade);

  free(pBuffer); // dou free

  return 0;
}