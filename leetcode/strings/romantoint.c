#include <stdio.h>
#include <string.h>

int traduzir(char c){ //switch case pra traduzir
  switch(c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0; //quando receber o final da string '\0' retorna 0
  }
}

int romanToInt(char* s) {
  int soma = 0;
  //laço q percorre ate achar o fim da string
  for ( int i = 0; s[i] != '\0'; i++ ){
    int atual = traduzir( s[i] );
    int proximo = traduzir( s[i+1] );
  //na ultima letra, s+1 sera o \0 q vai ser 0

  if ( atual < proximo ){
    //se o numero menor vem antes do maior,
    //se subtrai do total

    soma = soma - atual;
  } else {
    //normal

    soma = soma + atual;
  }

  }

  return soma;
    
}