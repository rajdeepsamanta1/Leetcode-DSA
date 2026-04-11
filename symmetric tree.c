/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 bool issame(struct TreeNode* left, struct TreeNode* right)
 {

    if(left == NULL && right == NULL)
    return true;

    if((left == NULL && right!=NULL) || (left!=NULL && right == NULL))
    return false;

    if(left->val!=right->val)
    return false;


    return issame(left->left, right->right) && issame(left->right, right->left);
 }
bool isSymmetric(struct TreeNode* root) {

    if(root == NULL)
    return true;

    return issame(root->left, root->right);
    
}
