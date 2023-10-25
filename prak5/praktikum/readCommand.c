#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"



// Prints word from Mesin Kata
int printWord(Word word) {

   int i;

   for (i = 0; i < word.Length; i++) {

      printf("%c", word.TabWord[i]);

   }

}


int main(){
    Word w;
    w.Length = 0;

    START();
    IgnoreBlanks();
    while (currentChar != MARK){
        w.TabWord[w.Length] = currentChar;
        w.Length++;
        ADV();
    }

    printWord(w);
    printf("\n%d\n", w.Length);
    return 0;
}

