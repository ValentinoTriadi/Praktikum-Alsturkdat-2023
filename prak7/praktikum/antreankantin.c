#include <stdio.h>
#include "queue.h"

int main(){
    int sum = 0, count = 0, x, val;
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
        } else if (x == 2){
            if (isEmpty(q)){
                printf("Queue kosong\n");
            } else {
                dequeue(&q, &val);
                sum += val;
                count++;
            }
        }
    } while (x != 0);

    printf("%d\n", count);

    if (!count) {
        printf("Tidak bisa dihitung\n");
    } else {
        printf("%.2f\n", (float)((float)sum/(float) count));
    }
    return 0;
}