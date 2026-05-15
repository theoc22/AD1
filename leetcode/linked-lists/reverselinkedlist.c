/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    //crio um ponteiro temporario pra armazenar o proximo valor
    struct ListNode *variavel;
    //segundo ponteiro pra armazenar o valor antigo
    struct ListNode *prev = NULL;
    while ( head != NULL ){
      variavel = head->next; //salvo o proximo numero
      head->next = prev; //redireciono o head->next pro antigo

      prev = head; //avanco o prev
      head = variavel; //avanco o head
    }

    return prev; //prev vai virar o ultimo elemento. q aponta pro penultimo ettc
    //assim, invertendo a lista
}