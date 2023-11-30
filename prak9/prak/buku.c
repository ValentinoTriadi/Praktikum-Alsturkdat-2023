#include <stdio.h>
#include "list_circular.h"

int main(){
    int n, i, a, j;
    scanf("%d", &n);
    List l;
    CreateList(&l);
    for(i = 0; i<n; i++){
        insertLast(&l, i+1);
    }
    Address p = FIRST(l), loc = NULL;
    for(i = 1; i < n; i++){
        scanf("%d", &a);
        if (a < 0){
            while (a < 0){
                a += n-i+1;
            }
            if (i != 1) a++;
        }
        for (j = 0; j<a; j++){
            if (j == 0 && i != 1){
                NEXT(loc) = NEXT(p);
                deallocate(p);
                p = NEXT(loc);
            } else if (j == 0 && i == 1){
                loc = p;
                p = NEXT(p);
            } else {
                loc = p;
                p = NEXT(p);
            }
        }
    }
    printf("%d\n", INFO(NEXT(p)));
}


// 1 2 3 4 5

// i = 1;
// a = 5