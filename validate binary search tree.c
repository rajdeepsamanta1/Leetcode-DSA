/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 bool isvalid(struct TreeNode* root, long min, long max)
 {

    if(root == NULL)
    return true;

    if(root->val <= min || root->val >= max)
    return false;

    return isvalid(root->left, min, root->val) && isvalid(root->right, root->val, max);
 }
bool isValidBST(struct TreeNode* root) {

    if(root == NULL)
    return true;

    long min = LONG_MIN;
    long max = LONG_MAX;

    return isvalid(root, min, max);
    
}
