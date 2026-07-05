/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>

//funcao auxiliar q constroi a arvore recursivamente
struct TreeNode* construir(int* nums, int inicio, int fim){
  if (inicio > fim) return NULL;

  //pego o meio pra virar raiz. isso garante q a arvore fica balanceada (avl)
  int meio = (inicio + fim) / 2;

  struct TreeNode* raiz = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  raiz->val = nums[meio];

  //metade da esquerda vira subarvore esquerda
  raiz->left = construir(nums, inicio, meio - 1);
  //metade da direita vira subarvore direita
  raiz->right = construir(nums, meio + 1, fim);

  return raiz;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
  //chama a auxiliar com o array inteiro
  return construir(nums, 0, numsSize - 1);
}
