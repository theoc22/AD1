#include <string.h>

//pensando em fazer um for q percorra as strings

char* longestCommonPrefix(char** strs, int strsSize) {
    //para **strs, eu uso dois colchetes para acessar o conteudo
    //strs[0] sendo a primeira palavra inteira
    //strs[0][0] sendo a primeira palavra da primeira letra
    if (strsSize == 0) return "";

    for (int i = 0; strs[0][i] != '\0'; i++){
      for (int j = 1; j < strsSize; j++){
        //se a primeira letra da primeira palavra for igual
        //a primeira letra da segunda palavra...
        if (strs[0][i] != strs[j][i]){
          //enqt for igual, ele n termina a string
          //quando achar a diferenca, ele corta a string
          strs[0][i] = '\0';
          //a primeira palavra (strs[0]), vira o longest
          //commom prefix. ai eu retorno ela.
          return strs[0];
        }
      }
    }
  return strs[0];
}