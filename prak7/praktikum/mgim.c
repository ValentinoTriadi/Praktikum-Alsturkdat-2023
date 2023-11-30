#include "queue.h"
#include <stdio.h>

int main () {
    Queue q;
    CreateQueue(&q);
    int N, i, val, R = 1, count, tempval1, tempval2, first;
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%d", &val);
        enqueue(&q, val);
    }
    while (!isEmpty(q)){
        dequeue(&q, &val);
        count = 0;
        while (val != 0){
            tempval1 = 0;
            tempval2 = 0;
            first = 0;
            for (i = val-1; i>1; i--){
                if (val % i == 0) {
                    if (!first){
                        tempval1 = i;
                        tempval2 = i;
                        first = i;
                    } else {
                        tempval1 = tempval2;
                        tempval2 = i;
                    }
                    if (val / tempval2 == tempval1) break;
                    if (val/tempval2 == tempval2){
                        tempval1 = tempval2;
                        break;
                    }
                    // printf("%d,%d  ", tempval1, tempval2);
                }
            }
            if (tempval1){
                val = tempval1;
            } else {
                val--;
            }
            // printf(":%d:  ", val);
            count++;
        }
        // printf("\ncount: %d\n", count);
        R *= count;
    }
    printf("%d\n", R);

    return 0;
}
