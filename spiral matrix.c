int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {

    int* spiral = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    int size = 0;
    int top = 0;
    int right = matrixColSize[0] - 1;
    int bottom = matrixSize - 1;
    int left = 0;

    while(top <= bottom && left <= right)
    {
        for(int i = left; i <= right; i++)
        {
            spiral[size] = matrix[top][i];
            size++;
        }
        top++;

        for(int i = top; i <= bottom; i++)
        {
            spiral[size] = matrix[i][right];
            size++;
        }
        right--;

        if(top <= bottom && left <= right)
        {
            for(int i = right; i >= left; i--)
            {
                spiral[size] = matrix[bottom][i];
                size++;
            }
            bottom--;

            for(int i = bottom; i >= top; i--)
            {
                spiral[size] = matrix[i][left];
                size++;
            }
            left++;
        }
    }

    *returnSize = size;
    return spiral;
}
