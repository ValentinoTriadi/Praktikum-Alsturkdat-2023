//LIST DINAMIK

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "listdin.c"

int main() {
    ListDin l1;
    ListDin l2;
    ListDin l3;
    int capacity = 20;
    ElType min;
    CreateListDin(&l1,capacity); //create list
    CreateListDin(&l2,capacity);
    printf("Input data for list 1:\n");
    readList(&l1); //input list
    printf("List 1:\n");
    printList(l1);
    printf("Input data for list 2:\n");
    readList(&l2); //input list
    dealocateList(&l2);
    printf("List 2:\n");
    printList(l2);
    printf("\n");
    printf("length of list1: ");
    printf("%d\n",listLength(l1));
    printf("first index of list1 : ");
    printf ("%d\n",getFirstIdx(l1));
    printf("last index of list1 : ");
    printf("%d\n",getLastIdx(l1));
    printf("apakah id 0 valid untuk list2: ");
    printf("%d\n",isIdxValid(l2,0));
    printf("apakah id 3 efektif untuk list1: ");
    printf("%d\n",isIdxEff(l1,3));
    printf("apakah list kosong untuk list2: ");
    printf("%d\n",isEmpty(l2));
    printf("apakah list penuh untuk list1: ");
    printf("%d\n",isFull(l1));
    printf("coba plus minus 2 list \n");
    printf("input baru list2 : \n");
    CreateListDin(&l2,capacity);
    readList(&l2);
    printList(l2);
    printf("penambahan 2 list: \n");
    printList(plusMinusList(l1,l2,1));
    printf("pengurangan 2 list: \n");
    printList(plusMinusList(l1,l2,0));
    printf("copy l1 untuk l3: \n");
    copyList(l1,&l3);
    printList(l3);
    printf("Delete Last list 1: \n");
    deleteLast(&l1, &min);
    printList(l1);
    printf("Insert last list 1: \n");
    insertLast(&l1,20);
    printList(l1);
    printf("sort utuk list 1(asc),2(asc),3(desc)");
    sort(&l1,1);
    sort(&l2,1);
    sort(&l3,0);
    printList(l1);
    printList(l2);
    printList(l3);
    printf("count val list 1");
    printf("%d",countVal(l1,1));

    ListDin L1,L2;
    CreateListDin(&L1,100);
    CreateListDin(&L2,100);
    readList(&L1);
    copyList(L1,&L2);
    printList(L2);
    

   return 0;
}