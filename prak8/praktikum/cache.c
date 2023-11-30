#include "listlinier.h"
#include <stdio.h>

int main(){
    int len,q,hitcnt = 0, i, val, totalel;
    ElType tempval;
    List l;
    CreateList(&l);
    scanf("%d", &len);
    scanf("%d", &q);
    totalel = q;
    while(q--){
        scanf("%d",&val);
        if (indexOf(l,val) == -1){
            printf("miss ");
            if (length(l) == len){
                deleteLast(&l, &tempval);
            }
            insertFirst(&l, val);
        } else {
            printf("hit ");
            hitcnt++;
            deleteAt(&l, indexOf(l,val), &tempval);
            insertFirst(&l, val);
        }
        displayList(l);
        printf("\n");
    }
    if (totalel){
        printf("hit ratio: %.2f\n", (float) hitcnt / (float) totalel);
    } else {
        printf("hit ratio: 0.00\n");
    }
    return 0;
}