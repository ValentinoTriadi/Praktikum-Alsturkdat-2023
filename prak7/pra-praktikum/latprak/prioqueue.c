#include "prioqueue.h"

void CreatePrioQueue(PrioQueue *pq){
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}
boolean isEmpty(PrioQueue pq){
    return (IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF);
}
boolean isFull(PrioQueue pq){
    return (IDX_HEAD(pq) == 0 && IDX_TAIL(pq) == CAPACITY-1);
}
int length(PrioQueue pq){
    if(isEmpty(pq)) return 0;
    return (IDX_TAIL(pq) - IDX_HEAD(pq) + 1);
}
void enqueue(PrioQueue *pq, ElType val){
    int i;
    ElType temp;
    if (isEmpty(*pq)){
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
    } else {
        if (IDX_TAIL(*pq) == CAPACITY-1 && IDX_HEAD(*pq) != 0){
            for (i = 0; i < length(*pq); i++){
                (*pq).buffer[i] = (*pq).buffer[i + IDX_HEAD(*pq)];
            }
            IDX_TAIL(*pq) -= IDX_HEAD(*pq); 
            IDX_HEAD(*pq) = 0;
        }
        IDX_TAIL(*pq)++;
    }
    TAIL(*pq) = val;

    // urutin queue
    i = IDX_TAIL(*pq);
    while ((i>0) && (pq->buffer[i-1].score < pq->buffer[i].score) || ((pq->buffer[i-1].score == pq->buffer[i].score) && (pq->buffer[i-1].tArrival > pq->buffer[i].tArrival)))
    {
        temp = pq->buffer[i];
        pq->buffer[i] = pq->buffer[i-1];
        pq->buffer[i-1] = temp;
        i--;
    }
}
void dequeue(PrioQueue * pq, ElType *val){
    *val = HEAD(*pq);
    if (length(*pq) == 1) {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    } else {
        IDX_HEAD(*pq)++;
    }
}
