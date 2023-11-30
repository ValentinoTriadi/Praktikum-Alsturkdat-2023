#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x){
    Address p;
    p = (Address) malloc (sizeof(Node));
    if (p != NULL){
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}
boolean isEmpty(List l){
    return (l == NIL);
}
boolean isOneElmt(List l){
    if (isEmpty(l)) return false;
    return (NEXT(l) == NIL);    
}
ElType head(List l){
    return INFO(l);
}
List tail(List l){
    return NEXT(l);
}
List konso(List l, ElType e){
    Address new = newNode(e);
    if (new != NIL){
        NEXT(new) = l;
        return new;
    }
    return l;
}
List konsb(List l, ElType e){
    if (isEmpty(l)) return newNode(e);
    NEXT(l) = konsb(tail(l), e);
    return l;
}
List copy(List l){
    if (isEmpty(l)) return NIL;
    return konso(copy(tail(l)), head(l));
}
List concat(List l1, List l2){
    if (isEmpty(l1)) return copy(l2);
    return(konso(concat(tail(l1),l2),head(l1)));
}

int length(List l){
    if(isEmpty(l)) return 0;
    return 1 + length(tail(l));
}
boolean isMember(List l, ElType x){
    if (isEmpty(l)) return false;
    return (head(l) == x || isMember(tail(l), x));
}
void displayList(List l){
    if (!isEmpty(l)){
        printf("%d\n",head(l));
        displayList(tail(l));
    }
}

List insertAt(List l, ElType e, int idx){
    if (!idx) return konso(l,e);
    if (isEmpty(l)) return NIL;
    return konso(insertAt(tail(l), e, idx-1), head(l));
}
List deleteFirst(List l){
    Address p = l;
    l = tail(l);
    free(p);
    return l;
}
List deleteAt(List l, int idx){
    if (isEmpty(l)) return NIL;
    if (!idx) {
        List t = tail(l);
        free(l);
        return t;
    }
    return konso(deleteAt(tail(l), idx-1), head(l));
}
List deleteLast(List l){
    if (isOneElmt(l)) {
        free(l);
        return NIL;
    }
    if (length(l) == 2) {
        NEXT(l) = deleteLast(tail(l));
        return l;
    }
    return konso(deleteLast(tail(l)), head(l));
}
List inverseList (List l){
    if (isEmpty(l)) return NIL;
    return konsb(inverseList(tail(l)), head(l));
}
void splitPosNeg (List l, List *l1, List *l2){
    if (isEmpty(l)){
        *l1 = NIL;
        *l2 = NIL;
    } else {
        splitPosNeg(tail(l), l1, l2);
        if (head(l) >= 0){
            *l1 = konso(*l1, head(l));
        } else {
            *l2 = konso(*l2, head(l));
        }
    }
}
void splitOnX (List l, ElType x, List *l1, List *l2){
    if (isEmpty(l)){
        *l1 = NIL;
        *l2 = NIL;
    } else {
        splitOnX(tail(l), x, l1, l2);
        if (head(l) >= x){
            *l2 = konso(*l2, head(l));
        } else {
            *l1 = konso(*l1, head(l));
        }
    }
    
}
List removeDuplicate(List l, List unique){
    if (isEmpty(l)) return NIL;
    if (!isMember(unique, head(l))){
        unique = konso(unique, head(l));
        return konso(removeDuplicate(tail(l), unique), head(l));
    }
    return removeDuplicate(tail(l), unique);
}