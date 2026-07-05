/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val) {
  //se chegou no fim ou achou o valor, retorna
  if (!root || root->val == val) return root;

  //propriedade da bst: se o val é menor q a raiz, ta na esquerda
  if (val < root->val){
    return searchBST(root->left, val);
  } else {
    //se for maior, ta na direita
    return searchBST(root->right, val);
  }
}
