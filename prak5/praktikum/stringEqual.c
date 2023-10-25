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
    Word w1,w2;
    int i;
    STARTWORD();
    w1 = currentWord;
    ADVWORD();
    w2 = currentWord;
    printf("Moving "); 
    printWord(w1);
    if (w2.TabWord[4] == 'U'){
        printf(" square upwards\n");
    } else if (w2.TabWord[4] == 'D'){
        printf(" square downwards\n");
        
    } else if (w2.TabWord[4] == 'L'){
        printf(" square leftwards\n");
    
    } else if (w2.TabWord[4] == 'R'){
        printf(" square rightwards\n");

    }
    
    
    

    return 0;
}