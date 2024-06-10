/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }

    int **matrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * n);
    }

    int length = n - 1, x = 0, y = 0, counter = 1;    
    while (length > 0) {
        for (int i = 0; i < length; i++, x++) {
            matrix[y][x] = counter;
            counter++;
        }

        for (int i = 0; i < length; i++, y++) {
            matrix[y][x] = counter;
            counter++;
        }

        for (int i = 0; i < length; i++, x--) {
            matrix[y][x] = counter;
            counter++;
        }
        
        for (int i = 0; i < length; i++, y--) {
            matrix[y][x] = counter;
            counter++;
        }
        
        x++;
        y++;
        length -= 2;
    }
    
    if (n % 2 == 1) {
        int mid = n / 2;
        matrix[mid][mid] = n * n;
    }
    
    return matrix;
}