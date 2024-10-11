/*
Phoenix Brehm
EECS 348
Th 11AM
Lab05
Goal: To take in some inputs about the dimensions of a matrix, then fill out those matrices. Then add, multiply, and transpose, alongside printing those matrices
*/
#include <stdio.h>

void addMatrices(int r1, int c1, int r2, int c2, int m1[r1][c1], int m2[r2][c2]){
    if(r1 != r2 || c1 != c2){
        printf("Cannot Add Matrices of 2 Different Sizes");
    }
    else{
        for(int i = 0; i<r1;i++){
            for(int j = 0; j<c1;j++){
                if(j == c1-1){
                    printf("%d\n", m1[i][j]+m2[i][j]);
                }
                else{
                    printf("%d\t", m1[i][j]+m2[i][j]);
                }
            }
        }
    }
    
}

void printMatrix(int r, int c, int mat[r][c]){
    for(int i = 0; i<r;i++){
        for(int j = 0; j<c;j++){
            if(j == c-1){
                printf("%d\n", mat[i][j]);
            }
            else{
                printf("%d\t", mat[i][j]);
            }
        }
    }
}

void multiplyMatrices(int r1, int c1, int r2, int c2, int mA[r1][c1], int mB[r2][c2]){
    if(c1 != r2){
        printf("Cannot Multiply These Two Matrices In This Order");
    }
    else{
        int newMAB[r1][c2];
        int sum = 0;
        for(int i = 0; i<r1;i++){
            for(int j = 0; j<c2;j++){           //[0][0]*[0][0]+[0][1]*[1][0]     [0][0]*[0][1]+[0][1]*[1][1]
                for(int k = 0;k<r2;k++){        //[1][0]*[0][0]+[1][1]*[1][0]     [1][0]*[0][1]+[1][1]*[1][1]
                    sum += mA[i][k] * mB[k][j];
                }
                newMAB[i][j] = sum;
                sum = 0;
            }
        }
        printMatrix(r1, c2, newMAB);
    }
}

void transposeMatrices(int r, int c, int m[r][c]){
    int newM[c][r];
    for(int i = 0; i<r;i++){
        for(int j = 0; j<c;j++){
            newM[j][i] = m[i][j];
        }
    }
    printMatrix(c, r, newM);
}

int main(){
    int m1R, m1C, m2R, m2C;
    printf("Enter Row Count for M1: ");
    scanf("%d", &m1R);
    printf("Enter Column Count for M1: ");
    scanf("%d", &m1C);
    printf("Enter Row Count for M2: ");
    scanf("%d", &m2R);
    printf("Enter Column Count for M2: ");
    scanf("%d", &m2C);
    int m1[m1R][m1C]      /*{{1, 2, 3, 4, 5},
                            {6, 7, 8, 9, 10},
                            {11, 12, 13, 14, 15},
                            {16, 17, 18, 19, 20},
                            {21, 22, 23, 24, 25}};*/;

    int m2[m2R][m2C]      /*{{26, 27, 28, 29, 30},
                            {31, 32, 33, 34, 35},
                            {36, 37, 38, 39, 40},
                            {41, 42, 43, 44, 45},
                            {46, 47, 48, 49, 50}};*/;
    for(int i = 0; i<m1R;i++){
        for(int j=0; j<m1C;j++){
            printf("Enter %d Value for m1: ", m1C*i+j+1);
            scanf("%d", &m1[i][j]);
        }
    }
    for(int i = 0; i<m2R;i++){
        for(int j=0; j<m2C;j++){
            printf("Enter %d Value for m2: ", m2C*i+j+1);
            scanf("%d", &m2[i][j]);
        }
    }


    printf("Printing Matrix 1:\n");
    printMatrix(m1R, m1C, m1);
    printf("\nPrinting Matrix 2:\n");
    printMatrix(m2R, m2C, m2);
    printf("\nAdding Matrix 1 and 2:\n");
    addMatrices(m1R, m1C, m2R, m2C, m1, m2);
    printf("\nMultiplying Matrix 1 and 2\n");
    multiplyMatrices(m1R, m1C, m2R, m2C, m1, m2);
    printf("\nMultiplying Matrix 2 and 1\n");
    multiplyMatrices(m2R, m2C, m1R, m1C, m2, m1);
    printf("\nTransposing Matrix 1\n");
    transposeMatrices(m1R, m1C, m1);
    printf("\nTransposing Matrix 2\n");
    transposeMatrices(m2R, m2C, m2);


    printf("Program Complete: Press Enter to quit");
    getchar();//scanf buffer
    getchar();
}