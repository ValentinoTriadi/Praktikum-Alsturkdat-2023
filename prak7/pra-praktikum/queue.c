#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
boolean isEmpty(Queue q){
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFull(Queue q){
    return (((IDX_TAIL(q) + 1) % CAPACITY) == IDX_HEAD(q));
}
int length(Queue q){
    if (isEmpty(q)) return 0;
    if (isFull(q)) return CAPACITY;
    return (IDX_TAIL(q) - IDX_HEAD(q) + 1 + CAPACITY) % CAPACITY;
}
void enqueue(Queue *q, ElType val){
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q) = ((IDX_TAIL(*q) + 1) % CAPACITY);
    }
    TAIL(*q) = val;
}
void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if (length(*q) == 1) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q) = ((IDX_HEAD(*q) + 1) % CAPACITY);
    }
}
void displayQueue(Queue q){
    int i, val, len = length(q);
    printf("[");
    for (i = 0; i < len; i++){
        dequeue(&q, &val);
        printf("%d", val);
        if (i < len-1) printf(",");
    }
    printf("]\n");
}