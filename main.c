#include <stdio.h>
#include <stdlib.h>
#include "calc/matrix_calc.h"

void test();

int main() {
    printf("[----- [김상수] [2018038078] -----]\n");
    test();
}

void test() {
    matrix matrixA;
    printf("matrixA col: ");
    scanf("%d", &(matrixA.column));
    printf("matrixA row: ");
    scanf("%d", &(matrixA.row));
    setMatrix(&matrixA);

    matrix matrixB;
    printf("matrixB col: ");
    scanf("%d", &(matrixB.column));
    printf("matrixB row: ");
    scanf("%d", &(matrixB.row));
    setMatrix(&matrixB);
    
    print_matrix(matrixA);
    print_matrix(matrixB);
    addition_matrix(matrixA, matrixB);
    subtraction_matrix(matrixA, matrixB);
    transpose_matrix(matrixA);
    multiply_matrix(matrixA, matrixB);
    free_matrix(&matrixA);
    free_matrix(&matrixB);
}