#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int column;
    int **matrixValue;
} matrix;

void test();
void setMatrix(matrix *matrix);
void giveMatrixSpace(matrix *matrix);
void free_matrix(matrix *matrix);
void print_matrix(matrix matrix);
void addition_matrix();
void subtraction_matrix();
void transpose_matrix();
void multiply_matrix();

int main() {
    printf("[----- [김상수] [2018038078] -----]\n");
    test();
}

void test() {
    matrix matrixA = {2, 2};
    matrix matrixB = {3, 3};

    setMatrix(&matrixA);
    setMatrix(&matrixB);
    print_matrix(matrixA);
    print_matrix(matrixB);
    free_matrix(&matrixA);
    free_matrix(&matrixB);

}

void setMatrix(matrix *matrix) {
    giveMatrixSpace(matrix);
    for (int i = 0; i < matrix->column; i++)
    {
        for (int j = 0; j < matrix->row; j++)
        {
            matrix->matrixValue[i][j] = i+j;
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

void addition_matrix() {

}

void subtraction_matrix() {

}

void transpose_matrix() {

}

void multiply_matrix() {

}