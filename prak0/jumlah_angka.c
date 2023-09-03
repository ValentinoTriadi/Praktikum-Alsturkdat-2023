#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int sum = 0, angka;
    scanf("%d", &angka);
    while (angka != 0) {
        sum += (angka % 10);
        angka = floor(angka / 10);
    }
    printf("%d\n", sum);
    return 0;
};