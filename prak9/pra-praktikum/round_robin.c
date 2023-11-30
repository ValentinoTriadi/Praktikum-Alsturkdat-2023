#include "list_circular.h"
#include <stdio.h>

void deleteRR(List *l, ElType tQ)
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika INFO(last) > tQ, maka last "diantrikan" kembali sebagai first elemen dengan INFO(last) = INFO(last) - tQ
- jika INFO(last) <= tQ, maka deleteLast(l, x) dan menampilkan x ke layar */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
l terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai dengan aturan round-robin
l mungkin menjadi kosong. */
{
    if (isEmpty(*l)) {
        printf("List kosong\n");
        return;
    }
    Address Last = FIRST(*l);
    ElType lama;
    while (NEXT(Last) != FIRST(*l)){
        Last = NEXT(Last);
    }

    if (INFO(Last) > tQ){
        INFO(Last) -= tQ;
        FIRST(*l) = Last;
        lama = tQ;
    } else {
        deleteLast(l, &lama);
    }   
    printf("%d\n", lama);
}

float average(List l)
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong */
{
    Address p = FIRST(l);
    int sum = 0;
    int count = 0;
    while (NEXT(p) != FIRST(l)){
        sum += INFO(p);
        count++;
        p = NEXT(p);
    }
    sum += INFO(p);
    count++;
    return (float) ((float)sum / (float)count);
}

int main(){
    List l;
    CreateList(&l);
    ElType e;
    int tq = -1;
    char cmd;
    do {
        scanf("%d", &tq);
    } while (tq <= 0);

    do {
        scanf(" %c", &cmd);
        if (cmd == 'A'){
            scanf("%d", &e);
            if (e > 0) insertFirst(&l,e);
        } else if (cmd == 'D'){
            deleteRR(&l, tq);
        } else if (cmd == 'F'){
            if (isEmpty(l)){
                printf("Proses selesai\n");
            } else {
                printf("%.2f\n", average(l));
            }
        } else {
            printf("Kode salah\n");
        }
    } while (cmd != 'F');

    return 0;
}