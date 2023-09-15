#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "listdin.h"

void deleteFirst(ListDin *l) {
    int i;
    for (i = IDX_MIN; i<NEFF(*l)-1; i++) {
        ELMT(*l,i) = ELMT(*l, i+1);
    }
    NEFF(*l)--;
}
int main(){
    ListDin l1,l2,l3;
    int n,m,x,i;
    scanf("%d", &n);
    CreateListDin(&l1, n);
    for (i=0; i<n; i++){
        scanf("%d", &x);
        insertLast(&l1, x);
    }
    scanf("%d", &m);
    CreateListDin(&l2, m);
    for (i=0; i<m; i++){
        scanf("%d", &x);
        insertLast(&l2, x);
    }
    CreateListDin(&l3, m+n);

    for(i=0; i < (n+m); i++){
        if (listLength(l2) == 0){
            insertLast(&l3,ELMT(l1,0));
            deleteFirst(&l1);
        } else if (listLength(l1) == 0){
            insertLast(&l3,ELMT(l2,0));
            deleteFirst(&l2);
        } else if (ELMT(l1,0) >= ELMT(l2,0)){
            insertLast(&l3,ELMT(l1,0));
            deleteFirst(&l1);
        } else {
            insertLast(&l3,ELMT(l2,0));
            deleteFirst(&l2);
        }
    }
    printList(l3);
    printf("\n");
    return 0;
}
