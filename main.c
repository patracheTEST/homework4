#include <stdio.h>
#include <stdlib.h>
#include "calc/matrix_calc.h"

void test();

int main() {
    printf("[----- [김상수] [2018038078] -----]\n");
    test();
}

void test() {
    matrix matrixA = {3, 3};
    matrix matrixB = {3, 3};

    setMatrix(&matrixA);
    setMatrix(&matrixB);
    print_matrix(matrixA);
    print_matrix(matrixB);
    addition_matrix(matrixA, matrixB);
    subtraction_matrix(matrixA, matrixB);
    free_matrix(&matrixA);
    free_matrix(&matrixB);
}