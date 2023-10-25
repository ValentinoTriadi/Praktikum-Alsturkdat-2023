#include <stdio.h>
#include "stack.h"
#include "wordmachine.h"
#include "charmachine.h"

int charToInt(char x){
    return (x-48);
}

int main(){
    Stack s1,s2,hasil;
    CreateEmpty(&s1);
    CreateEmpty(&s2);
    CreateEmpty(&hasil);
    int i=0, j=0;
    int val1, val2, hitung;
    Word a1, a2;
    

    // baca
    STARTWORD();
    a1 = currentWord;
    ADVWORD();
    a2 = currentWord;

    for (i = 0; i< a1.Length; i++){
        Push(&s1, charToInt(a1.TabWord[i]));
    }
    for (i = 0; i< a2.Length; i++){
        Push(&s2, charToInt(a2.TabWord[i]));
    }

    int sisa = 0;
    while (!IsEmpty(s2)){
        Pop(&s1, &val1);
        Pop(&s2, &val2);
        hitung = val1 - val2 + sisa;
        if (hitung < 0){
            sisa = -1;
            hitung += 10;
        } else {
            sisa = 0;
        }
        Push(&hasil, hitung);
    }
    while (!IsEmpty(s1)){
        Pop(&s1, &val1);
        hitung = val1 + sisa;
        if (hitung < 0){
            sisa = -1;
            hitung += 10;
        } else {
            sisa = 0;
        }
        Push(&hasil, hitung);
    }

    while(InfoTop(hasil) == 0){
        Pop(&hasil, &val1);
    }

    while (!IsEmpty(hasil)){
        Pop(&hasil, &val1);
        printf("%d", val1);
    }
    printf("\n");

    return 0;
}