#include <stdio.h>
#include "wordmachine.c"
#include "charmachine.c"

int main() {
    int jumlah = 0, count = 0;

    STARTWORD();
    while (!EndWord){
        jumlah += currentWord.Length;
        count++;
        ADVWORD();
    }
    if (count != 0){
        printf("%d %d %d", jumlah, count, jumlah/count);
    } else {
        printf("Tidak terdefinisi");
    }
    return 0;
}