#include "stacklinked.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x){
    Address p = (Address) malloc (sizeof(Node));
    if (p != NIL){
        INFO(p) = x;
        NEXT(p) = NIL;
    }
}
boolean isEmpty(Stack q){
    return (ADDR_TOP(q) == NIL);
}
int length(Stack q){
    if (isEmpty(q)) return 0;
    Address p = ADDR_TOP(q);
    int cnt = 0;
    while (p != NIL){
        cnt++;
        p = NEXT(p);
    }
    return cnt;

}
void CreateStack(Stack *q){
    ADDR_TOP(*q) = NIL;
}
void DisplayStack(Stack q){
    int i;
    Address p = ADDR_TOP(q);
    printf("[");
    for(i = 0; i<length(q); i++){
        printf("%d", INFO(p));
        p = NEXT(p);
        if (i < length(q)-1) printf(",");
    }
    printf("]");
}
void push(Stack *q, ElType x){
    Address New = newNode(x);
    if (New != NIL){ 
        if (isEmpty(*q)){
            ADDR_TOP(*q) = New;
        } else {
            NEXT(New) = ADDR_TOP(*q);
            ADDR_TOP(*q) = New;
        }
    }
}
void pop(Stack *q, ElType *x){
    Address p = ADDR_TOP(*q);
    *x = TOP(*q);
    if (length(*q) == 1){
        CreateStack(q);
    } else {
        ADDR_TOP(*q) = NEXT(p);
    }
    free(p);
}