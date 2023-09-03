#include <stdio.h>
#include <math.h>
#include "point.h"
#include "garis.h"

int main() {
    int b, n, i, total = 0;
    POINT P1, P2;
    GARIS L;

    scanf("%d", &b);
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    CreateGaris(&L, P1, P2);
    scanf("%d", &n);
    for (i = 0; i<n; i++){
        POINT B;
        BacaPOINT(&B);
        if (JarakGARIS(L,B) < b){
            total += 1;
        }
    }
    printf("%d\n",total);
    return 0;
}