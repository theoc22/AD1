/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
  //se os dois sao menores q a raiz, o lca ta na subarvore esquerda
  if (p->val < root->val && q->val < root->val){
    return lowestCommonAncestor(root->left, p, q);
  }

  //se os dois sao maiores, ta na subarvore direita
  if (p->val > root->val && q->val > root->val){
    return lowestCommonAncestor(root->right, p, q);
  }

  //se um é menor e o outro é maior (ou algum é a raiz), achei o lca
  return root;
}
