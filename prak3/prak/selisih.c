#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "listdin.h"

int main(){
    ListDin L;
    CreateListDin(&L, 100);
    readList(&L);

    ElType max, min;
    extremeValues(L, &max, &min);

    if (listLength(L)==1) max--;
    printf("%d\n", (max-min+1));

    return 0;
}