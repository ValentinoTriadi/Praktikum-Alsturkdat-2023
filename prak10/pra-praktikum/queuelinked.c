#include "queuelinked.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x){
    Address p = (Address) malloc (sizeof(Node));
    if (p != NIL){
        INFO(p) = x;
        NEXT(p) = NIL;
    }
}
boolean isEmpty(Queue q){
    return (ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL);
}
int length(Queue q){
    if (isEmpty(q)) return 0;
    Address p = ADDR_HEAD(q);
    int cnt = 1;
    while (p != ADDR_TAIL(q)){
        cnt++;
        p = NEXT(p);
    }
    return cnt;

}
void CreateQueue(Queue *q){
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}
void DisplayQueue(Queue q){
    int i;
    Address p = ADDR_HEAD(q);
    printf("[");
    for(i = 0; i<length(q); i++){
        printf("%d", INFO(p));
        p = NEXT(p);
        if (i < length(q)-1) printf(",");
    }
    printf("]");
}
void enqueue(Queue *q, ElType x){
    Address New = newNode(x);
    if (New != NIL){
        if (isEmpty(*q)){
            ADDR_HEAD(*q) = New;
            ADDR_TAIL(*q) = New;
        } else {
            NEXT(ADDR_TAIL(*q)) = New;
            ADDR_TAIL(*q) = New;
        }
    }
}
void dequeue(Queue *q, ElType *x){
    Address p = ADDR_HEAD(*q);
    *x = INFO(p);
    if (length(*q) == 1){
        CreateQueue(q);
    } else {
        ADDR_HEAD(*q) = NEXT(p);
    }
    free(p);
}