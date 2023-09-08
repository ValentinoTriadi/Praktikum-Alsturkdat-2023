#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik L1,L2, L3;
    int i;
    readList(&L1);
    readList(&L2);
    CreateListStatik(&L3);

    for (i = IDX_MIN; i<listLength(L1); i++){
        ELMT(L3,i) = ELMT(L1,i);
    }
    for (i = IDX_MIN; i<listLength(L2); i++){
        ELMT(L3, listLength(L1)+i) = ELMT(L2,i);
    }
    sortList(&L3, true);
    printList(L3);
    printf("\n");
    return 0;
}
