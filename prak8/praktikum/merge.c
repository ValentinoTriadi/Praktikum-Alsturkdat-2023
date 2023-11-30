#include "merge.h"
#include "listlinier.h"

void splitList(List source, List* front, List* back){
    int i, len = length(source);
    ElType val;
    for (i = 0; i < len/2; i++){
        deleteLast(&source, &val);
        insertFirst(back, val);
    }
    while (!isEmpty(source)){
        deleteFirst(&source, &val);
        insertLast(front, val);
    }
}
List merge(List a, List b){
    List front, back;
    CreateList(&front);
    CreateList(&back);
    front = a;
    back = b;
    if (length(a) >= 1){
        displayList(a);
        printf("\n");
        if (length(a)>1){
            List f1, b1;
            CreateList(&f1);
            CreateList(&b1);
            splitList(a,&f1,&b1);
            front = merge(f1,b1);
        }
    }
    if (length(b) >= 1){
        displayList(b);
        printf("\n");
        if (length(b)>1){
            List f2, b2;
            CreateList(&f2);
            CreateList(&b2);
            splitList(b,&f2,&b2);
            back = merge(f2,b2);
        }
    }
    if (INFO(front)>INFO(back)) return concat(back,front);
    return concat(front, back);
}
void mergeSort(List* list){
    List f, b;
    displayList(*list);
    printf("\n");
    CreateList(&f);
    CreateList(&b);
    splitList(*list, &f, &b);
}