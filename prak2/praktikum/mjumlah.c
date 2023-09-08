#include <stdio.h>
#include <math.h>
#include "liststatik.h"

int main (){
    ListStatik L1, L2, L3, L4;
    readList(&L1);
    readList(&L2);
    CreateListStatik(&L3);
    CreateListStatik(&L4);

    int i, num;
    for (i = getFirstIdx(L1); i<= getLastIdx(L1); i++){
        num += (ELMT(L1, i)*(pow(10,(listLength(L1)-1-i))));
    }
    for (i = getFirstIdx(L2); i<= getLastIdx(L2); i++){
        num += (ELMT(L2, i)*(pow(10,(listLength(L2)-1-i))));
    }
    
    i = 0;
    while (num!=0) {
        ELMT(L3,i) = num % 10;
        num = floor(num/10);
        i++;
    }

    for (i = getLastIdx(L3); i>= IDX_MIN; i--){
        ELMT(L4,i) = ELMT(L3, getLastIdx(L3)-i);
    }
    
    printList(L4);
    printf("\n");
    return 0;
}