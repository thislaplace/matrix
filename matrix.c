#include <stdio.h>
#include <stdlib.h>
#include"./matrix.h"

void DisplayMatrix(IN const Matrix_s *pstMatrix)
{
    int i = 0;
    int j = 0;
    printf("The matrix is:\r\n");
    for(i = 0;i < pstMatrix->ucRow;i++)
    {
        for(j = 0;j < pstMatrix->ucCol;j++)
        {
            printf(" %8.2f",(pstMatrix->pfDataAdd)[i][j]);
        }
        printf("\r\n");		
    }
}

Matrix_s *CreatMatrix(IN unsigned int ucRow, 
        IN unsigned int ucCol, 
        IN float *pvData)
{
    int i = 0;
    int j = 0;
    Matrix_s *pstMatrix = (Matrix_s*)malloc(sizeof(Matrix_s));
    if (pvData == NULL || pstMatrix == NULL)
    {
        printf("Creat matrix fault.\r\n");
        return NULL;
    }

    memset(pstMatrix, 0, sizeof(Matrix_s));
    pstMatrix->ucRow = ucRow;
    pstMatrix->ucCol = ucCol;
    pstMatrix->pfDataAdd = (float**)malloc((sizeof(float*) * ucRow));

    printf("malloc OK\n");

    if(pstMatrix->pfDataAdd == NULL)
    {
        printf("Malloc fault.\r\n");
        return NULL;
    }
    else
    {
        for(i = 0;i < pstMatrix->ucRow;i++)
        {
            (pstMatrix->pfDataAdd)[i] = (float*)malloc((sizeof(float) * ucCol));
            for(j = 0;j < pstMatrix->ucCol;j++)
            {
                (pstMatrix->pfDataAdd)[i][j] = pvData[i*ucCol + j];
            }				
        }	
    }

    return pstMatrix;
}

BOOL DestoryMatrix(IN Matrix_s *pstMatrix)
{
    int tmp = pstMatrix->ucRow;
    while( tmp > 0 )
    {
        if ((pstMatrix->pfDataAdd)[tmp-1] != NULL)
        {
            free((pstMatrix->pfDataAdd)[tmp-1]);
            (pstMatrix->pfDataAdd)[tmp-1] = NULL;
        }
        tmp--;
    }

    free(pstMatrix->pfDataAdd);

    if(pstMatrix != NULL)
    {
        free(pstMatrix);
        pstMatrix = NULL;
    }
}

unsigned int GetMatrixRow(IN const Matrix_s *pstMatrix)
{
    return pstMatrix->ucRow;
}

unsigned int GetMatrixCol(IN const Matrix_s *pstMatrix)
{
    return pstMatrix->ucCol;
}

Matrix_s *AddMatrix(IN const Matrix_s *pstMatrixA,
        IN const Matrix_s *pstMatrixB)
{
    int i;
    int j;
    Matrix_s *pstMatrixResult = (Matrix_s*)malloc(sizeof(Matrix_s));

    if((pstMatrixA->ucRow != pstMatrixB->ucRow)||(pstMatrixA->ucCol != pstMatrixB->ucCol))
    {
        printf("相加的两个矩阵的行或列不满足矩阵相减条件！\r\n");
        return NULL;
    }

    pstMatrixResult->ucRow = pstMatrixA->ucRow;
    pstMatrixResult->ucCol = pstMatrixA->ucCol;

    pstMatrixResult->pfDataAdd = (float **)malloc(sizeof(float*)*(pstMatrixA->ucRow));

    for(i = 0;i < pstMatrixResult->ucRow;i++)
    {
        (pstMatrixResult->pfDataAdd)[i] = (float *)malloc(sizeof(float*)*(pstMatrixA->ucCol));
        for(j = 0;j < pstMatrixResult->ucCol;j++)
        {
            (pstMatrixResult->pfDataAdd)[i][j] = (pstMatrixA->pfDataAdd)[i][j] + (pstMatrixB->pfDataAdd)[i][j];
        } 			  
    }

    return pstMatrixResult;
}


Matrix_s *SubtractMatrix(IN const Matrix_s *pstMatrixA,
        IN const Matrix_s *pstMatrixB)
{
    int i;
    int j;
    Matrix_s *pstMatrixResult = (Matrix_s*)malloc(sizeof(Matrix_s));

    if((pstMatrixA->ucRow != pstMatrixB->ucRow)||(pstMatrixA->ucCol != pstMatrixB->ucCol))
    {
        printf("相减的两个矩阵的行或列不满足矩阵相减条件！\r\n");
        return NULL;
    }

    pstMatrixResult->ucRow = pstMatrixA->ucRow;
    pstMatrixResult->ucCol = pstMatrixA->ucCol;

    pstMatrixResult->pfDataAdd = (float **)malloc(sizeof(float*) * (pstMatrixA->ucRow));

    for(i = 0;i < pstMatrixResult->ucRow;i++)
    {
        (pstMatrixResult->pfDataAdd)[i] = (float *)malloc(sizeof(float)*(pstMatrixA->ucCol));
        for(j = 0;j < pstMatrixResult->ucCol;j++)
        {
            (pstMatrixResult->pfDataAdd)[i][j] = (pstMatrixA->pfDataAdd)[i][j] - (pstMatrixB->pfDataAdd)[i][j];
        } 			  
    }

    return pstMatrixResult;
}



