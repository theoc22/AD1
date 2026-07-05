/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>

//funcao pra pegar a altura de cada no (igual maxDepth)
int altura(struct TreeNode* root) {
  if (!root) return 0;

  int esquerda = altura(root->left);
  int direita = altura(root->right);

  if (esquerda > direita){
    return esquerda + 1;
  } else return direita + 1;
}

bool isBalanced(struct TreeNode* root) {
  if (!root) return true;

  int esquerda = altura(root->left);
  int direita = altura(root->right);

  //diferenca das alturas nao pode ser maior q 1 (propriedade avl)
  int diferenca = esquerda - direita;
  if (diferenca < 0) diferenca = -diferenca;

  if (diferenca > 1) return false;

  //verifica recursivamente pros filhos tbm
  return isBalanced(root->left) && isBalanced(root->right);
}
