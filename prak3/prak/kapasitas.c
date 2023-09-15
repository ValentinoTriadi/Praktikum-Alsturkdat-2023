#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "listdin.h"

int main(){
    int tipe, Q, i;
    ListDin A;
    CreateListDin(&A, 0);
    scanf ("%d",&Q);


    for (i=0; i<Q; i++) {

        scanf("%d",&tipe);

        if(tipe==1){
            int x;
            scanf("%d",&x);

            // proses query tipe 1
            if (CAPACITY(A) == 0) expandList(&A, 1);
            if (isFull(A)) expandList(&A, (CAPACITY(A)));
            insertLast(&A, x);

        }else if(tipe==2){
            // proses query tipe 2
            ElType last;
            deleteLast(&A,&last);
            if (NEFF(A) == 0) shrinkList(&A, 1);
            if (NEFF(A) <= round(CAPACITY(A)/2)) shrinkList(&A, round(CAPACITY(A)/2));

        }else{
            // proses query tipe 3
            printf("%d ", CAPACITY(A));
            printList(A);
            printf("\n");
        }
    }
    return 0;
}