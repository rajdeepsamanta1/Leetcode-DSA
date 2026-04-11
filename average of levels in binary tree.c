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
double* averageOfLevels(struct TreeNode* root, int* returnSize) {

    double sum = 0;
    double size = 0;

    int level = 0;

    double* average = (double*)malloc(sizeof(double)*(10000));

    struct TreeNode* queue[10000];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while(front < rear)
    {
        sum=0;
        size = rear - front;

        for(int i=0; i<size; i++)
        {
        struct TreeNode* node = queue[front++];

        sum = sum + node->val;
        
        if(node->left!=NULL)
        queue[rear++] = node->left;

        if(node->right!=NULL)
        queue[rear++] = node->right;
        }
        average[level++] = sum/size;
    }

    *returnSize = level;

    return average;
    
}
