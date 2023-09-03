#include <stdio.h>
int main() {
    int n, temp, max1 = 0, max2 = 0, i = 0;
    scanf("%d", &n);

    for(i;i<n;i++) {
        scanf("%d", &temp);
        if (i == 0) {
            max1 = temp;
            max2 = 0;
        }
        if (i == 1) {
            if (temp>max1) {
                max2 = max1;
                max1 = temp;
            } else {
                max2 = temp;
            }
        } else {
            if (temp > max1){
                max2 = max1;
                max1 = temp;
            } else if (temp > max2){
                max2 = temp;
            }
        }
    }
    printf("%d\n", max2);

    return 0;
}
int main() {
    int maks1, maks2;
    int bilangan, i, n;

    scanf("%d", &n);

    for (i = 0; i<n; i++){
        scanf("%d", &bilangan);

        if (bilangan>maks1){
            maks2 = maks1;
            maks1 = bilangan;
        } else if (bilangan>maks2 && bilangan <= maks1){
            maks2=bilangan;
        }
    }
    if (maks2 != -999999){
        printf("%d\n", maks2);
    }
    return 0;
}