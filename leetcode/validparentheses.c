#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
//defino o tamanho maximo da pilha

int tamanho = strlen(s);
char pilha[tamanho];

int topo = -1; // começa em -1 pq o 0 ja aponta pra primeira
//-1 esta vazio

//percorre a toda a string
for ( int i = 0; i < tamanho; i++ ) {
    char atual = s[i];

    if ( atual == '(' || atual == '[' || atual == '{' ){
      topo++; //sobe a pilha
      pilha[topo] = atual; //guarda
    }

    else if ( atual == ')' || atual == ']' || atual == '}'){
      //se tem um fechamento mas a pilha ta vazia, deu erro.
      if ( topo == -1 ){
        return false;
      }

      char topoAtual = pilha[topo];

      if ((atual == ')' && topoAtual == '(') || (atual == ']' && topoAtual == '[') || (atual == '}' && topoAtual == '{')) {
          //ta certo. remove da pilha
          topo--;
    } else{
      return false;
    }
  }
}
  if ( topo == -1 ){
    return true;
  } else{
    return false;
  }

}