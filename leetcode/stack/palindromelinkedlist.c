/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdbool.h>

bool isPalindrome(struct ListNode* head) {
  //variavel pra contar o n de elementos da lista p dar o malloc
  int n = 0;

  struct ListNode *atual = head;

  while (atual != NULL){
    //incremento o n primeiro
    n++;
    //avanco e salvo o valor do atual
    atual = atual->next;
  }

  //volto pro head, pq o atual tava no null
  atual = head;


  int *pilha = (int *)malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++){
    //acesso o valor do struct
    pilha[i] = atual->val;
    atual = atual->next;
  }

  for (int i = 0; i < n; i++){
    //acesso o primeiro item (ultimo da lista) da pilha e comparo
    //com o ultimo da pilha.
    if (pilha[i] != pilha[n - 1 - i]){
      free(pilha);

      return false;
    }
  }

  free(pilha);

  return true;

}