#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity) {
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType *) malloc (sizeof(ElType) * capacity);
}
void dealocateList(ListDin *l) {
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}
int listLength(ListDin l) {
    return NEFF(l);
}
IdxType getFirstIdx(ListDin l) {
    return IDX_MIN;
}
IdxType getLastIdx(ListDin l) {
    return listLength(l)-1;
}
boolean isIdxValid(ListDin l, IdxType i) {
    return (i >= IDX_MIN && i < (IdxType) CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i) {
    return (i >= IDX_MIN && i < listLength(l));
}
boolean isEmpty(ListDin l) {
    return (listLength(l) == 0);
}
boolean isFull(ListDin l) {
    return (listLength(l) == CAPACITY(l));
}
void readList(ListDin *l) {
    int N;
    IdxType i;
    scanf("%d", &N);
    while (N<0 || N>CAPACITY(*l)){
        scanf("%d", &N);
    }
    NEFF(*l) = N;
    for(i = 0; i < (IdxType) N; i++) {
        scanf("%d", &ELMT(*l,i));
    }
}
void printList(ListDin l) {
    int i;
    printf("[");
    for(i = getFirstIdx(l); i<=getLastIdx(l); i++){
        printf("%d", ELMT(l,i));
        if (i < getLastIdx(l)) printf(",");
    }
    printf("]");
}
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    ListDin L;
    CreateListDin(&L, CAPACITY(l1));
    NEFF(L) = NEFF(l1);
    IdxType i;
    if (plus) {
        for(i=getFirstIdx(l1); i<=getLastIdx(l1); i++) {
            ELMT(L,i) = ELMT(l1,i) + ELMT(l2,i);
        }
    } else {
        for(i=getFirstIdx(l1); i<=getLastIdx(l1); i++) {
            ELMT(L,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }
    return L;
}
boolean isListEqual(ListDin l1, ListDin l2) {
    IdxType i;
    if (listLength(l1) != listLength(l2)) return false;
    for(i=getFirstIdx(l1); i<=listLength(l1); i++){
        if (ELMT(l1,i) != ELMT(l2,i)) {
            return false;
        }
    }
    return true;
}
IdxType indexOf(ListDin l, ElType val) {
    IdxType i;
    if (listLength(l) == 0) return IDX_UNDEF;
    for (i = getFirstIdx(l); i<=getLastIdx(l); i++){
        if (ELMT(l,i) == val) return i;
    }
    return IDX_UNDEF;
}
void extremeValues(ListDin l, ElType *max, ElType *min) {
    *max = ELMT(l, getFirstIdx(l));
    *min = ELMT(l, getFirstIdx(l));
    IdxType i;
    for (i = getFirstIdx(l); i<=getLastIdx(l); i++) {
        if (ELMT(l, i) < *min) *min = ELMT(l, i);
        if (ELMT(l, i) > *max) *max = ELMT(l, i);
    }
}
void copyList(ListDin lIn, ListDin *lOut) {
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    IdxType i;
    for (i=getFirstIdx(lIn); i<=getLastIdx(lIn); i++) {
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
}
ElType sumList(ListDin l) {
    int sum = 0;
    IdxType i;
    if (listLength(l) == 0) return 0;
    for (i=getFirstIdx(l); i<=getLastIdx(l); i++){
        sum += ELMT(l,i);
    }
    return sum;
}
int countVal(ListDin l, ElType val) {
    int count = 0;
    IdxType i;
    for (i=getFirstIdx(l); i<=getLastIdx(l); i++){
        if (ELMT(l,i) == val) count++;
    }
    return count;
}
void sort(ListDin *l, boolean asc) {
    IdxType i, j;
    int temp;
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
void insertLast(ListDin *l, ElType val) {
    ELMT(*l, listLength(*l)) = val;
    NEFF(*l)++;
}
void deleteLast(ListDin *l, ElType *val) {
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l)--;
}
void expandList(ListDin *l, int num) {
    ListDin L;
    copyList(*l, &L);
    dealocateList(l);
    CreateListDin(l, CAPACITY(L)+num);
    NEFF(*l) = NEFF(L);
    IdxType i;
    for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
        ELMT(*l,i) = ELMT(L,i);
    }
}
void shrinkList(ListDin *l, int num){
    ListDin L;
    copyList(*l, &L);
    dealocateList(l);
    CreateListDin(l, CAPACITY(L)-num);
    NEFF(*l) = NEFF(L);
    IdxType i;
    for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
        ELMT(*l,i) = ELMT(L,i);
    }
}
void compressList(ListDin *l) {
    ListDin L;
    copyList(*l, &L);
    dealocateList(l);
    CreateListDin(l, NEFF(L));
    NEFF(*l) = NEFF(L);
    IdxType i;
    for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
        ELMT(*l,i) = ELMT(L,i);
    }
}