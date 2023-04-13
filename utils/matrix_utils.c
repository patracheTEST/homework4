#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

void setMatrix(matrix *matrix) {
    giveMatrixSpace(matrix);
    for (int i = 0; i < matrix->column; i++)
    {
        for (int j = 0; j < matrix->row; j++)
        {
            matrix->matrixValue[i][j] = i+j*j;
        }
    }
}

void giveMatrixSpace(matrix *matrix) {
    matrix->matrixValue = (int**)malloc(sizeof(int*)*matrix->column);
    for (int i = 0; i < matrix->column; i++)
    {
        *(matrix->matrixValue+i) = (int*)malloc(sizeof(int)*matrix->row);
    }
}

void free_matrix(matrix *matrix) {
    free(matrix->matrixValue);
    printf("matrix free executed\n");
}

void print_matrix(matrix matrix) {
    printf("matrix value\n");
    for (int i = 0; i < matrix.column; i++)
    {
        for (int j = 0; j < matrix.row; j++)
        {
            printf("%d ", matrix.matrixValue[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}