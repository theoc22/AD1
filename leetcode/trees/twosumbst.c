/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>

//funcao aux pra procurar um valor na bst (nao pode ser o mesmo no)
bool procurar(struct TreeNode* root, int alvo, struct TreeNode* atual){
  if (!root) return false;

  //achei o valor mas nao pode ser o mesmo no q eu ja to usando
  if (root->val == alvo && root != atual) return true;

  //usa a propriedade da bst pra descer
  if (alvo < root->val){
    return procurar(root->left, alvo, atual);
  } else {
    return procurar(root->right, alvo, atual);
  }
}

//percorre a arvore e pra cada no procura o complemento (k - valor)
bool percorrer(struct TreeNode* root, struct TreeNode* raiz, int k){
  if (!root) return false;

  //k - valor atual é o q eu preciso achar em outro no
  int complemento = k - root->val;
  if (procurar(raiz, complemento, root)) return true;

  //tenta nos filhos
  return percorrer(root->left, raiz, k) || percorrer(root->right, raiz, k);
}

bool findTarget(struct TreeNode* root, int k) {
  //passo a raiz duas vezes pq preciso dela pra procurar sempre do topo
  return percorrer(root, root, k);
}
