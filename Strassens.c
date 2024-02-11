#include <stdio.h>
#include <stdlib.h>

// Function to print the matrix
void print(int n, int **result)
{
    printf("The result is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d \t", result[i][j]);
        }
        printf("\n");
    }
}

// Function to allocate memory for the matrix
int **allocate_matrix(int n)
{
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    return matrix;
}

// Function to free the memory allocated for the matrix
void free_matrix(int n, int **matrix)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to add two matrices
int **matadd(int n, int **matrix1, int **matrix2)
{
    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
int **matsub(int n, int **matrix1, int **matrix2)
{
    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply two 2x2 matrices using the standard method
int **matmul(int n, int **matrix1, int **matrix2, int **result)
{
    int a = matrix1[0][0];
    int b = matrix1[0][1];
    int c = matrix1[1][0];
    int d = matrix1[1][1];

    int e = matrix2[0][0];
    int f = matrix2[0][1];
    int g = matrix2[1][0];
    int h = matrix2[1][1];

    result[0][0] = a * e + b * g;
    result[0][1] = a * f + b * h;
    result[1][0] = c * e + d * g;
    result[1][1] = c * f + d * h;
    return result;
}

// Function to multiply two matrices using Strassen's algorithm
int **strassen(int n, int **matrix1, int **matrix2)
{
    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(n * sizeof(int));
    }
    if (n == 2)
    {
        matmul(n, matrix1, matrix2, result);
        return result;
    }
    else
    {
        int **matA = allocate_matrix(n / 2);
        int **matB = allocate_matrix(n / 2);
        int **matC = allocate_matrix(n / 2);
        int **matD = allocate_matrix(n / 2);
        int **matE = allocate_matrix(n / 2);
        int **matF = allocate_matrix(n / 2);
        int **matG = allocate_matrix(n / 2);
        int **matH = allocate_matrix(n / 2);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < n / 2 && j < n / 2)
                {
                    matA[i][j] = matrix1[i][j];
                    matE[i][j] = matrix2[i][j];
                }
                else if (i < n / 2 && j >= n / 2)
                {
                    matB[i][j - n / 2] = matrix1[i][j];
                    matF[i][j - n / 2] = matrix2[i][j];
                }
                else if (i >= n / 2 && j < n / 2)
                {
                    matC[i - n / 2][j] = matrix1[i][j];
                    matG[i - n / 2][j] = matrix2[i][j];
                }
                else
                {
                    matD[i - n / 2][j - n / 2] = matrix1[i][j];
                    matH[i - n / 2][j - n / 2] = matrix2[i][j];
                }
            }
        }
        int **p1 = strassen(n / 2, matA, matsub(n / 2, matF, matH));
        int **p2 = strassen(n / 2, matadd(n / 2, matA, matB), matH);
        int **p3 = strassen(n / 2, matadd(n / 2, matC, matD), matE);
        int **p4 = strassen(n / 2, matD, matsub(n / 2, matG, matE));
        int **p5 = strassen(n / 2, matadd(n / 2, matA, matD), matadd(n / 2, matE, matH));
        int **p6 = strassen(n / 2, matsub(n / 2, matB, matD), matadd(n / 2, matG, matH));
        int **p7 = strassen(n / 2, matsub(n / 2, matA, matC), matadd(n / 2, matE, matF));

        int **c11 = matadd(n / 2, matsub(n / 2, matadd(n / 2, p5, p4), p2), p6);
        int **c12 = matadd(n / 2, p1, p2);
        int **c21 = matadd(n / 2, p3, p4);
        int **c22 = matsub(n / 2, matsub(n / 2, matadd(n / 2, p1, p5), p3), p7);

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                result[i][j] = c11[i][j];
                result[i][j + n / 2] = c12[i][j];
                result[i + n / 2][j] = c21[i][j];
                result[i + n / 2][j + n / 2] = c22[i][j];
            }
        }

        free_matrix(n / 2, matA);
        free_matrix(n / 2, matB);
        free_matrix(n / 2, matC);
        free_matrix(n / 2, matD);
        free_matrix(n / 2, matE);
        free_matrix(n / 2, matF);
        free_matrix(n / 2, matG);
        free_matrix(n / 2, matH);
        free_matrix(n / 2, p1);
        free_matrix(n / 2, p2);
        free_matrix(n / 2, p3);
        free_matrix(n / 2, p4);
        free_matrix(n / 2, p5);
        free_matrix(n / 2, p6);
        free_matrix(n / 2, p7);

        return result;
    }
}

// Main function
int main()
{
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    int **matrix1 = allocate_matrix(n);
    int **matrix2 = allocate_matrix(n);
    printf("Enter the elements of the first matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    print(n, matrix1);
    printf("Enter the elements of the second matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    print(n, matrix2);
    int **result = strassen(n, matrix1, matrix2);
    print(n, result);
    free_matrix(n, matrix1);
    free_matrix(n, matrix2);
    free_matrix(n, result);
    getchar();
    return 0;
}