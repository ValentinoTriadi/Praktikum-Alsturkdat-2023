#include <stdio.h>
#include <math.h>
#include "matrix.h"

int main(){
    int N,M,K,i,j,x,y,a,b,sum=0,max=0;
    scanf("%d %d %d", &N,&M,&K);
    Matrix m;
    readMatrix(&m,N,M);
    
    for (x=1; x<=N; x++){
        for (y=1; y<=M; y++){
            if(x*y == K){
                for(a=0; a<=N-x; a++){
                    for(b=0; b<=M-y;b++){
                        sum = 0;
                        for(i=a; i<a+x; i++){
                            for(j=b; j<b+y;j++){
                                sum+=ELMT(m,i,j);
                            }
                        }
                        if(sum>max) max = sum;
                    }
                }
            }
        }
    }
    printf("%d\n",max);
    return 0;
}