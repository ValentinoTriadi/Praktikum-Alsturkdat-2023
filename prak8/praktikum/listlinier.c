#include "listlinier.h"
#include <stdio.h> 
#include <stdlib.h>

Address newNode(ElType val){
    Address p;
    p = (Address) malloc (sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
void CreateList(List *l){
    *l = NULL;
}
boolean isEmpty(List l){
    return (l == NULL);
}
ElType getElmt(List l, int idx){
    Address p = l;
    int  i;
    for (i = 0; i < idx; i++){
        p = NEXT(p);
    }
    return INFO(p);
}
void setElmt(List *l, int idx, ElType val){
    Address p = *l;
    int  i;
    for (i = 0; i < idx; i++){
        p = NEXT(p);
    }
    INFO(p) = val;
}
int indexOf(List l, ElType val){
    if (isEmpty(l)) return IDX_UNDEF;
    Address p = l;
    int idx = 0;
    boolean found = false;
    while (p != NULL && !found){
        if (INFO(p) == val) found = true;
        idx++;
        p = NEXT(p);
    }
    if (found) return idx-1;
    return IDX_UNDEF;
}
void insertFirst(List *l, ElType val){
    Address new = newNode(val);
    if (new != NULL){
        NEXT(new) = *l;
        *l = new;
    }
}
void insertLast(List *l, ElType val){
    Address p = *l;
    Address new = newNode(val);
    if (new != NULL){
        if (p == NULL){
            *l = new;
        } else {
            while (NEXT(p) != NULL){
                p = NEXT(p);
            }
            NEXT(p) = new;
        }
    }
}
void insertAt(List *l, ElType val, int idx){
    Address p = *l;
    int  i;
    Address new = newNode(val);
    if (new != NULL){
        if (idx == 0){
            NEXT(new) = p;
            *l = new;
        } else {
            for (i = 0; i < idx-1; i++){
                p = NEXT(p);
            }
            NEXT(new) = NEXT(p);
            NEXT(p) = new;
        }
    }
}
void deleteFirst(List *l, ElType *val){
    Address p = *l;
    *val = INFO(p);    
    *l = NEXT(p);
    free(p);
}
void deleteLast(List *l, ElType *val){
    Address p = *l;
    int len = length(*l);
    int  i;
    if (len == 1) {
        *val = INFO(*l);
        *l = NULL;
    } else {
        p = *l;
        for (i = 0; i < len-2; i++){
            p = NEXT(p);
        }
        *val = INFO(NEXT(p));
        free(NEXT(p));
        NEXT(p) = NULL;
    }
}
void deleteAt(List *l, int idx, ElType *val){
    Address p = *l, p1;
    int  i;
    if (idx == 0){
        deleteFirst(l,val);
    } else {
        for (i = 0; i < idx-1; i++){
            p = NEXT(p);
        }
        *val = INFO(NEXT(p));
        p1 = NEXT(p);
        NEXT(p) = NEXT(NEXT(p));
        free(p1);
    }

}
void displayList(List l){
    Address p = l;
    int len = length(l);
    int i;
    printf("[");
    for (i = 0; i < len; i++){
        printf("%d", INFO(p));
        p = NEXT(p);
        if (i < len-1) printf(",");
    }
    printf("]");
}
// void printInfo(List l){

// }
int length(List l){
    Address p = l;
    int length = 0;
    while (p != NULL){
        p = NEXT(p);
        length++;
    }
    return length;
}
List concat(List l1, List l2){
    List l;
    CreateList(&l);
    Address p, p1 = l1, p2 = l2;
    int val, i, idx, len;
    len = length(l1);
    for (i = 0; i < len; i++){
        val = INFO(p1);
        // p = l;
        // idx = 0;
        // while (p != NULL && INFO(p) < val){
        //     idx++;
        //     p = NEXT(p);
        // }
        // insertAt(&l,val,idx);
        // p1 = NEXT(p1);
        insertLast(&l,val);
        p1 = NEXT(p1);
    }
    len = length(l2);
    for (i = 0; i < len; i++){
        val = INFO(p2);
        // p = l;
        // idx = 0;
        // while (p != NULL && INFO(p) < val){
        //     idx++;
        //     p = NEXT(p);
        // }
        // insertAt(&l,val,idx);
        // p2 = NEXT(p2);
        insertLast(&l,val);
        p2 = NEXT(p2);
    }
    return l;
}

boolean fSearch(List L, Address P){
    boolean found = false;
    Address p = L;
    while (p!=NULL && !found){
        found = (p == P);
        if (!found){
            p = NEXT(p);
        }
    }
    return found;
}
Address searchPrec(List L, ElType X){
    Address loc = NULL, p = L;
    boolean found = false;
    while (p != NULL && !found){
        found = (INFO(p) == X);
        if (!found){
            loc = p;
            p = NEXT(p);
        }
    }
    if (loc == NULL) return NULL;
    return loc;
}
ElType maxValue(List l){
    int max = INFO(l);
    Address p = NEXT(l);
    while (p != NULL){
        if (INFO(p) > max) max = INFO(p);
        p = NEXT(p);
    }
    return max;
}
Address adrMax(List l){
    return NEXT(searchPrec(l,maxValue(l)));
}
ElType minValue(List l){
    int min = INFO(l);
    Address p = NEXT(l);
    while (p != NULL){
        if (INFO(p) < min) min = INFO(p);
        p = NEXT(p);
    }
    return min;
}
Address adrMin(List l){
    return NEXT(searchPrec(l,minValue(l)));
}
float average(List L){
    int sum = 0;
    Address p = L;
    while (p != NULL){
        sum += INFO(p);
        p = NEXT(p);
    }
    return (float) sum / (float) length(L);
}
void deleteAll(List *l){
    ElType val;
    while (!isEmpty(*l)){
        deleteFirst(l, &val);
    }
}
void copyList(List *l1, List *l2){
    *l2 = *l1;
}
void inverseList(List *l){
    int len = length(*l);
    int i;
    ElType tempval;
    for (i = 0; i<len/2; i++){
        tempval = getElmt(*l, i);
        setElmt(l,i,getElmt(*l,len-1-i));
        setElmt(l,len-1-i,tempval);
    }
}