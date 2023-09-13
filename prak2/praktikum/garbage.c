#include <stdio.h>
#include "liststatik.h" 

int main () {
    ListStatik L1, L2;
    readList(&L1);
    readList(&L2);
    int time = 0, i, j;

    for(j = 1; j<=3; j++){
        if (indexOf(L1,j) != IDX_UNDEF) {
            int temp = 0, temp1 = 0;
            for (i = 0; i<listLength(L1); i++){
                if (i == 0 && ELMT(L1, 0) == j) {
                    time++;
                }
                if (i == getLastIdx(L1)) {
                    if (ELMT(L1, i) == j){
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
                    if (ELMT(L1, i) == j){
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
    }
        
    printf("%d\n", time);
    return 0;
}
