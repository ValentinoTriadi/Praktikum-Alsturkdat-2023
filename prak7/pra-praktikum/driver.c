#include <stdio.h>
#include "queue.c"

int main(){
    Queue q1,q2,q3;
    CreateQueue(&q1);
    CreateQueue(&q2);
    CreateQueue(&q3);
    printf("q1, q2, q3 awal: \n");
    displayQueue(q1);
    printf("\n");
    displayQueue(q2);
    printf("\n");
    displayQueue(q3);
    printf("\n");
    printf("isEmpty q1, q2, q3 awal: %d, %d, %d\n", isEmpty(q1), isEmpty(q2), isEmpty(q3));
    printf("isFull q1, q2, q3 awal: %d, %d, %d\n", isFull(q1), isFull(q2), isFull(q3));
    printf("length q1, q2, q3 awal: %d, %d, %d\n", length(q1), length(q2), length(q3));
    printf("\n");

    // enqueue(&q1, 1);
    // printf("\ntail: %d\n", TAIL(q1));
    // printf("idxhead: %d\n", IDX_HEAD(q1));
    // printf("idxtail: %d\n", IDX_TAIL(q1));
    // printf("length q1: %d\n", length(q1));
    // enqueue(&q1, 2);
    // printf("\ntail: %d\n", TAIL(q1));
    // printf("idxhead: %d\n", IDX_HEAD(q1));
    // printf("idxtail: %d\n", IDX_TAIL(q1));
    // printf("length q1: %d\n", length(q1));
    // enqueue(&q1, 3);
    // printf("\ntail: %d\n", TAIL(q1));
    // printf("idxhead: %d\n", IDX_HEAD(q1));
    // printf("idxtail: %d\n", IDX_TAIL(q1));
    // printf("length q1: %d\n", length(q1));

    for (int i = 0; i < 10; i++){
        enqueue(&q1,i+1);
        enqueue(&q2,i+1 + 10);
        enqueue(&q3,i+1 + 20);
    }

    printf("q1, q2, q3: \n");
    displayQueue(q1);
    printf("\n");
    displayQueue(q2);
    printf("\n");
    displayQueue(q3);
    printf("\n");
    printf("isEmpty q1, q2, q3: %d, %d, %d\n", isEmpty(q1), isEmpty(q2), isEmpty(q3));
    printf("isFull q1, q2, q3: %d, %d, %d\n", isFull(q1), isFull(q2), isFull(q3));
    printf("length q1, q2, q3: %d, %d, %d\n", length(q1), length(q2), length(q3));
    printf("\n");

    int x1;
    printf("\nDequeue q1:\n");
    dequeue(&q1,&x1);
    displayQueue(q1);
    printf(" %d\n", x1);
    dequeue(&q1,&x1);
    displayQueue(q1);
    printf(" %d\n", x1);
    dequeue(&q1,&x1);
    displayQueue(q1);
    printf(" %d\n", x1);
    dequeue(&q1,&x1);
    displayQueue(q1);
    printf(" %d\n", x1);
    dequeue(&q1,&x1);
    displayQueue(q1);
    printf(" %d\n\n", x1);
    
    for(int i = 0; i < 93; i++){
        enqueue(&q1, i);
    }

    printf("q1: \n");
    displayQueue(q1);
    printf("\n");
    printf("isEmpty q1: %d\n", isEmpty(q1));
    printf("isFull q1: %d\n", isFull(q1));
    printf("IDX_HEAD q1: %d\n", IDX_HEAD(q1));
    printf("IDX_TAIL q1: %d\n", IDX_TAIL(q1));
    printf("length q1: %d\n", length(q1));
    printf("\n");

    enqueue(&q1,999);
    enqueue(&q1,999);
    printf("q1: \n");
    displayQueue(q1);
    printf("\n");
    printf("isEmpty q1: %d\n", isEmpty(q1));
    printf("isFull q1: %d\n", isFull(q1));
    printf("IDX_HEAD q1: %d\n", IDX_HEAD(q1));
    printf("IDX_TAIL q1: %d\n", IDX_TAIL(q1));
    printf("length q1: %d\n", length(q1));
    printf("\n");

    printf("\nDequeue q1:\n");
    dequeue(&q1,&x1);
    displayQueue(q1);
    printf(" %d\n", x1);
    dequeue(&q1,&x1);
    displayQueue(q1);
    printf(" %d\n", x1);
    dequeue(&q1,&x1);
    displayQueue(q1);
    printf(" %d\n", x1);
    dequeue(&q1,&x1);
    displayQueue(q1);
    printf(" %d\n", x1);
    dequeue(&q1,&x1);
    displayQueue(q1);
    printf(" %d\n\n", x1);

    printf("q1: \n");
    displayQueue(q1);
    printf("\n");
    printf("isEmpty q1: %d\n", isEmpty(q1));
    printf("isFull q1: %d\n", isFull(q1));
    printf("IDX_HEAD q1: %d\n", IDX_HEAD(q1));
    printf("IDX_TAIL q1: %d\n", IDX_TAIL(q1));
    printf("length q1: %d\n", length(q1));
    printf("\n");
    
    printf("\nDequeue q2:\n");
    dequeue(&q2,&x1);
    displayQueue(q2);
    printf(" %d\n", x1);
    dequeue(&q2,&x1);
    displayQueue(q2);
    printf(" %d\n", x1);
    dequeue(&q2,&x1);
    displayQueue(q2);
    printf(" %d\n", x1);
    dequeue(&q2,&x1);
    displayQueue(q2);
    printf(" %d\n", x1);
    dequeue(&q2,&x1);
    displayQueue(q2);
    printf(" %d\n\n", x1);

    printf("q2: \n");
    displayQueue(q2);
    printf("\n");
    printf("isEmpty q2: %d\n", isEmpty(q2));
    printf("isFull q2: %d\n", isFull(q2));
    printf("IDX_HEAD q2: %d\n", IDX_HEAD(q2));
    printf("IDX_TAIL q2: %d\n", IDX_TAIL(q2));
    printf("length q2: %d\n", length(q2));
    printf("\n");

    printf("\nDequeue q2:\n");
    dequeue(&q2,&x1);
    displayQueue(q2);
    printf(" %d\n", x1);
    dequeue(&q2,&x1);
    displayQueue(q2);
    printf(" %d\n", x1);
    dequeue(&q2,&x1);
    displayQueue(q2);
    printf(" %d\n", x1);
    dequeue(&q2,&x1);
    displayQueue(q2);
    printf(" %d\n", x1);
    dequeue(&q2,&x1);
    displayQueue(q2);
    printf(" %d\n\n", x1);

    printf("q2: \n");
    displayQueue(q2);
    printf("\n");
    printf("isEmpty q2: %d\n", isEmpty(q2));
    printf("isFull q2: %d\n", isFull(q2));
    printf("IDX_HEAD q2: %d\n", IDX_HEAD(q2));
    printf("IDX_TAIL q2: %d\n", IDX_TAIL(q2));
    printf("length q2: %d\n", length(q2));
    printf("\n");


    return 0;
}