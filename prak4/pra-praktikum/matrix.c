#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m)= nCols;
    int i,j;
    for(i=0; i<nRows; i++){
        for(j=0; j<nCols; j++){
            ELMT(*m, i, j) = 0;
        }
    }
}
boolean isMatrixIdxValid(int i, int j){
    return (i<ROW_CAP && i>=0 && j>=0 && j<COL_CAP);
}
IdxType getLastIdxRow(Matrix m){
    return (ROW_EFF(m)-1);
}
IdxType getLastIdxCol(Matrix m){
    return (COL_EFF(m)-1);
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return (i<ROW_EFF(m) && i>=0 && j>=0 && j<COL_EFF(m));
}
ElType getElmtDiagonal(Matrix m, IdxType i){
    return (ELMT(m,i,i));
}
void copyMatrix(Matrix mIn, Matrix *mOut){
    createMatrix(ROW_EFF(mIn),COL_EFF(mIn),mOut);
    int i, j;
    for(i=0; i<ROW_EFF(mIn); i++){
        for(j=0; j<COL_EFF(mIn); j++){
            ELMT(*mOut, i, j) = ELMT(mIn, i, j); 
        }
    }
}
void readMatrix(Matrix *m, int nRow, int nCol){
    createMatrix(nRow,nCol,m);
    int i,j;
    for(i=0; i<nRow; i++){
        for(j=0; j<nCol; j++){
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}
void displayMatrix(Matrix m){
    int i,j;
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            printf("%d", ELMT(m,i,j));
            if (j<getLastIdxCol(m)) printf(" ");
        }
        // if (i!=ROW_EFF(m)-1) printf("\n");
        printf("\n");
    }
}
Matrix addMatrix(Matrix m1, Matrix m2){
    int i,j;
    for(i=0; i<ROW_EFF(m1); i++){
        for(j=0; j<COL_EFF(m1); j++){
            ELMT(m1, i, j) += ELMT(m2, i, j);
        }
    }
    return m1;
}
Matrix subtractMatrix(Matrix m1, Matrix m2){
    int i,j;
    for(i=0; i<ROW_EFF(m1); i++){
        for(j=0; j<COL_EFF(m1); j++){
            ELMT(m1, i, j) -= ELMT(m2, i, j);
        }
    }
    return m1;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);

    int i,j,k;
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            for(k=0; k<COL_EFF(m1); k++){
                ELMT(m, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return m;
}
Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod){
    Matrix m;
    createMatrix(ROW_EFF(m1),COL_EFF(m2), &m);;
    
    int i,j,k;
    for (i=0;i<ROW_EFF(m);i++){
        for (j=0;j<COL_EFF(m);j++){
            for (k=0;k<COL_EFF(m1);k++){
                ELMT(m,i,j) += ELMT(m1,i,k) * ELMT(m2,k,j);
            }
            ELMT(m,i,j) %= mod;
        }   
    }

    return m;
}
Matrix multiplyByConst(Matrix m, ElType x){
    int i,j;
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            ELMT(m, i, j) *= x;
        }
    }
    return m;
}
void pMultiplyByConst(Matrix *m, ElType k){
    int i,j;
    for(i=0; i<ROW_EFF(*m); i++){
        for(j=0; j<COL_EFF(*m); j++){
            ELMT(*m,i,j) *= k;
        }
    }
}
boolean isMatrixEqual(Matrix m1, Matrix m2){
    if (!isMatrixSizeEqual(m1,m2)) return false;
    int i,j;
    for(i=0; i<ROW_EFF(m1); i++){
        for(j=0; j<COL_EFF(m1); j++){
            if (ELMT(m1,i,j) != ELMT(m2,i,j)) return false;
        }
    }
    return true;
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return (!isMatrixEqual(m1,m2));
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}
int countElmt(Matrix m){
    return(ROW_EFF(m)*COL_EFF(m));
}
boolean isSquare(Matrix m){
    return(ROW_EFF(m) == COL_EFF(m));
}
boolean isSymmetric(Matrix m){
    if (!isSquare(m)) return false;
    int i,j;
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            if (ELMT(m,i,j) != ELMT(m,j,i)) return false;
        }
    }
    return true;
}
boolean isIdentity(Matrix m){
    if (!isSquare(m)) return false;
    int i,j;
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            if (i == j){
                if (ELMT(m,i,j) != 1) return false;
            } else {
                if (ELMT(m,i,j) != 0) return false;
            }
        }
    }
    return true;

}
boolean isSparse(Matrix m){
    if (!isSquare(m)) return false;
    int i,j, counter = 0;
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            if (ELMT(m,i,j) != 0) counter++;
        }
    }
    return (counter <= (0.05)*(float)countElmt(m));
}
Matrix negation(Matrix m){
    return multiplyByConst(m, -1);
}
void pNegation(Matrix *m){
    pMultiplyByConst(m, -1);
}
float determinant(Matrix m){
    if (ROW_EFF(m) == 0) return (float)(0);
    if (ROW_EFF(m) == 1) return (float)(ELMT(m,0,0));
    if (COL_EFF(m) == 2) return (float)((ELMT(m,0,0)*ELMT(m,1,1)) - (ELMT(m,0,1)*ELMT(m,1,0)));

    int i,j,k,l;
    float det=0;
    for (i=0; i<ROW_EFF(m); i++){
        Matrix mtemp;
        createMatrix(ROW_EFF(m)-1, COL_EFF(m)-1, &mtemp);
        for(j=0; j<ROW_EFF(mtemp); j++){
            int l = 0;
            for(k=0; k<COL_EFF(m); k++){
                if(k != i){
                    ELMT(mtemp,j,l) = ELMT(m,j+1,k);
                    l++;
                }
            }
        }

        det += (float)(ELMT(m,0,i)*(pow(-1,2+i))*determinant(mtemp));
    }

    return det;
}
Matrix transpose(Matrix m){
    Matrix mtemp;
    createMatrix(COL_EFF(m), ROW_EFF(m), &mtemp);
    int i,j;
    for(i=0; i<ROW_EFF(mtemp); i++){
        for(j=0; j<COL_EFF(mtemp); j++){
            ELMT(mtemp,i,j) = ELMT(m,j,i);
        }
    }
    return mtemp;
}
void pTranspose(Matrix *m){
    Matrix mtemp;
    createMatrix(COL_EFF(*m), ROW_EFF(*m), &mtemp);
    int i,j;
    for(i=0; i<COL_EFF(*m); i++){
        for(j=0; j<ROW_EFF(*m); j++){
            ELMT(mtemp,i,j) = ELMT(*m,j,i);
        }
    }
    *m = mtemp;
}