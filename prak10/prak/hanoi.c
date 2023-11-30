#include "stacklinked.h"
#include <stdio.h>

int main(){
    Stack s1, s2, s3;
    CreateStack(&s1);
    CreateStack(&s2);
    CreateStack(&s3);
    push(&s1, 5);
    push(&s1, 4);
    push(&s1, 3);
    push(&s1, 2);
    push(&s1, 1);
    int i, n;
    scanf("%d", &n);
    for(i = 0; i<n; i++){
        int x,y, temp;
        scanf("%d %d", &x, &y);
        if (x == 1){
            if (isEmpty(s1)){
                printf("Menara kosong\n");
            } else {
                pop(&s1, &temp);
                if (y == 2){
                    if (!isEmpty(s2) && TOP(s2) < temp){
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s1, temp);
                    } else {
                        push(&s2, temp);
                    }
                } else if(y == 3){
                    if (!isEmpty(s3) && TOP(s3) < temp){
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s1, temp);
                    } else {
                        push(&s3, temp);
                    }
                }
            }
        } else if (x == 2){
            if (isEmpty(s2)){
                printf("Menara kosong\n");
            } else {
                pop(&s2, &temp);
                if (y == 1){
                    if (!isEmpty(s1) && TOP(s1) < temp){
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s2, temp);
                    } else {
                        push(&s1, temp);
                    }
                } else if(y == 3){
                    if (!isEmpty(s3) && TOP(s3) < temp){
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s2, temp);
                    } else {
                        push(&s3, temp);
                    }
                }
            }
        } else{
            if (isEmpty(s3)){
                printf("Menara kosong\n");
            } else {
                pop(&s3, &temp);
                if (y == 1){
                    if (!isEmpty(s1) && TOP(s1) < temp){
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s3, temp);
                    } else {
                        push(&s1, temp);
                    }
                } else if(y == 2){
                    if (!isEmpty(s2) && TOP(s2) < temp){
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s3, temp);
                    } else {
                        push(&s2, temp);
                    }
                }
            }
        }
    }

    printf("Menara 1: ");
    DisplayStack(s1);
    printf("\n");
    printf("Menara 2: ");
    DisplayStack(s2);
    printf("\n");
    printf("Menara 3: ");
    DisplayStack(s3);
    printf("\n");
    return 0;
}