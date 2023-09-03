#include <stdio.h>
int main() {
    int M, N;
    int i = 1;
    scanf("%d", &M);
    scanf("%d", &N);

    while (i<=M) {
        if (i % N == 0) {
            printf("happy\n");
        } else {
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}