/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 int diametertree(struct TreeNode* root, int* sum)
 {
    if(root == NULL)
    return 0;

    int left = diametertree(root->left, sum);
    int right = diametertree(root->right, sum);
    
    if(left + right > *sum)
    *sum = left + right;

    return 1+(left>right ? left : right);
 }
int diameterOfBinaryTree(struct TreeNode* root) {

    int sum = 0;

    if(root == NULL)
    return 0;

    int diameter = diametertree(root, &sum);

    return sum;
    
}
