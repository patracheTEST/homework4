#include <stdio.h>
#include <stdlib.h>
#include "calc/matrix_calc.h"

void test();

int main() {
    printf("[----- [김상수] [2018038078] -----]\n");
    test();
}

void test() {
    // 첫번째 매트릭스 선언 및 값 할당
    matrix matrixA;
    printf("matrixA col: ");
    scanf("%d", &(matrixA.column));
    printf("matrixA row: ");
    scanf("%d", &(matrixA.row));
    setMatrix(&matrixA);

    // 두번째 매트릭스 선언 및 값 할당
    matrix matrixB;
    printf("matrixB col: ");
    scanf("%d", &(matrixB.column));
    printf("matrixB row: ");
    scanf("%d", &(matrixB.row));
    setMatrix(&matrixB);
    
    // 받은 행렬 출력
    print_matrix(matrixA);
    print_matrix(matrixB);
    // 행렬 연산
    addition_matrix(matrixA, matrixB);
    subtraction_matrix(matrixA, matrixB);
    transpose_matrix(matrixA);
    multiply_matrix(matrixA, matrixB);
    // 행렬 할당 해제
    free_matrix(&matrixA);
    free_matrix(&matrixB);
}