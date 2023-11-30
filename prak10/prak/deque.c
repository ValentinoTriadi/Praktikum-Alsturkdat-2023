#include "deque.h"
#include <stdio.h>

Address newNode(ElType x){
    Address p = (Address) malloc (sizeof(Node));
    if (p != NIL){
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}
boolean isEmpty(Deque q){
    return (ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL);
}
int length(Deque q){
    if (isEmpty(q)) return 0;
    Address p = ADDR_HEAD(q);
    int cnt = 1;
    while (p != ADDR_TAIL(q)){
        cnt++;
        p = NEXT(p);
    }
    return cnt;
}
void CreateDeque(Deque *q){
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}
void DisplayDeque(Deque q){
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
void EnqueueHead(Deque *q, ElType x){
    Address New = newNode(x);
    if (New != NIL){
        if (isEmpty(*q)){
            ADDR_HEAD(*q) = New;
            ADDR_TAIL(*q) = New;
        } else {
            NEXT(New) = ADDR_HEAD(*q);
            ADDR_HEAD(*q) = New;
        }
    }
}
void DequeueHead(Deque *q, ElType *x){
    Address p = ADDR_HEAD(*q);
    *x = INFO(p);
    if (length(*q) == 1){
        CreateDeque(q);
    } else {
        ADDR_HEAD(*q) = NEXT(p);
    }
    free(p);
}
void EnqueueTail(Deque *q, ElType x){
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
void DequeueTail(Deque *q, ElType *x){
    Address p = ADDR_HEAD(*q);
    Address loc = NIL;
    *x = TAIL(*q);
    if (length(*q) == 1){
        CreateDeque(q);
    } else {
        while (p != ADDR_TAIL(*q)){
            loc = p;
            p = NEXT(p);
        }
        NEXT(loc) = NIL;
        ADDR_TAIL(*q) = loc;
    }
    free(p);
}