#include <stdio.h>
int main() {
    int a, b, i;
    int sum = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    for (i = a; i<=b; i++) {
        if (i % 11 == 0 && i > 10 && i<100) {
            sum++;
        } else if (i % 111 == 0 && i > 100 && i<1000) {
            sum++;
        } else if (i % 111 == 0 && i > 1000 && i<10000) {
            sum++;
        } else if (i % 111 == 0 && i > 10000 && i<100000) {
            sum++;
        }
    }
    printf("%d\n", sum);

    return 0;
}
