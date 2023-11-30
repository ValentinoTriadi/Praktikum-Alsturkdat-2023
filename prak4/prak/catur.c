#include <stdio.h>
#include <math.h>
#include "matrix.h"

int main(){
    Matrix m;
    readMatrix(&m,8,8);
    int i,j, hitam=0, putih=0;

    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            if (ELMT(m,i,j) == 1){
                if ((i+j) % 2 == 0){
                    hitam++;
                } else {
                    putih++;
                }
            }
        }
    }
    printf("%d %d\n", hitam, putih);
    return 0;
}