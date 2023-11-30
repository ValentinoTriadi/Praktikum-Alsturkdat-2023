#include <stdio.h>
#include <math.h>
#include "matrix.h"

int main(){
    Matrix mtx, subm;
    int n,m,x,i,j,k,a,b;
    boolean kondisi=true, kondisitotal=false, kondisitotal1 = true;
    scanf("%d %d", &n,&m);
    readMatrix(&mtx,n,m);
    scanf("%d", &x);
    for(k = 0; k<x; k++){
        kondisitotal = false;
        scanf("%d %d", &i, &j);
        readMatrix(&subm, i, j);
        for(a=0; a<=getLastIdxRow(mtx); a++){
            for(b=0; b<=getLastIdxCol(mtx); b++){
                if (ELMT(mtx,a,b) == ELMT(subm,0,0) && a<=n-i && b<=m-j){
                    kondisi = true;
                    for(i=0; i<=getLastIdxRow(subm); i++){
                        for(j=0; j<=getLastIdxCol(subm); j++){
                            if (ELMT(mtx,a+i,b+j) != ELMT(subm,i,j)){
                                kondisi = false;
                            }
                        }
                    }
                }
                if (kondisi) kondisitotal = true;
            }
        }
        if(!kondisitotal) kondisitotal1 = false;
    }
    if (kondisitotal1){
        printf("Puzzle dapat diselesaikan.\n");
    } else {
        printf("Puzzle tidak dapat diselesaikan.\n");
    }
    return 0;
}