#include <stdio.h>
#include "stack.h"
#include "charmachine.h"
#include "wordmachine.h"

void readWord(Word *input) {
    int i;
    START();
    IgnoreBlanks();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV();
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}

int main(){
    int i, temp, count=0, maxcount = 0;
    boolean condition = true;
    Word s;
    readWord(&s);
    Stack p;
    CreateEmpty(&p);
    for(i = 0; i<s.Length; i++){
        if (s.TabWord[i] == '(') {
            Push(&p, s.TabWord[i]);
        } else {
            if (IsEmpty(p)) {
                condition = false;
                break;
            } else {
                count = Top(p) + 1;
                Pop(&p, &temp);
                if (count > maxcount) maxcount = count;
                count = 0;
            }
        }
    }
    if (!condition || !IsEmpty(p)){
        printf("-1\n");
    } else {
        printf("%d\n", maxcount);
    }
}