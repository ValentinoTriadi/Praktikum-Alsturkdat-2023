#include "stacklinked.h"
#include <stdio.h>

int main(){
    Stack A;
    Stack B;
    CreateStack(&A);
    CreateStack(&B);
    int a, b, i, val, temp;
    scanf("%d %d", &a, &b);
    for(i = 0; i < a; i++){
        scanf("%d", &val);
        if (val == 0){
            if(!isEmpty(A)){
                pop(&A, &temp);
            }
        } else {
            push(&A, val);
        }
    }
    for(i = 0; i < b; i++){
        scanf("%d", &val);
        if (val == 0){
            if(!isEmpty(B)){
                pop(&B, &temp);
            }
        } else {
            push(&B, val);
        }
    }
    boolean same = true;
    if (length(A) != length(B)) same = false;
    Address pa = ADDR_TOP(A);
    Address pb = ADDR_TOP(B);
    while(pa != NIL && pb != NIL && !same){
        if (INFO(pa) != INFO(pb)) same = false;
        pa = NEXT(pa);
        pb = NEXT(pb);
    }

    if (same){
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }

    return 0;
}