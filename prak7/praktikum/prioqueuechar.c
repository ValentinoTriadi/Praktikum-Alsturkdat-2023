#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmpty (PrioQueueChar Q){
    return (Head(Q) == Nil && Tail(Q) == Nil);
}
boolean IsFull (PrioQueueChar Q){
    if (Tail(Q) < Head(Q)){
        return (Tail(Q)+1 == Head(Q));
    } else {
        return (Head(Q) == 1 && Tail(Q) == MaxEl(Q));
    }
    return false;

}
int NBElmt (PrioQueueChar Q){
    if (IsEmpty(Q)) return 0;
    if (IsFull(Q)) return MaxEl(Q);
    if (Tail(Q) < Head(Q)){
        return( MaxEl(Q)-Head(Q)+1 + Tail(Q));
    } else {
        return(Tail(Q)-Head(Q)+1);
    }
}
void MakeEmpty (PrioQueueChar * Q, int Max){
    Q->T = (infotype *) malloc ((Max+1) * sizeof(infotype));
    if ((*Q).T){
        MaxEl(*Q) = Max;
    } else {
        MaxEl(*Q) = 0;
    }
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
void DeAlokasi(PrioQueueChar * Q){
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    free(Q->T);
}
void Enqueue (PrioQueueChar * Q, infotype X){
    int i;
    infotype temp;
    if (IsEmpty(*Q)){
        Tail(*Q) = 1;
        Head(*Q) = 1;
    } else if (Tail(*Q) == MaxEl(*Q)-1){
        Tail(*Q) = MaxEl(*Q);
    } else {
        Tail(*Q) = (Tail(*Q) + 1) % (MaxEl(*Q));
    }
    InfoTail(*Q) = X;

    i = Tail(*Q);
    while ((i>0) && (Prio(Elmt(*Q,i-1)) > Prio(Elmt(*Q,i)))){
        temp = Elmt(*Q,i);
        Elmt(*Q, i) = Elmt(*Q, i-1);
        Elmt(*Q, i-1) = temp;
        i--;
    }

}
void Dequeue (PrioQueueChar * Q, infotype * X){
    *X = InfoHead(*Q);
    if (NBElmt(*Q) == 1){
        Tail(*Q) = Nil;
        Head(*Q) = Nil;
    } else if (Head(*Q) == MaxEl(*Q)-1){
        Head(*Q) = MaxEl(*Q);
    } else {
        Head(*Q) = (Head(*Q) + 1) % (MaxEl(*Q));
    }
}
void PrintPrioQueueChar (PrioQueueChar Q){
    int i, len = NBElmt(Q);
    infotype temp;
    for (i = 0; i<len; i++){
        Dequeue(&Q, &temp);
        printf("%d %c\n", Prio(temp), Info(temp));
    }
    printf("#\n");
}