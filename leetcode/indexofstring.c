#include <string.h>

int strStr(char* haystack, char* needle) {

    for ( int i = 0; haystack[i] != '\0'; i++ ){
      int j;
      for ( j = 0; needle[j] != '\0'; j++){
          if ( haystack[i + j] != needle[j] ){
            break;
          } 
      }//se chegou no fim da needle sem interrupcao, retorna o i
      if ( needle[j] == '\0' ){
        return i;
      }
    }
    return -1;
}