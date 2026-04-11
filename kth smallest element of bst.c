/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 void inorder(struct TreeNode* root, int k, int* size, int* val)
 {
    if(root == NULL)
    return;

    inorder(root->left, k, size, val);
    if(*size == k)
    *val = root->val;
    (*size)++;
    inorder(root->right, k, size, val);
 }
int kthSmallest(struct TreeNode* root, int k) {

if(root == NULL)
return 0;

int val;
int size = 1;

inorder(root, k, &size, &val);

return val;
    
    
}
