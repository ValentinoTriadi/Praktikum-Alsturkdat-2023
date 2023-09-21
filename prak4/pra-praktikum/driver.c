#include <stdio.h>
#include "matrix.c"

int main(){
    Matrix m1,m2,m3,m4,m5;
    // createMatrix(4,4, &m3);
    // createMatrix(4,4, &m4);
    createMatrix(4,5, &m5);
    readMatrix(&m1, 4,5);
    // readMatrix(&m2, 4,4);
    // ELMT(m4,0,0) = 1;
    // ELMT(m4,0,3) = 1;
    // ELMT(m4,0,2) = 1;
    // ELMT(m4,0,1) = 1;
    // ELMT(m5,0,1) = 1;
    
    // printf("Matriks 1:\n");
    // displayMatrix(m1);
    // printf("\nMatriks 2:\n");
    // displayMatrix(m2);
    // printf("\nMatriks 3:\n");
    // displayMatrix(m3);
    // printf("\n");
    
    // printf("isMatrixIdxValid(4,5): %d\n", isMatrixIdxValid(4,5));
    // printf("isMatrixIdxValid(101,100): %d\n", isMatrixIdxValid(101,100));
    // printf("isMatrixIdxValid(-1,00): %d\n", isMatrixIdxValid(-1,00));
    
    // printf("getLastIdxRow(m1): %d\n", getLastIdxRow(m1));
    // printf("getLastIdxCol(m1): %d\n", getLastIdxCol(m1));
    // printf("getLastIdxRow(m2): %d\n", getLastIdxRow(m1));
    // printf("getLastIdxCol(m2): %d\n", getLastIdxCol(m1));
    // printf("getLastIdxRow(m3): %d\n", getLastIdxRow(m1));
    // printf("getLastIdxCol(m3): %d\n", getLastIdxCol(m1));
    
    // printf("isIdxEff(m1,5,4): %d\n", isIdxEff(m1,5,4));
    // printf("isIdxEff(m1,3,3): %d\n", isIdxEff(m1,3,3));
    // printf("isIdxEff(m1,3,4): %d\n", isIdxEff(m1,3,4));
    // printf("isIdxEff(m2,5,4): %d\n", isIdxEff(m2,5,4));
    // printf("isIdxEff(m2,3,3): %d\n", isIdxEff(m2,3,3));
    // printf("isIdxEff(m2,0,0): %d\n", isIdxEff(m2,0,0));
    // printf("isIdxEff(m2,-1,0): %d\n", isIdxEff(m2,-1,0));
    // printf("isIdxEff(m3,0,0): %d\n", isIdxEff(m3,0,0));
    
    // printf("getElmtDiagonal(m1,0): %d\n", getElmtDiagonal(m1,0));
    // printf("getElmtDiagonal(m1,1): %d\n", getElmtDiagonal(m1,1));
    // printf("getElmtDiagonal(m1,2): %d\n", getElmtDiagonal(m1,2));
    // printf("getElmtDiagonal(m1,3): %d\n", getElmtDiagonal(m1,3));
    // printf("getElmtDiagonal(m2,0): %d\n", getElmtDiagonal(m2,0));
    // printf("getElmtDiagonal(m2,1): %d\n", getElmtDiagonal(m2,1));
    // printf("getElmtDiagonal(m2,2): %d\n", getElmtDiagonal(m2,2));
    // printf("getElmtDiagonal(m2,3): %d\n", getElmtDiagonal(m2,3));
    
    // printf("copyMatrix(m2,*m3): \n");
    // copyMatrix(m2,&m3);
    // displayMatrix(m3);
    // printf("\ncopyMatrix(m1,*m3): \n");
    // copyMatrix(m1,&m3);
    // copyMatrix(m1,&m4);
    // copyMatrix(m1,&m5);
    // displayMatrix(m3);
    
    // printf("\naddMatrix(m1,m2): \n");
    // m3 = addMatrix(m1,m2);
    // displayMatrix(m3);
    // printf("\naddMatrix(m1,m2): \n");
    // m3 = addMatrix(m1,m2);
    // displayMatrix(m3);
    
    // printf("\nSubtractMatrix(m1,m2): \n");
    // m3 = subtractMatrix(m1,m2);
    // displayMatrix(m3);
    // printf("\nSubtractMatrix(m2,m1): \n");
    // m3 = subtractMatrix(m2,m1);
    // displayMatrix(m3);
    
    // printf("\nmultiplyMatrix(m1,m2): \n");
    // m3 = multiplyMatrix(m1,m2);
    // displayMatrix(m3);
    // printf("\nmultiplyMatrix(m2,m1): \n");
    // m3 = multiplyMatrix(m2,m1);
    // displayMatrix(m3);
    
    // printf("\nmultiplyMatrixWithMod(m1,m2, 5): \n");
    // m3 = multiplyMatrixWithMod(m1,m2, 5);
    // displayMatrix(m3);
    // printf("\nmultiplyMatrixWithMod(m2,m1, 5): \n");
    // m3 = multiplyMatrixWithMod(m2,m1, 5);
    // displayMatrix(m3);
    
    // printf("\nmultiplyByConst(m1, 5): \n");
    // m3 = multiplyByConst(m1, 5);
    // displayMatrix(m3);
    // printf("\nmultiplyByConst,m2, 5): \n");
    // m3 = multiplyByConst(m2, 5);
    // displayMatrix(m3);
    
    // printf("\npMultiplyByConst(&m1, 5): \n");
    // pMultiplyByConst(&m1, 5);
    // displayMatrix(m1);
    // printf("\npMultiplyByConst,&m2, 5): \n");
    // pMultiplyByConst(&m2, 5);
    // displayMatrix(m2);
    
    printf("\n");
    printf("Matrix m1: \n");
    displayMatrix(m1);
    printf("\n");
    // printf("Matrix m2: \n");
    // displayMatrix(m2);
    // printf("\n");
    // printf("Matrix m3: \n");
    // displayMatrix(m3);
    // printf("\n");
    // printf("Matrix m4: \n");
    // displayMatrix(m4);
    // printf("\n");
    // printf("Matrix m5: \n");
    // displayMatrix(m5);
    // printf("\n");
    
    // printf("\nisMatrixEqual(m4,m5): %d\n", isMatrixEqual(m4,m5));
    // printf("isMatrixEqual(m1,m2): %d\n", isMatrixEqual(m1,m2));
    
    // printf("isMatrixNotEqual(m4,m5): %d\n", isMatrixNotEqual(m4,m5));
    // printf("isMatrixNotEqual(m1,m2): %d\n", isMatrixNotEqual(m1,m2));
    
    // printf("isMatrixSizeEqual(m4,m5): %d\n", isMatrixSizeEqual(m4,m5));
    // printf("isMatrixSizeEqual(m1,m2): %d\n", isMatrixSizeEqual(m1,m2));
    
    // printf("countElmt(m1): %d\n", countElmt(m1));
    // printf("countElmt(m2): %d\n", countElmt(m2));
    // printf("countElmt(m3): %d\n", countElmt(m3));
    // printf("countElmt(m4): %d\n", countElmt(m4));
    // printf("countElmt(m5): %d\n", countElmt(m5));
    
    // printf("isSquare(m1): %d\n", isSquare(m1));
    // printf("isSquare(m2): %d\n", isSquare(m2));
    // printf("isSquare(m3): %d\n", isSquare(m3));
    // printf("isSquare(m4): %d\n", isSquare(m4));
    // printf("isSquare(m5): %d\n", isSquare(m5));
    
    // printf("isSymmetric(m1): %d\n", isSymmetric(m1));
    // printf("isSymmetric(m2): %d\n", isSymmetric(m2));
    // printf("isSymmetric(m3): %d\n", isSymmetric(m3));
    // printf("isSymmetric(m4): %d\n", isSymmetric(m4));
    // printf("isSymmetric(m5): %d\n", isSymmetric(m5));
    
    // readMatrix(&m4,4,4);
    // readMatrix(&m5,3,3);
    // printf("isIdentity(m1): %d\n", isIdentity(m1));
    // printf("isIdentity(m2): %d\n", isIdentity(m2));
    // printf("isIdentity(m3): %d\n", isIdentity(m3));
    // printf("isIdentity(m4): %d\n", isIdentity(m4));
    // printf("isIdentity(m5): %d\n", isIdentity(m5));

    // readMatrix(&m4,4,4);
    // readMatrix(&m5,3,3);
    
    // printf("isSparse(m1): %d\n", isSparse(m1));
    // printf("isSparse(m2): %d\n", isSparse(m2));
    // printf("isSparse(m3): %d\n", isSparse(m3));
    // printf("isSparse(m4): %d\n", isSparse(m4));
    // printf("isSparse(m5): %d\n", isSparse(m5));

    // m5 = negation(m1);
    // printf("\nNegation Matrix 1:\n");
    // displayMatrix(m5);
    // m5 = negation(m2);
    // printf("\nNegation Matrix 2:\n");
    // displayMatrix(m5);

    // pNegation(&m1);
    // printf("\nNegation Matrix 1:\n");
    // displayMatrix(m1);

    m5 = transpose(m1);
    printf("\nTranspose Matrix 1:\n");
    displayMatrix(m5);
    // m5 = transpose(m2);
    // printf("\nTranspose Matrix 2:\n");
    // displayMatrix(m5);

    pTranspose(&m5);
    printf("\nTranspose Matrix 5:\n");
    displayMatrix(m5);
    
    // printf("\nDeterminan(m1): %f", determinant(m1));
    // printf("\nDeterminan(m2): %d", determinant(m2));
    // printf("\nDeterminan(m3): %d", determinant(m3));


    return 0;
}
