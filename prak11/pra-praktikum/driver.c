#include "listrec.c"
#include <stdio.h>

int main(){
    List l1, l2;
    l1 = NULL;
    l2 = NULL;
    printf("isEmpty l1, l2: %d, %d\n", isEmpty(l1), isEmpty(l2));
    printf("Length l1, l2: %d, %d\n", length(l1), length(l2));
    printf("isOneElmt l1, l2: %d, %d\n", isOneElmt(l1), isOneElmt(l2));
    printf("DisplayList 1:\n");
    displayList(l1);
    printf("DisplayList 2:\n");
    displayList(l2);

    l1 = konso(l1,221);
    l2 = konso(l2,100);

    printf("isEmpty l1, l2: %d, %d\n", isEmpty(l1), isEmpty(l2));
    printf("Length l1, l2: %d, %d\n", length(l1), length(l2));
    printf("isOneElmt l1, l2: %d, %d\n", isOneElmt(l1), isOneElmt(l2));
    printf("head l1, l2: %d, %d\n", head(l1), head(l2));
    printf("TAIL 1:\n");
    displayList(tail(l1));
    printf("TAIL 2:\n");
    displayList(tail(l2));
    printf("DisplayList 1:\n");
    displayList(l1);
    printf("DisplayList 2:\n");
    displayList(l2);

    for (int i = 0; i < 5; i++){
        l1 = konso(l1,i);
        l2 = konsb(l2,i);
    }

    printf("isEmpty l1, l2: %d, %d\n", isEmpty(l1), isEmpty(l2));
    printf("Length l1, l2: %d, %d\n", length(l1), length(l2));
    printf("isOneElmt l1, l2: %d, %d\n", isOneElmt(l1), isOneElmt(l2));
    printf("head l1, l2: %d, %d\n", head(l1), head(l2));
    printf("TAIL 1:\n");
    displayList(tail(l1));
    printf("TAIL 2:\n");
    displayList(tail(l2));
    printf("DisplayList 1:\n");
    displayList(l1);
    printf("DisplayList 2:\n");
    displayList(l2);


    List l3 = copy(l1);
    printf("DisplayList 3 (Copy of L1):\n");
    displayList(l3);
    List l4 = concat(l1,l2);
    printf("DisplayList 4 (Concat l1,l2):\n");
    displayList(l4);
    return 0;
}