/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root == NULL)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*)*2000);
    *returnColumnSizes = (int*)malloc(sizeof(int)*2000);

    int level = 0;

    struct TreeNode* queue[2000];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while(front<rear)
    {
        int size = rear - front;

        result[level] = (int*)malloc(sizeof(int)*size);

        for(int i=0; i<size; i++)
        {
            struct TreeNode* node = queue[front++];

            if(level%2==0)
            {
            result[level][i] = node->val;
            }

            else
            {
                result[level][size-1-i] = node->val;
            }
            if(node->left!=NULL)
            queue[rear++]=node->left;
            if(node->right!=NULL)
            queue[rear++]=node->right;
            
        }

        (*returnColumnSizes)[level]=size;

        (level)++;
    }

    *returnSize = level;

    return result;
    
}
