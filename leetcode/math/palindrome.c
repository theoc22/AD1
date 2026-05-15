#include <stdbool.h>

bool isPalindrome(int x) {
  long reverse = 0;
  int original = x; // guarda o valor original para comparar

  if ( x < 0 ){
    return false;
  }

  while ( x != 0 ){ //laco pra reverter o numero
    reverse = reverse * 10 + x % 10; //pego o ultimo digito
    x /= 10; // corto o ultimo digito
    //faço isso ate o x ser 0. ou seja, ou numero for reverso
  }

  //comparo com o original. pois x agr é 0

  if ( reverse == original ){
    return true;
  } else {
    return false;
  }


}