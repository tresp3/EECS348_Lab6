#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void read_matrix_file(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, string file)
{
    fstream input_stream(file);
    int matrix_size = 0;
    input_stream >> matrix_size;

    matrix1 = vector<vector<int>>(matrix_size, vector<int>(matrix_size));
    matrix2 = vector<vector<int>>(matrix_size, vector<int>(matrix_size));
    for(int i = 0, value = 0; i<matrix_size; i++)
    {
        for(int j = 0; j<matrix_size; j++)
        {
            input_stream >> value;
            matrix1[i][j] = value;
        }        
    }
    for(int i = 0, value = 0; i<matrix_size; i++)
    {
        for(int j = 0; j<matrix_size; j++)
        {
            input_stream >> value;
            matrix2[i][j] = value;
        }        
    }
        
    input_stream.close();
}

void printMatrix(vector<vector<int>> &matrix)
{
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix.front().size(); ++j) {
             printf("%d\t",matrix[i][j]);
        }
         printf("\n");
    }
   
}

void addMatrices(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2)
{
    if(matrix1.size() == matrix2.size() && matrix1.front().size() == matrix2.front().size()){
        vector<vector<int>> matrix3 = vector<vector<int>>(matrix1.size(), vector<int>(matrix1.front().size()));
        for(int i = 0; i < matrix1.size(); ++i) {
            for(int j = 0; j < matrix1.front().size(); ++j) {
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        printf("Result of adding 2 Matrices: ");
        printf("\n");
        printMatrix(matrix3); 
    } 
}

void multiplyMatrices(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2)
{
    if(matrix1.front().size() == matrix2.size()){
        vector<vector<int>> matrix3 = vector<vector<int>>(matrix1.size(), vector<int>(matrix1.front().size()));
        for(int i = 0; i< matrix1.size(); ++i) {
            for(int j = 0; j < matrix2.front().size(); ++j) {
                for(int k = 0; k < matrix2.size(); ++k) {
                    matrix3[i][j]+= matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        printf("Result of multiplying 2 Matrices: ");
        printf("\n");
        printMatrix(matrix3);
    }
}
    
void subtractMatrices(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2)
{
    if(matrix1.size() == matrix2.size() && matrix1.front().size() == matrix2.front().size()){
        vector<vector<int>> matrix3 = vector<vector<int>>(matrix1.size(), vector<int>(matrix1.front().size()));
        for(int i = 0; i < matrix1.size(); ++i) {
            for(int j = 0; j < matrix1.front().size(); ++j) {
                matrix3[i][j] = matrix2[i][j] - matrix1[i][j];
            }
        }
        printf("Result of subtracting 2 Matrices: ");
        printf("\n");
        printMatrix(matrix3); 
    } 
}

void updateElement(vector<vector<int>> &matrix, int val, int row, int col){
    if(row>= 0 && row<matrix.size()){
        if(col>= 0 && col<matrix.size()){
            matrix[row][col] = val;
            printf("Updated matrix: ");
            printf("\n");
            printMatrix(matrix);
        }
        else{
            printf("Invalid Column. ");
        printf("\n");
        }
    }
    else{
        printf("Invalid Row. ");
        printf("\n");
    }
}

void getMaxValue(vector<vector<int>> &matrix)
{
        int max = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix.front().size(); ++j) {
                if(max<matrix[i][j]){
                    max=matrix[i][j];
                }
            }
        }
        printf("Max of Matrix: %d", max);
        printf("\n");
} 

void transposeMatrix(vector<vector<int>> &matrix)
{
        vector<vector<int>> tmatrix = vector<vector<int>>(matrix.front().size(), vector<int>(matrix.size()));
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix.front().size(); ++j) {
                tmatrix[j][i] = matrix[i][j];
            }
        }
        matrix=tmatrix;
        printf("Transposed Matrix: ");
        printf("\n");
        printMatrix(matrix);
} 

#endif
