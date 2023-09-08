#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik L1;
    int i,n, idx, max, min;
    float avg;
    readList(&L1);
    scanf("%d", &n);
    
    sortList(&L1, true);
    printList(L1);
    printf("\n");
    
    for (i=getFirstIdx(L1); i<=getLastIdx(L1); i++){
        avg += ELMT(L1,i);
    }
    printf("Average: %.2f\n", (avg/listLength(L1)));

    idx = indexOf(L1, n);
    if (idx == IDX_UNDEF) {
        printf("%d tidak ada\n", n);
    } else {
        printf("%d\n", idx);
    }

    extremeValues(L1, &max, &min);
    sortList(&L1,true);
    if (n == max){
        printf("X maksimum\n");
    }
    if (n == min){
        printf("X minimum\n");
    }
    if (listLength(L1) % 2 == 1){
        if (n == ELMT(L1, listLength(L1)/2)) printf("X median\n");
    } else {
        if (n == ELMT(L1, listLength(L1)/2 -1)) printf("X median\n");
    }

    return 0;
}
