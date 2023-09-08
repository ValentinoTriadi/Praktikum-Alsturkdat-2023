#include <stdio.h>
#include "liststatik.h" 

int main () {
    ListStatik L1, L2;
    readList(&L1);
    readList(&L2);
    int time = 0, i,
    idx0 = indexOf(L1, 0), 
    idx1 = indexOf(L1, 1), 
    idx2 = indexOf(L1, 2),
    idx3 = indexOf(L1, 3); 

    if (idx3 != IDX_UNDEF) {
        int temp = 0, temp1 = 0;
        for (i = 0; i<listLength(L1); i++){
            if (i == 0 && ELMT(L1, 0) == 3) {
                time++;
            }
            if (i == getLastIdx(L1)) {
                if (ELMT(L1, i) == 3){
                    temp += ELMT(L2,i-1);
                    temp1 += temp;
                    time += temp + 1;
                    temp = 0;
                    time += temp1;
                } else {
                    temp += ELMT(L2, i-1);
                    time += temp1;
                }
            }
            if (i != 0 && i != getLastIdx(L1)) {
                if (ELMT(L1, i) == 3){
                    temp += ELMT(L2,i-1);
                    temp1 += temp;
                    time += temp + 1;
                    temp = 0;
                } else {
                    temp += ELMT(L2, i-1);
                }
            }
        }
    }
    if (idx1 != IDX_UNDEF) {
        int temp = 0, temp1 = 0;
        for (i = 0; i<listLength(L1); i++){
            if (i == 0 && ELMT(L1, 0) == 1) {
                time++;
            }
            if (i == getLastIdx(L1)) {
                if (ELMT(L1, i) == 1){
                    temp += ELMT(L2,i-1);
                    temp1 += temp;
                    time += temp + 1;
                    temp = 0;
                    time += temp1;
                } else {
                    temp += ELMT(L2, i-1);
                    time += temp1;
                }
            }
            if (i != 0 && i != getLastIdx(L1)) {
                if (ELMT(L1, i) == 1){
                    temp += ELMT(L2,i-1);
                    temp1 += temp;
                    time += temp + 1;
                    temp = 0;
                } else {
                    temp += ELMT(L2, i-1);
                }
            }
        }
    }
    if (idx2 != IDX_UNDEF) {
        int temp = 0, temp1 = 0;
        for (i = 0; i<listLength(L1); i++){
            if (i == 0 && ELMT(L1, 0) == 2) {
                time++;
            }
            if (i == getLastIdx(L1)) {
                if (ELMT(L1, i) == 2){
                    temp += ELMT(L2,i-1);
                    temp1 += temp;
                    time += temp + 1;
                    temp = 0;
                    time += temp1;
                } else {
                    temp += ELMT(L2, i-1);
                    time += temp1;
                }
            }
            if (i != 0 && i != getLastIdx(L1)) {
                if (ELMT(L1, i) == 2){
                    temp += ELMT(L2,i-1);
                    temp1 += temp;
                    time += temp + 1;
                    temp = 0;
                } else {
                    temp += ELMT(L2, i-1);
                }
            }
        }
    }
    printf("%d\n", time);
    return 0;
}
