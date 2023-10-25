#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

boolean cekAnagram(Word w1, Word w2){
    int i,j;
    boolean isAnagram = false, tempword;
    for (i = 0; i<w1.Length; i++){
        tempword = false;
        for (j=0; j<w2.Length; j++){
            if (w1.TabWord[i] == w2.TabWord[j]){
                tempword = true;
                w2.TabWord[j] = MARK;
            }
        }
        if (!tempword) return false;
    }
    return true;
}

int main(){
    Word arrWord[100];
    int countWord = 0, countAnagram = 0, i, j;
    boolean isAnagram;
    STARTWORD();
    while (!EndWord) {
        arrWord[countWord] = currentWord;
        countWord++;
        ADVWORD();
    }
    for (i = 0; i<countWord-1; i++){
        for (j=i+1; j<countWord; j++){
            isAnagram = false;
            if (i != j){
                if (arrWord[i].Length == arrWord[j].Length){
                    isAnagram = cekAnagram(arrWord[i], arrWord[j]);
                }
            }
            if (isAnagram) countAnagram++;
        }
    }
    printf("%d\n", countAnagram);
    return 0;
}