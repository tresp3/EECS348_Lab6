#include "matrix.h"
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char*argv[])
{
    vector<vector<int>> matrix1, matrix2;
    read_matrix_file(matrix1, matrix2, "matrix1.txt");

    printf("Matrix 1: \n");
    printMatrix(matrix1);
    printf("\n");

    printf("Matrix 2: \n");
    printMatrix(matrix2);
    printf("\n");
    
    addMatrices(matrix1, matrix2);
    printf("\n");

    multiplyMatrices(matrix1, matrix2);
    printf("\n");

    subtractMatrices(matrix1, matrix2);
    printf("\n");

    updateElement(matrix1, 3,1,1);
    printf("\n");

    getMaxValue(matrix1);
    printf("\n");

    transposeMatrix(matrix1);
    printf("\n");


    return 0;
}