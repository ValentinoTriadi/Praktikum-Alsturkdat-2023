#include "stacklinked.h"
#include <stdio.h>

int main(){
    int t, n, val, temp, i, j;
    scanf("%d", &t);
    Stack s, kecil, d;
    for (i = 0; i < t; i++){
        boolean isPosible = true;
        CreateStack(&d);
        CreateStack(&s);
        CreateStack(&kecil);
        scanf("%d", &n);
        for (j = 0; j<n; j++){
            scanf("%d", &val);
            push(&kecil, val);
        }
        for (j = 0; j<n; j++){
            pop(&kecil, &val);
            push(&d, val);
        }
        while (!isEmpty(d)){
            if (!isEmpty(kecil) && !isEmpty(s) && TOP(kecil) == TOP(s) + 1) {
                pop(&kecil, &temp);
                push(&s, temp);
            } else {
                pop(&d, &val);
                if (isEmpty(s) && val == 1){
                    push(&s, val);
                } else if (!isEmpty(s) && val == TOP(s) + 1){
                    push(&s, val);
                } else {
                    if (isEmpty(kecil)){
                        push(&kecil, val);
                    } else if (!isEmpty(kecil) && TOP(kecil) > val){
                        push(&kecil, val);
                    } else {
                        isPosible = false;
                        break;
                    }
                }
            }
        }
        if (isPosible){
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}