#include "queue.h"
#include <stdio.h>
#include <math.h>

int main(){
    int i, n, k, val, temp;
    Queue q;
    CreateQueue(&q);
    scanf("%d", &n);
    scanf("%d", &k);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        enqueue(&q, val);
    }
    if (k % 2 == 0){
        for(i=0; i<k/2; i++){
            temp = q.buffer[k-i-1];
            q.buffer[k-i-1] = q.buffer[i];
            q.buffer[i] = temp;
        }
    } else {
        for(i=0; i<floor(k/2); i++){
            temp = q.buffer[k-i-1];
            q.buffer[k-i-1] = q.buffer[i];
            q.buffer[i] = temp;
        }
    }
    displayQueue(q);
    return 0;
}