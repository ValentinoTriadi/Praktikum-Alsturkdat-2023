#include <stdio.h>
#include "time.h"

int main(){
    int n, i;
    TIME awal, akhir;
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
        TIME T1, T2;
        long durasi;
        printf("[%d]\n",i);
        BacaTIME(&T1);
        BacaTIME(&T2);
        if (i == 1) {
            if (TLT(T1, T2)) {
                awal = T1;
                akhir = T2;
            } else {
                awal = T2;
                akhir = T1;
            }
        }
        if (TLT(T1,T2)) {
            durasi = Durasi(T1,T2);
            if (TLT(T1,awal)) {
                awal = T1;
            }
            if (TGT(T2,akhir)) {
                akhir = T2;
            }
        } else {
            durasi = Durasi(T2,T1);
            if (TLT(T2,awal)) {
                awal = T2;
            }
            if (TGT(T1,akhir)) {
                akhir = T1;
            }
        }
        printf("%d\n", durasi);
    }
    printf("%d:%d:%d\n", Hour(awal), Minute(awal), Second(awal));
    printf("%d:%d:%d\n", Hour(akhir), Minute(akhir), Second(akhir));
}