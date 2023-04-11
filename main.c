#include <stdio.h>
#include <stdlib.h>
#include "model/matrix.h"
#include "utils/matrix_utils.h"

void test();

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