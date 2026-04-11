/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {

    if(root == NULL)
    return NULL;

    struct TreeNode* queue[100];

    int front=0;
    int rear=0;

    queue[rear++] = root;

    while(front<rear)
    {
        struct TreeNode* node = queue[front++];

        struct TreeNode* intermediate = node->left;
        node->left = node->right;
        node->right = intermediate;
        

        if(node->left!=NULL)
        queue[rear++] = node->left;

        if(node->right!=NULL)
        queue[rear++] = node->right;
    }

    return root;
    
}
