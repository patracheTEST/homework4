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

void transpose_matrix(matrix oldMatrix) {
    
    matrix transposedMatrix = {
        .column = oldMatrix.row,
        .row = oldMatrix.column
    };
    
    giveMatrixSpace(&transposedMatrix);

    for (int i = 0; i < oldMatrix.column; i++) {
        for (int j = 0; j < oldMatrix.row; j++) {
            transposedMatrix.matrixValue[j][i] = oldMatrix.matrixValue[i][j];
        }
    }
    printf("transpose complete, ");
    print_matrix(transposedMatrix);
    free_matrix(&transposedMatrix);
}

void multiply_matrix(matrix matrixA, matrix matrixB) {
    if (matrixA.row != matrixB.column) {
        printf("multiply failed : matrix size does not matches\n");
        return;
    }
    matrix multipliedMatrix = {
        .column = matrixA.column,
        .row = matrixB.row,
    };
    giveMatrixSpace(&multipliedMatrix);

    for (int i = 0; i < multipliedMatrix.column; i++) {
        for (int j = 0; j < multipliedMatrix.row; j++) {
            multipliedMatrix.matrixValue[i][j] = 0;
            for (int k = 0; k < matrixA.row; k++) {
                multipliedMatrix.matrixValue[i][j] += matrixA.matrixValue[i][k] * matrixB.matrixValue[k][j];
            }
        }
    }

    printf("multiply complete, ");
    print_matrix(multipliedMatrix);
    free_matrix(&multipliedMatrix);
}

int compareMatrixSize(matrix matrixA, matrix matrixB) {
    if (matrixA.column == matrixB.column && matrixA.row == matrixB.column)
    {
        return 1;
    }
    else return 0;
}