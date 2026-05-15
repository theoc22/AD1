/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
  if (!root) return 0;

  int esquerda = maxDepth(root->left);
  int direita = maxDepth(root->right);  
  
  if (esquerda > direita){
    return esquerda + 1;
  } else return direita + 1;

}