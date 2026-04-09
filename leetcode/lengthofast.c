#include <string.h>

int lengthOfLastWord(char* s) {
    int length = 0; //armazenar a qnt do ultimo
    int tamanho = strlen(s);
    int i = tamanho - 1; //antes do '0'
  
  while ( i >= 0 && s[i] == ' ' ) i--; //coloco o i em cima da ultima letra da ultima palavra

  while ( i >= 0 && s[i] != ' ' ) {
    length++; //aumento a length da string
    i--; //vou pra proxima letra ate ser zero ou um espaco
  }

  
    return length;
}