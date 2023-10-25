#include <stdio.h>
#include "listlinier.c"

int main(){
    List l1,l2,l3;
    ElType val;
    CreateList(&l1);
    CreateList(&l2);
    CreateList(&l3);
    printf("Cek Awal (CreateList)\nisEmpty L1,L2,L3: %d %d %d\n", isEmpty(l1), isEmpty(l2), isEmpty(l3));
    printf("Displat List L1, L2, L3: \n");
    displayList(l1);
    printf("Length: %d\n", length(l1));
    displayList(l2);
    printf("Length: %d\n", length(l2));
    displayList(l3);
    printf("Length: %d\n", length(l3));

    printf("\nInsert El 1-20 at first into L1:\n");
    for(int i = 20; i > 0; i--){
        insertFirst(&l1, i);
    }
    displayList(l1);
    printf("Length: %d\n", length(l1));
    
    printf("\nInsert El 101-110 at index 0 into L1:\n");
    for(int i = 10; i > 0; i--){
        insertAt(&l1, i+100, 0);
    }
    displayList(l1);
    printf("Length: %d\n", length(l1));

    printf("\nInsert El 111-120 at index 10 into L1:\n");
    for(int i = 10; i > 0; i--){
        insertAt(&l1, i+110, 10);
    }
    displayList(l1);
    printf("Length: %d\n", length(l1));

    printf("\nInsert El 121-130 at index 40 into L1:\n");
    for(int i = 10; i > 0; i--){
        insertAt(&l1, i+120, 40);
    }
    displayList(l1);
    printf("Length: %d\n", length(l1));

    printf("\nInsert El 201-220 at last into L1:\n");
    for(int i = 1; i <= 20; i++){
        insertLast(&l1, i+200);
    }
    displayList(l1);
    printf("Length: %d\n", length(l1));

    printf("\nDelete 5 El at first on L1:\n");
    for(int i = 1; i <= 5; i++){
        deleteFirst(&l1,&val);
        printf("Deleted EL: %d\n", val);
        displayList(l1);
        printf("Length: %d\n", length(l1));
    }

    printf("\nDelete 5 El at last on L1:\n");
    for(int i = 1; i <= 5; i++){
        deleteLast(&l1,&val);
        printf("Deleted EL: %d\n", val);
        displayList(l1);
        printf("Length: %d\n", length(l1));
    }

    printf("\nDelete 5 El at index 5 on L1:\n");
    for(int i = 1; i <= 5; i++){
        deleteAt(&l1,5,&val);
        printf("Deleted EL: %d\n", val);
        displayList(l1);
        printf("Length: %d\n", length(l1));
    }

    printf("\nDelete 5 El at index 0 on L1:\n");
    for(int i = 1; i <= 5; i++){
        deleteAt(&l1,0,&val);
        printf("Deleted EL: %d\n", val);
        displayList(l1);
        printf("Length: %d\n", length(l1));
    }

    printf("\nDelete 5 El at index 49 ~ 45 on L1:\n");
    for(int i = 1; i <= 5; i++){
        deleteAt(&l1,50-i,&val);
        printf("Deleted EL: %d\n", val);
        displayList(l1);
        printf("Length: %d\n", length(l1));
    }

    printf("\nGet El at index multiple of 5 on L1:\n");
    displayList(l1);
    for(int i = 0; i < length(l1); i+=5){
        printf("EL[%d]: %d\n", i, getElmt(l1,i));
    }

    printf("\nSet El that less equal than 20 by El*100 on L1:\n");
    for(int i = 1; i <= 20; i++){
        int index = indexOf(l1,i);
        setElmt(&l1,index,getElmt(l1,index)*100);
    }
    displayList(l1);

    printf("\nDelete all El in L1:\n");
    int len = length(l1);
    for(int i = 1; i <= len; i++){
        deleteFirst(&l1, &val);
    }
    displayList(l1);
    printf("Length: %d\n", length(l1));

    printf("\nConcat L1 and L2 to L3:\n");
    l3 = concat(l1,l2);
    displayList(l3);
    printf("Length: %d\n", length(l3));

    printf("\nFill L1 with odd integer (1-19):\n");
    for (int i = 1; i < 20; i+=2){
        insertLast(&l1,i);
    }
    displayList(l1);
    printf("Length: %d\n", length(l1));

    printf("\nFill L2 with even integer (2-20):\n");
    for (int i = 2; i <= 20; i+=2){
        insertLast(&l2,i);
    }
    displayList(l2);
    printf("Length: %d\n", length(l2));

    printf("\nConcat L1 and L2 to L3:\n");
    l3 = concat(l1,l2);
    displayList(l3);
    printf("Length: %d\n", length(l3));

    printf("\n----------Additional Concat Case----------\n");
    printf("\nFill L2 with integer (1-25):\n");
    for (int i = 1; i <= 25; i++){
        insertLast(&l2,i);
    }
    printf("L1: ");
    displayList(l1);
    printf("Length: %d\n", length(l1));
    printf("L2: ");
    displayList(l2);
    printf("Length: %d\n", length(l2));

    printf("\nConcat L1 and L2 to L3:\n");
    l3 = concat(l1,l2);
    displayList(l3);
    printf("Length: %d\n", length(l3));

    printf("\nFill L1 with integer (25-1):\n");
    for (int i = 25; i >= 1; i--){
        insertLast(&l1,i);
    }
    printf("L1: ");
    displayList(l1);
    printf("Length: %d\n", length(l1));
    printf("L2: ");
    displayList(l2);
    printf("Length: %d\n", length(l2));

    printf("\nConcat L1 and L2 to L3:\n");
    l3 = concat(l1,l2);
    displayList(l3);
    printf("Length: %d\n", length(l3));

    return 0;
}