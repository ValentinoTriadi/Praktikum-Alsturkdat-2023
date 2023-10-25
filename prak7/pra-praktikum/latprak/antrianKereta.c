// #include "./../queue.h"
#include "./../queue.c"
#include <stdio.h>

float avgElmt(Queue Q){
    float sum = 0, count = ((float) length(Q));
    int i;
    ElType val;
    for (i = 0; i<count; i++){
        dequeue(&Q, &val);
        sum += val;
    }
    if (!count) return 0;
    return sum/count;
}

int main(){
    float avg;
    ElType x, val;
    Queue q;
    CreateQueue(&q);
    do {
        scanf("%d", &x);
        if (x == 1){
            scanf("%d", &val);
            if (isFull(q)){
                printf("Queue penuh\n");
            } else {
                enqueue(&q, val);
            }
        }
        if (x == 2){
            if (isEmpty(q)){
                printf("Queue kosong\n");
            } else {
                dequeue(&q, &val);
            }
        }
    } while (x != 0);

    printf("%d\n", length(q));
    
    avg = avgElmt(q);
    if (!avg) {
        printf("Tidak bisa dihitung\n");
    } else {
        printf("%.2f\n", avg);
    }

    return 0;
}