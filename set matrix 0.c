void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {

    int row[matrixSize];
    int col[matrixColSize[0]];

    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < matrixColSize[0]; j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < matrixColSize[0]; j++)
        {
            if(row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
