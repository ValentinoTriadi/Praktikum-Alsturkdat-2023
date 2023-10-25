#include "prioqueue.c"
#include <stdio.h>

// int main(){
//     int n, count = 1, countenqueue = 0;
//     int T, I, M, D;
//     ElType temp, sedangDilayani;
//     PrioQueue q;
//     CreatePrioQueue(&q);
//     boolean isDone = true, isOff = false;
//     scanf("%d", &n);
//     do {
//         scanf("%d %d %d %d", &T, &I, &M, &D);
//         temp.tArrival = T;
//         temp.id = I;
//         temp.score = M;
//         temp.dService = D;
//         if (countenqueue < n){
//             enqueue(&q, temp);
//             countenqueue++;
//         } 
//         if(isDone){
//             dequeue(&q,&sedangDilayani);
//             isDone = false;
//             printf("%d %d %d\n", count, sedangDilayani.id, count-sedangDilayani.tArrival);
//         }
//         if(!isDone){
//             sedangDilayani.dService--;
//         }
//         if(!sedangDilayani.dService){
//             isDone = true;
//         }
//         count++;
//         if (countenqueue == n){
//             if (isEmpty(q)) isOff = true;
//         }
//     } while (!isOff);
//     return 0;
// }


// int main() {
//     int n, count = 1, countarr = 0;
//     int T, I, M, D;
//     ElType temp, sedangDilayani;
//     PrioQueue q;
//     CreatePrioQueue(&q);
//     boolean isDone = true;
//     scanf("%d", &n);
//     ElType arr[n];
//     for(n; n>0; n--){
//         scanf("%d %d %d %d", &T, &I, &M, &D);
//         temp.tArrival = T;
//         temp.id = I;
//         temp.score = M;
//         temp.dService = D;
//         enqueue(&q, temp);
//     }
//     while (!isEmpty(q)){
//         if (isDone) {
//             dequeue(&q, &sedangDilayani);
//             isDone = false;
//             temp = sedangDilayani;
//             temp.dService = count - temp.tArrival;
//             temp.tArrival = count;
//             arr[countarr] = temp;
//             countarr++;
//         } 
//         if (!isDone) {
//             sedangDilayani.dService--;
//         }
//         if (!sedangDilayani.dService) isDone = true;
//         count++;
//     }

//     for(n = 0; n < countarr; n++){
//         printf("%d %d %d\n", arr[n].tArrival, arr[n].id, arr[n].dService);
//     }
//     return 0;
// }

int main() {
    int n, i, t = 1, countarr = 0, tempservice;
    int T, I, M, D;
    ElType temp, sedangDilayani;
    PrioQueue q;
    CreatePrioQueue(&q);
    boolean isDone = true, isStop = false;
    scanf("%d", &n);
    if (!n){
        printf("Tidak ada layanan\n");
    } else {
        ElType arr[n];
        for(i = 0; i<n; i++){
            scanf("%d %d %d %d", &arr[i].tArrival, &arr[i].id, &arr[i].score, &arr[i].dService);
        }

        while (!isStop){
            if (countarr < n && arr[countarr].tArrival == t){
                enqueue(&q, arr[countarr]);
                countarr++;
            }
            if (isDone && !isEmpty(q)){
                dequeue(&q,&sedangDilayani);
                tempservice = sedangDilayani.dService; 
                printf("%d %d %d\n", t, sedangDilayani.id, t - sedangDilayani.tArrival);
                isDone = false;
            }
            if (!isDone) tempservice--;
            if (!tempservice && !isDone){
                isDone = true;
            }
            if (countarr == n && !tempservice){
                if (isEmpty(q)) isStop = true;
            }
            t++;
        }

    }
    return 0;
}