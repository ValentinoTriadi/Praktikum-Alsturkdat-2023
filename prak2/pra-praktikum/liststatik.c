#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liststatik.h"


void CreateListStatik(ListStatik *l){
    int i;
    for (i=IDX_MIN; i<CAPACITY; i++){
        ELMT(*l,i) = MARK;
    }
}

int listLength(ListStatik l){
    int i, counter = 0;
    for (i=IDX_MIN; i<CAPACITY; i++){
        if (ELMT(l,i) != MARK) counter++;
    }
    return counter;

}

IdxType getFirstIdx(ListStatik l){
    int i;
    for (i=IDX_MIN; i<CAPACITY; i++){
        if (ELMT(l,i) != MARK) return i;
    }
    return IDX_UNDEF;
}

IdxType getLastIdx(ListStatik l){
    int i;
    for (i=CAPACITY-1; i>=IDX_MIN; i--){
        if (ELMT(l,i) != MARK) return i;
    }
    return IDX_UNDEF;
}

boolean isIdxValid(ListStatik l, IdxType i){
    return (i >= IDX_MIN && i < CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i){
    return (i >= 0 && i < listLength(l));
}

boolean isEmpty(ListStatik l){
    return (listLength(l) == 0);
}

boolean isFull(ListStatik l){
    return (listLength(l) == CAPACITY);
}

void readList(ListStatik *l){
    int n, i;
    scanf("%d", &n);
    while (n< IDX_MIN || n>CAPACITY){
        scanf("%d", &n);
    }

    CreateListStatik(l);
    for (i = 0; i<n; i++) {
        scanf("%d", &ELMT(*l,i));
    }
}

void printList(ListStatik l){
    int i;
    printf("[");
    if (!isEmpty(l)){
        for (i=getFirstIdx(l); i<=getLastIdx(l); i++) {
            printf("%d",ELMT(l,i));
            if (i < getLastIdx(l)) printf(",");
        }
    }
    printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    ListStatik lbaru;
    CreateListStatik(&lbaru);
    int i, firstIDXl1 = getFirstIdx(l1), firstIDXl2 = getFirstIdx(l2);
    if (plus) {
        for (i=0;i<listLength(l1);i++) {
            ELMT(lbaru, i) = ELMT(l1,firstIDXl1+i) + ELMT(l2,firstIDXl2+i);
        } 
    } else {
        for (i=0;i<listLength(l1);i++) {
            ELMT(lbaru, i) = ELMT(l1,firstIDXl1+i) - ELMT(l2,firstIDXl2+i);
        } 
    }
    return lbaru;
}

boolean isListEqual(ListStatik l1, ListStatik l2){
    if (listLength(l1) != listLength(l2)) return false;
    int i, firstIDXl1 = getFirstIdx(l1), firstIDXl2 = getFirstIdx(l2);
    for (i=0; i<listLength(l1); i++) {
        if (ELMT(l1, firstIDXl1+i) != ELMT(l2, firstIDXl2+i)) return false;
    }
    return true;
}

int indexOf(ListStatik l, ElType val){
    int i;
    if (isEmpty(l)) return IDX_UNDEF;
    for (i = getFirstIdx(l); i<=getLastIdx(l);i++) {
        if (ELMT(l,i) == val) return i;
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
    *max = ELMT(l, getFirstIdx(l));
    *min = ELMT(l, getFirstIdx(l));
    int i;
    for (i = getFirstIdx(l); i<=getLastIdx(l); i++) {
        int e = ELMT(l, i);
        if (e < *min) *min = e;
        if (e > *max) *max = e;
    }
}

void insertFirst(ListStatik *l, ElType val){
    int i, fidx = IDX_MIN;
    if (!isEmpty(*l)){
        fidx  = getFirstIdx(*l);
        for (i=getLastIdx(*l); i>= fidx; i--){
            ELMT(*l,i+1) = ELMT(*l,i);
        }
    }
    ELMT(*l, fidx) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    int i;
    if (getLastIdx(*l) < CAPACITY-1){
        for(i=getLastIdx(*l);i>=idx;i--){
            ELMT(*l,i+1) = ELMT(*l,i);
        }
    } else {
        for(i=getFirstIdx(*l);i<=idx;i++){
            ELMT(*l,i-1) = ELMT(*l,i);
        }
    }
    ELMT(*l,idx) = val;
}

void insertLast(ListStatik *l, ElType val){
    ELMT(*l, getLastIdx(*l) + 1) = val;
}

void deleteFirst(ListStatik *l, ElType *val){
    int i, lidx = getLastIdx(*l), fidx = getFirstIdx(*l);
    *val = ELMT(*l, fidx);
    for (i=fidx; i<lidx; i++) {
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    ELMT(*l, lidx) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    int i, lidx = getLastIdx(*l);
    *val = ELMT(*l, idx);
    for (i=idx; i<lidx; i++) {
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    ELMT(*l, lidx) = MARK;
}

void deleteLast(ListStatik *l, ElType *val){
    int lidx = getLastIdx(*l);
    *val = ELMT(*l, lidx);
    ELMT(*l, lidx) = MARK;
}

void sortList(ListStatik *l, boolean asc){
    int i, j, temp;
    if (asc) {
        for (i=getFirstIdx(*l); i<getLastIdx(*l); i++){
            for (j=getLastIdx(*l); j>i; j--){
                if (ELMT(*l,j) < ELMT(*l,j-1)) {
                    temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j-1);
                    ELMT(*l,j-1) = temp;
                }
            }
        }
    } else {
        for (i=getFirstIdx(*l); i<getLastIdx(*l); i++){
            for (j=getLastIdx(*l); j>i; j--){
                if (ELMT(*l,j) > ELMT(*l,j-1)) {
                    temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j-1);
                    ELMT(*l,j-1) = temp;
                }
            }
        }

    }
}
