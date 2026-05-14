#include <stdio.h>
#include <string.h>

typedef struct Pilha{
  char dados[100];
  int topo;
}Pilha;

typedef struct Fila {
  char dados[100];
  int inicio;
  int fim;
} Fila;

void push (Pilha *p, char c){
  p->topo++; //incremento o topo
  
  p->dados[p->topo] = c; //guardo o caracter na posicao do topo
}

char pop (Pilha *p){
  char temp = p->dados[p->topo]; //guardo numa variavel temporaria

  p->topo--; // dou o "pop"

  return temp; // retorno a variavel temporaria
}

void enqueue (Fila *f, char c){
  f->fim++;

  f->dados[f->fim] = c;
}

//removo do inicio
char dequeue (Fila *f){
  char temp = f->dados[f->inicio];

  f->inicio++;

  return temp;
}