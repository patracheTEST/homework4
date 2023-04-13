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

    // 받은 배열과 같은 크기를 부여 해주고
    matrix tempMatrix = {
        .column = matrixA.column,
        .row = matrixA.row
    };

    // 그 만큼 메모리에 할당 해준다.
    giveMatrixSpace(&tempMatrix);

    // 그리고 두 행렬의 더한 값을 넣고
    for (int i = 0; i < tempMatrix.column; i++)
    {
        for (int j = 0; j < tempMatrix.row; j++)
        {
            tempMatrix.matrixValue[i][j] = matrixA.matrixValue[i][j] + matrixB.matrixValue[i][j];
        }
    }

    // 출력 해준 다음
    printf("addition complete, ");
    print_matrix(tempMatrix);
    // 할당을 해제해준다.
    free_matrix(&tempMatrix);
    return;
}

void subtraction_matrix(matrix matrixA, matrix matrixB) {
    // 더하기와 같으나 연산이 빼기이다.
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
    // 크기를 반대로 설정 해준 후
    matrix transposedMatrix = {
        .column = oldMatrix.row,
        .row = oldMatrix.column
    };
    
    // 그만큼 메모리에 크기를 부여하고
    giveMatrixSpace(&transposedMatrix);

    // 값을 반대로 넣어준다.
    for (int i = 0; i < oldMatrix.column; i++) {
        for (int j = 0; j < oldMatrix.row; j++) {
            transposedMatrix.matrixValue[j][i] = oldMatrix.matrixValue[i][j];
        }
    }

    // 이후 동일
    printf("transpose complete, ");
    print_matrix(transposedMatrix);
    free_matrix(&transposedMatrix);
}

void multiply_matrix(matrix matrixA, matrix matrixB) {
    // 곱셈이 안되는 크기면은 함수를 끝내고
    if (matrixA.row != matrixB.column) {
        printf("multiply failed : matrix size does not matches\n");
        return;
    }
    // 첫번째 행렬의 col, 두번째 행렬의 row 크기를 가져온다.
    matrix multipliedMatrix = {
        .column = matrixA.column,
        .row = matrixB.row,
    };
    giveMatrixSpace(&multipliedMatrix);

    // 곱한 값을 넣어준다.
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
    // 두 행렬의 크기가 같지 않으면 0을 같으면 1을 반환하게 설정, 덧셈, 뺄셈에 쓰일 예정
    if (matrixA.column == matrixB.column && matrixA.row == matrixB.column)
    {
        return 1;
    }
    else return 0;
}