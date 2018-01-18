#include "matrix.h"

#define TEST_ROW (3)
#define TEST_COL (6)

int main(int argc, char *argv[])
{
    float TEST_data1[TEST_ROW][TEST_COL]={
                                    {300.0,100.1,150.2,400.3,150.4,100.5},
                                    {300.0,500.1,200.2,350.3,200.4,100.5},
                                    {100.0,100.1,100.2,100.3,100.4,100.5}};

    float TEST_data2[TEST_ROW][TEST_COL]={
                                    {200.0,100.1,150.2,400.3,150.4,100.5},
                                    {300.0,500.1,200.2,350.3,200.4,100.5},
                                    {100.0,100.1,100.2,100.3,100.4,100.5}};


    Matrix_s *pstMatrix_A = CreatMatrix(TEST_ROW, TEST_COL, &TEST_data1[0][0]);
    Matrix_s *pstMatrix_B = CreatMatrix(TEST_ROW, TEST_COL, &TEST_data2[0][0]);

    if(NULL == pstMatrix_A || NULL == pstMatrix_B)
    {
        return -1;
    }

    DisplayMatrix(pstMatrix_A);
    DisplayMatrix(pstMatrix_B);

    Matrix_s *pstMatrix_Result = AddMatrix(pstMatrix_A,pstMatrix_B);
    if (pstMatrix_Result == NULL)
    {
        printf("pstMatrix_Result fault!\n");
        return -1;
    }
    DisplayMatrix(pstMatrix_Result);

    DestoryMatrix(pstMatrix_A);
    DestoryMatrix(pstMatrix_B);
    DestoryMatrix(pstMatrix_Result);

    return 0;
}

