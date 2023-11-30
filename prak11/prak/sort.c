#include "sort.h"
#include <stdlib.h>

Address findMiddle(List l){
    int mid;
    if (length(l) % 2 == 1){
        mid = length(l)/2;
    } else {
        mid = length(l)/2;
        mid--;
    }
    Address p = l;
    while (mid != 0){
        p = NEXT(p);
        mid--;
    }
    return p;
// 1 2
}
List merge(List l1, List l2){
    
}
List mergeSort(List l){
    if (isEmpty(l) || isOneElmt(l)) return l;
    Address m = findMiddle(l);
    Address p = l;
    List l1 = NULL, l2 = NULL;
    while (p != m){
        l1 = konsb(l1, INFO(p));
        p = NEXT(p);
    }
    l1 = konsb(l1, INFO(p));
    p = NEXT(p);
    while(p != NIL){
        l2 = konsb(l2, INFO(p));
        p = NEXT(p);
    }
    return merge(l1,l2);
}
ElType max(List l){
    if (isEmpty(l)) return 0;
    if (isOneElmt(l)) return head(l);
    if (head(l) >= max(tail(l))) return head(l); 
    return max(tail(l));
}
ElType min(List l){
    if (isEmpty(l)) return 0;
    if (isOneElmt(l)) return head(l);
    if (head(l) <= min(tail(l))) return head(l); 
    return min(tail(l));
}
int indexOf(List l, ElType x){
    Address p = l;
    int idx = 0;
    while(p != NIL && INFO(p) != x){
        p = NEXT(p);
        idx++;
    }
    return idx;
}
List deleteIDX(List l, int idx){
    if (isEmpty(l)) return NIL;
    if (!idx) {
        List t = tail(l);
        free(l);
        return t;
    }
    return konso(deleteIDX(tail(l), idx-1), head(l));
}
List zigZagSort(List l){
    if (isEmpty(l)) return NIL;
    if (isOneElmt(l)) return l;
    List zigzag = NIL;
    List isi = copy(l);
    while (!isEmpty(isi) && !isOneElmt(isi)){
        zigzag = konsb(zigzag, max(isi));
        int idx = indexOf(isi,max(isi));
        isi = deleteIDX(isi, idx);
        zigzag = konsb(zigzag, min(isi));
        idx = indexOf(isi,min(isi));
        isi = deleteIDX(isi, idx);
    }
    if (isOneElmt(isi)) zigzag = konsb(zigzag, INFO(isi));
    return zigzag;
    //6 9
}
