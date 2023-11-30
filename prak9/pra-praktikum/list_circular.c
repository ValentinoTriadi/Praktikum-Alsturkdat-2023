#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

boolean isEmpty(List l){
    return (FIRST(l) == NULL);
}
void CreateList(List *l){
    FIRST(*l) = NULL;
}
Address allocate(ElType val){
    Address p = (Address) malloc (sizeof(ElmtList));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
void deallocate(Address P){
    free(P);
}
Address search(List l, ElType val){
    if (isEmpty(l)) return NULL;
    Address p = FIRST(l);
    boolean found = false;
    while (NEXT(p) != FIRST(l) && !found){
        found = INFO(p) == val;
        if (!found) p = NEXT(p);
    }
    if (INFO(p) == val) return p;
    if (found) return p;
    return NULL;
}
boolean addrSearch(List l, Address p){
    if (isEmpty(l)) return false;
    Address P = FIRST(l);
    boolean found = false;
    while (NEXT(P) != FIRST(l) && !found){
        found = P == p;
        if (!found) P = NEXT(P);
    }
    if (P == p) return true;
    return found;
    
}
void insertFirst(List *l, ElType val){
    Address p = allocate(val);
    Address loc = FIRST(*l);
    if (p != NULL){
        if (isEmpty(*l)){
            FIRST(*l) = p;
            NEXT(p) = FIRST(*l);
        } else {
            NEXT(p) = loc;
            FIRST(*l) = p;
            p = NEXT(p);
            while (NEXT(p) != loc){
                p = NEXT(p);
            }
            NEXT(p) = FIRST(*l);
        }
    }
}
void insertLast(List *l, ElType val){
    Address p = FIRST(*l);
    Address loc = NULL;
    if (isEmpty(*l)) {   
        insertFirst(l,val);
    } else {
        while (NEXT(p) != FIRST(*l)){
            p = NEXT(p);
        }
        NEXT(p) = allocate(val);
        if (NEXT(p) != NULL) {
            NEXT(NEXT(p)) = FIRST(*l);
        } else {
            NEXT(p) = FIRST(*l);
        }
    }
}
void deleteFirst(List *l, ElType * val){
    Address p = FIRST(*l);
    *val = INFO(p);
    if (NEXT(p) == p){
        FIRST(*l) = NULL;
    } else {
        FIRST(*l) = NEXT(p);
        Address loc = FIRST(*l);
        while (NEXT(loc) != p){
            loc = NEXT(loc);
        }
        NEXT(loc) = FIRST(*l);
    }
    deallocate(p);
}
void deleteLast(List *l, ElType * val){
    Address p = FIRST(*l);
    Address loc = NULL;
    while (NEXT(p) != FIRST(*l)){
        loc = p;
        p = NEXT(p);
    }
    *val = INFO(p);
    if (loc == NULL){
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = FIRST(*l);
    }
    deallocate(p);
}
void displayList(List l){
    printf("[");
    Address p = FIRST(l);
    while (NEXT(p)!=FIRST(l)){
        printf("%d,", INFO(p));
        p = NEXT(p);
    }
    if (p != NULL){
        printf("%d", INFO(p));
    }
    printf("]");
}