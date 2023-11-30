#include "listganda.h"
#include <stdlib.h>

Address newNode(ElType val){
    Address p = (Address) malloc (sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
        PREV(p) = NULL;
    }
}
void createListGanda(ListGanda *l){
    CURRENT(*l) = NULL;
}
boolean isEmpty(ListGanda l){
    return (CURRENT(l) == NULL);
}
boolean isOneElement(ListGanda l){
    return (NEXT(CURRENT(l)) == CURRENT(l) && PREV(CURRENT(l)) == CURRENT(l));
}
int length(ListGanda l){
    if (isEmpty(l)) return 0;
    Address p = CURRENT(l);
    int len = 1;
    while (NEXT(p) != CURRENT(l)){
        len++;
        p = NEXT(p);
    }
    return len;
}
void rotate(ListGanda *l, int k){
    if (isEmpty(*l)) return;
    int i;
    k %= length(*l);
    while(k < 0){
        k+=length(*l);
    }
    // if (k > 0){
        for(i = 0; i<k ; i++){
            CURRENT(*l) == NEXT(CURRENT(*l)); 
        }
    // } else {
    //     for(i = 0; i>k ; i--){
    //         CURRENT(*l) == PREV(CURRENT(*l)); 
    //     }
    // }
}
void insertAfterCurrent(ListGanda *l, ElType x){
    Address p = newNode(x);
    if (p == NULL) return;
    if (isEmpty(*l)){
        CURRENT(*l) = p;
        NEXT(p) = p;
        PREV(p) = p;
    } else {
        PREV(p) = CURRENT(*l);
        NEXT(p) = NEXT(CURRENT(*l));
        NEXT(CURRENT(*l)) = p;
        CURRENT(*l) = p;
    }
}
void deleteCurrent(ListGanda *l, ElType *x){
    Address p = CURRENT(*l);
    *x = INFO(p);
    if (isOneElement(*l)) {
        CURRENT(*l) = NULL;
    } else {
        NEXT(PREV(p)) = NEXT(p);
        PREV(NEXT(p)) = PREV(p);
        CURRENT(*l) = NEXT(p);
    }
    free(p);
}