#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

Address newNode(ElType x){
    Address P = (Address) malloc(sizeof(Node));
    if(P != NULL){
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}

boolean isEmpty(List l){
    return l == NULL;
}

boolean isOneElmt(List l){
    if (isEmpty(l)) return false;
    return NEXT(l) == NULL;
}

ElType head(List l){
    return INFO(l);
}

List tail(List l){
    return NEXT(l);
}

List konso(List l, ElType e){
    Address P = newNode(e);
    if(P != NULL){
        NEXT(P) = l;
        l = P;
    }
    return l;
}

List konsb(List l, ElType e){
    Address P = newNode(e);
    if(P != NULL){
        if(isEmpty(l)){
            l = P;
        }else{
            NEXT(tail(l)) = P;
        }
    }
    return l;
}

List copy(List l){
    if(isEmpty(l)){
        return NULL;
    }else{
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2){
    if(isEmpty(l1)){
        return copy(l2);
    }else{
        return konso(concat(tail(l1), l2), head(l1));
    }
}

int length(List l){
    if(isEmpty(l)){
        return 0;
    }else{
        return 1 + length(tail(l));
    }   
}

boolean isMember(List l, ElType x){
    if(isEmpty(l)){
        return false;
    }else{
        if(head(l) == x){
            return true;
        }else{
            return isMember(tail(l), x);
        }
    }
}

void displayList(List l){
    if (!isEmpty(l)) {
        printf("%d", head(l));
        List temp = tail(l);
        while (!isEmpty(temp))
        {
            printf("\n%d", head(temp));
            temp = tail(temp);
        }
        printf("\n");
    }
}
