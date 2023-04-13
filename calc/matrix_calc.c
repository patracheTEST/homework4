#include <stdio.h>
#include <stdlib.h>
#include "matrix_calc.h"
// #include "../model/matrix.h"
// #include "../utils/matrix_utils.h"

void addition_matrix(matrix matrixA, matrix matrixB) {
    if (compareMatrixSize(matrixA, matrixB) == 0) {
        printf("addition failed : matrix size different\n");
        return;
    }

    matrix tempMatrix = {
        .column = matrixA.column,
        .row = matrixA.row
    };

    giveMatrixSpace(&tempMatrix);

    for (int i = 0; i < tempMatrix.column; i++)
    {
        for (int j = 0; j < tempMatrix.row; j++)
        {
            tempMatrix.matrixValue[i][j] = matrixA.matrixValue[i][j] + matrixB.matrixValue[i][j];
        }
    }
    printf("addition complete, ");
    print_matrix(tempMatrix);
    free_matrix(&tempMatrix);
    return;
}

void subtraction_matrix(matrix matrixA, matrix matrixB) {
    if (compareMatrixSize(matrixA, matrixB) == 0) {
        printf("subtraction failed : matrix size different\n");
        return;
    }

    matrix tempMatrix = {
        .column = matrixA.column,
        .row = matrixA.row
    };

    giveMatrixSpace(&tempMatrix);

    for (int i = 0; i < tempMatrix.column; i++)
    {
        for (int j = 0; j < tempMatrix.row; j++)
        {
            tempMatrix.matrixValue[i][j] = matrixA.matrixValue[i][j] - matrixB.matrixValue[i][j];
        }
    }
    printf("subtraction complete, ");
    print_matrix(tempMatrix);
    free_matrix(&tempMatrix);
    return;
}

void transpose_matrix() {

}

void multiply_matrix() {

}

int compareMatrixSize(matrix matrixA, matrix matrixB) {
    if (matrixA.column == matrixB.column && matrixA.row == matrixB.column)
    {
        return 1;
    }
    else return 0;
}