#include <stdio.h>
#include "stack.h"

int main(){

    int x;
    scanf("%d",&x);
    Stack s;
    CreateEmpty(&s);
    Push(&s,x);
    int counter = 0; 
    while (!IsEmpty(s))
    {
        int temp;
        Pop(&s,&temp);
        printf("fibonacci(%d)\n",temp);
        if(temp == 1){
            counter++;
        }
        else if(temp == 0){
            counter+=0;
        }
        else{
            Push(&s,temp-2);
            Push(&s,temp-1);
        }
    }
    printf("%d\n",counter);
    
    return 0;
}