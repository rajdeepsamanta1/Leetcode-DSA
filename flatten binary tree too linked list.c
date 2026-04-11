/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {

    if(root == NULL)
    return;

    flatten(root->left);
    flatten(root->right);

    if(root->left!=NULL)
    {

    struct TreeNode* node0 = root->right;

    root->right = root->left;

    root->left = NULL;

    struct TreeNode* curr = root->right;

    while(curr!=NULL && curr->right!=NULL)
    {
        curr = curr->right;
    }

    curr->right = node0;
  //  curr->left = NULL;
    
    }
    
}
