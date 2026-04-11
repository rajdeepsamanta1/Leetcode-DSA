/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {

    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    

    struct TreeNode* queue[100];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int* result = (int*)malloc(sizeof(int)*100);
    *returnSize = 0;

    int size;

    int num = 0;

    while(front < rear)
    {
        size = rear - front;

        for(int i=0; i<size; i++)
        {
            struct TreeNode* node = queue[front++];
            if(i==size-1)
            result[num++] = node->val;

            if(node->left!=NULL)
            queue[rear++] = node->left;

            if(node->right!=NULL)
            queue[rear++] = node->right;
        }
    }

    *returnSize = num;

    return result;
    
}
