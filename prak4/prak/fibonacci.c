#include <stdio.h>
#include <math.h>
#include "matrix.h"


Matrix PangkatMatrix (Matrix m, unsigned long int pangkat){
    if (pangkat == 0){
        Matrix mtemp;
        createMatrix(2,2,&mtemp);
        ELMT(mtemp,0,0) = 1;
        ELMT(mtemp,1,1) = 1;
        return mtemp;
    } else if (pangkat == 1){
        return m;
    } else {
        Matrix m2 = PangkatMatrix(m, pangkat/2);
        Matrix mulMatrix = multiplyMatrixWithMod(m2,m2, 2003);
        if (pangkat % 2 == 1) {
            mulMatrix = multiplyMatrixWithMod(mulMatrix,m, 2003);
        }
        return mulMatrix;
    }
}

int main(){
    Matrix m;
    Matrix m1;
    createMatrix(2,1,&m);
    createMatrix(2,2,&m1);
    ELMT(m,0,0) = 1;
    ELMT(m,1,0) = 1;
    ELMT(m1,0,0) = 1;
    ELMT(m1,0,1) = 1;
    ELMT(m1,1,0) = 1;
    unsigned long int x, r;
    scanf("%d",&x);

    // for (unsigned long int i = 0; i<x-2; i++){
    //     m = multiplyMatrixWithMod(m1,m,2003);
    // }
    m1 = PangkatMatrix(m1,x-2);
    m = multiplyMatrixWithMod(m1,m,2003);
    r = ELMT(m,0,0);
    printf("%d\n", r);
    return 0;
}