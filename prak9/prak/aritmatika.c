#include <stdio.h>
#include "list_circular.h"

int main(){
    int n, i;
    int x;
    int a = -9999, b=-9999;
    boolean isTrue = true;
    scanf("%d", &n);
    List l;
    CreateList(&l);
    for (i=0; i<n; i++){
        scanf("%d", &x);
        insertLast(&l, x);
    }
    Address p = FIRST(l);
    for (i = 1; i<=n; i++){
        x = INFO(p);
        if (i == 1){
            b = x;
        } else if (i == 2) {
            a = x-b;
        } else {
            if ((a*(i-1))+b != x){
                isTrue = false;
                break;
            }
        }
        p = NEXT(p);
    }
    if (isTrue){
        printf("%d %d\n", a,b);
    } else {
        printf("0 0\n");
    }
    return 0;
}