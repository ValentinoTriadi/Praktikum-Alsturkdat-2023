#include "listrec.h"
#include <stdio.h>

List splitAt (List l, List *l1, List *l2, int idx){
    if (isEmpty(l)){
        return concat(*l1, *l2);
    } else {
        splitAt(tail(l), l1, l2, idx-1);
        if (idx > 0){
            *l1 = konsb(*l1, head(l));
        } else {
            *l2 = konsb(*l2, head(l));
        }
    }
}

int main(){
    int i,n,x;
    List l = NIL;
    List l1 = NIL;
    List l2 = NIL;
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        scanf("%d", &x);
        l = konsb(l,x);
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &x);
        List l1 = NIL;
        List l2 = NIL;
        l = splitAt(l,&l1, &l2, x);
        l = concat(l1,l2);
    }
    displayList(l);
    return 0;
}