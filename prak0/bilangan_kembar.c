#include <stdio.h>
#include <math.h>

#define true 1
#define false 0

int main() {
    int a, b, i, value;
    int sum = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    for (i = a; i<=b; i++) {
        value = 1; // merupakan bilangan kembar
        int angka = i % 10, // satuan
        bilangan = i; // bilangan yang sedang di cek
        while (bilangan != 0) {
            if (bilangan % 10 != angka) value = 0;
            bilangan = floor(bilangan / 10);
        }
        if (value == 1) sum++;
    }

    printf("%d\n", sum);

    return 0;
}

