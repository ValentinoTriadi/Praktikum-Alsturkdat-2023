#include "listrec1.h"
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
    return (l == NULL);
}
boolean isOneElmt(List l){
    if (isEmpty(l)) return 0;
    return (NEXT(l) == NULL);    
}
ElType head(List l){
    return INFO(l);
}
List tail(List l){
    return NEXT(l);
}
List konso(List l, ElType e){
    Address new = newNode(e);
    if (new != NULL){
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
    if (isEmpty(l)) return NULL;
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

ElType maxList (List l){
    if (isOneElmt(l)) return head(l);
    if (head(l) > maxList(tail(l))) return head(l);
    return maxList(tail(l));
}
ElType minList (List l){
    if (isOneElmt(l)) return head(l);
    if (head(l) < maxList(tail(l))) return head(l);
    return maxList(tail(l));
}
ElType sumList (List l){
    if(isOneElmt(l)) return head(l);
    return head(l) + sumList(tail(l));
}
float averageList (List l){
    return (float) sumList(l) / (float) length(l);
}
List inverseList (List l){
    if(isEmpty(l)) return NULL;
    return konsb(inverseList(tail(l)), head(l));
}
void splitPosNeg (List l, List *l1, List *l2){
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    } else {
        splitPosNeg(tail(l), l1, l2);
        if (head(l) >= 0){
            *l1 = konso(*l1,head(l));
        } else {
            *l2 = konso(*l2,head(l));
        }
    }
}
void splitOnX (List l, ElType x, List *l1, List *l2){
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    } else {
        splitOnX(tail(l),x, l1, l2);
        if (head(l) >= x){
            *l2 = konso(*l2,head(l));
        } else {
            *l1 = konso(*l1,head(l));
        }
    }
    
}
int compareList (List l1, List l2){
    if (isEmpty(l1) && isEmpty(l2)) {
        return 0;
    } else if (isEmpty(l1) && !isEmpty(l2)) {
        return -1;
    } else if (!isEmpty(l1) && isEmpty(l2)) {
        return 1;
    } else if (head(l1) < head(l2)) {
        return -1;
    } else if (head(l1) > head(l2)) {
        return 1;
    } else {
        return compareList(tail(l1), tail(l2));
    }
}
boolean isAllExist (List l1, List l2){
    if (isEmpty(l1)) return true;
    return (isMember(l2,head(l1)) && isAllExist(tail(l1), l2));
}