#include "queuelinked.h"
#include <stdio.h>

int main(){
    Queue q;
    CreateQueue(&q);
    int n, i, val, temp;
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        enqueue(&q, val);
        while(val - HEAD(q) > 300){
            dequeue(&q, &temp);
        }
        printf("%d\n", length(q));
    }
    return 0;
}