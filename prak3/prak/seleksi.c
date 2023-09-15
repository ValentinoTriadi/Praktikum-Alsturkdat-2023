#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "listdin.h"

int main(){
    ListDin A, B;
    int c,q,i,j,k, tipe, idxfirst;
    boolean cek;

    scanf("%d", &c);
    CreateListDin(&A, c);
    scanf("%d", &q);

    for(i=0; i<q; i++){
        scanf("%d",&tipe);

        if(tipe==1){
            int x;
            scanf("%d",&x);
            insertLast(&A, x);
            copyList(A, &B);
            sort(&B,true);
            idxfirst = indexOf(B,x);
            if (idxfirst > IDX_MIN) {
                for (j=IDX_MIN; j<idxfirst; j++){
                    int getidx = indexOf(A,ELMT(B,j));
                    for(k=getidx; k < NEFF(A)-1; k++){
                        ELMT(A,k) = ELMT(A,k+1);
                    }
                }
                NEFF(A) -= idxfirst;
            }
        } else {
            printf("%d\n",NEFF(A));
            printList(A);
            printf("\n");
        }
    }

    return 0;
}