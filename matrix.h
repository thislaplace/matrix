#ifndef _MATRIX_H
#define _MATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN 
#define OUT 

#define TRUE    (0)
#define FALSE   (1)

typedef int BOOL; 

typedef struct tagMatrix 
{  
	unsigned int ucRow;  //行
	unsigned int ucCol;  //列
	float **pfDataAdd; 
}Matrix_s;


Matrix_s *CreatMatrix(IN unsigned int ucRow, 
                 IN unsigned int ucCol, 
                 IN float *pvData);

BOOL DestoryMatrix(IN Matrix_s *pstMatrix);

unsigned int GetMatrixRow(const Matrix_s *pstMatrixA);

unsigned int GetMatrixCol(const Matrix_s *pstMatrixA);

Matrix_s *AddMatrix(IN const Matrix_s *pstMatrixA,
               IN const Matrix_s *pstMatrixB);

Matrix_s *SubtractMatrix(IN const Matrix_s *pstMatrixA,
                    IN const Matrix_s *pstMatrixB);

void DisplayMatrix(IN const Matrix_s *pstMatrix);
#endif

