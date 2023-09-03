#include <stdio.h>
#include <math.h>
#include "datetime.h"

int GetMaxDay(int M, int Y) {
    if (M % 2 == 1) {
        return (M < 8) ? 31 : 30;
    }
    if (M != 2){
        return (M < 7) ? 30 : 31;
    }
    if (Y % 400 == 0) {
        return 29;
    }
    if (Y % 100 == 0) {
        return 28;
    }
    if (Y % 4 == 0) {
        return 29;
    }
    return 28;
}
boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s) {
    if (Y<0) {return false;}
    if (M>12 || M<1) {return false;}
    if (D > GetMaxDay(M,Y) || D<1) {return false;}
    if (!IsTIMEValid(h,m,s)) {return false;}
    return true;
}
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss) {
    TIME T;
    CreateTime(&T, hh,mm,ss);
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    Time(*D) = T;
}
void BacaDATETIME(DATETIME *D) {
    int DD, MM, YYYY, hh, mm, ss;
    scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
    while (!IsDATETIMEValid(DD,MM,YYYY,hh,mm,ss)) {
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
    }
    CreateDATETIME(D,DD,MM,YYYY,hh,mm,ss);  
}

void TulisDATETIME(DATETIME D) {
    printf("%d/%d/%d %d:%d:%d\n", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}
boolean DEQ(DATETIME D1, DATETIME D2) {
    return (Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && Hour(Time(D1)) == Hour(Time(D2)) && Minute(Time(D1)) == Minute(Time(D2)) && Second(Time(D1)) == Second(Time(D2)));
}
boolean DNEQ(DATETIME D1, DATETIME D2){
    return !(Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && Hour(Time(D1)) == Hour(Time(D2)) && Minute(Time(D1)) == Minute(Time(D2)) && Second(Time(D1)) == Second(Time(D2)));
}
boolean DLT(DATETIME D1, DATETIME D2) {
    if (Year(D1) < Year(D2)) {
        return true;
    } else if (Year(D1) == Year(D2)) {
        if (Month(D1) < Month(D2)) {
            return true;
        } else if (Month(D1) == Month(D2)) {
            if (Day(D1) < Day(D2)) {
                return true;
            } else if (Day(D1) == Day(D2)) {
                if (TLT(Time(D1),Time(D2))) {
                    return true;
                }
            }
        }
    }
    return false;
}
boolean DGT(DATETIME D1, DATETIME D2){
    if (Year(D1) > Year(D2)) {
        return true;
    } else if (Year(D1) == Year(D2)) {
        if (Month(D1) > Month(D2)) {
            return true;
        } else if (Month(D1) == Month(D2)) {
            if (Day(D1) > Day(D2)) {
                return true;
            } else if (Day(D1) == Day(D2)) {
                if (TGT(Time(D1),Time(D2))) {
                    return true;
                }
            }
        }
    }
    return false;
}
DATETIME DATETIMENextNDetik(DATETIME D, int N) {
    long s;
    s = TIMEToDetik(Time(D));
    s += N;
    if (s >= 86400){
        Day(D) += floor(s/86400);
        s %= 86400;
        Time(D) = DetikToTIME(s);
        while (Day(D) > GetMaxDay(Month(D), Year(D))){
            Day(D) -= GetMaxDay(Month(D), Year(D));
            Month(D) += 1;
            if (Month(D) > 12){
                Year(D) += 1;
                Month(D) = 1;
            }
        }
    }
    return D;
}
DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
    long s;
    s = TIMEToDetik(Time(D));
    s -= N;
    if (s<0){
        Day(D) += floor(s/86400);
        s %= 86400;
        if (s < 0){
            Day(D) -= 1;
            s += 86400;
        } 
        Time(D) = DetikToTIME(s);
        while (Day(D) < 1){
            if (Month(D) == 1){
                Year(D) -= 1;
                Month(D) = 12;
            } else {
                Month(D) -= 1;
            }
            Day(D) += GetMaxDay(Month(D), Year(D));
        }
    }
    return D;
}
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh){
    long int Sakh, Saw;
    long Dday = 0;
    int i, j;
    for (i=Year(DAw); i<Year(DAkh); i++){
        j = 0;
        if (i % 400 == 0) {
            j = 1;
        }
        if (i % 100 == 0) {
            j = 0;
        }
        if (i % 4 == 0) {
            j = 1;
        }
        if (j == 1) {
            Dday += 366;
        } else {
            Dday += 365;
        }
    }
    for (i=1; i<Month(DAw); i++){
        if (i % 2 == 1) {
            Saw += (i < 8) ? 31 : 30;
        } else {
            if (i != 2){
                Saw += (i < 7) ? 30 : 31;
            } else {
                if (Year(DAw) % 400 == 0) {
                    Saw += 29;
                } else if (Year(DAw) % 100 == 0) {
                    Saw += 28;
                } else if (Year(DAw) % 4 == 0) {
                    Saw += 29;
                } else {
                    Saw += 28;
                }
            }
        }
    }
    for (i=1; i<Month(DAkh); i++){
        if (i % 2 == 1) {
            Sakh += (i < 8) ? 31 : 30;
        } else {
            if (i != 2){
                Sakh += (i < 7) ? 30 : 31;
            } else {
                if (Year(DAkh) % 400 == 0) {
                    Sakh += 29;
                } else if (Year(DAkh) % 100 == 0) {
                    Sakh += 28;
                } else if (Year(DAkh) % 4 == 0) {
                    Sakh += 29;
                } else {
                    Sakh += 28;
                }
            }
        }
    }
    Sakh += Day(DAkh);
    Saw += Day(DAw);
    Dday += (Sakh-Saw);
    return (Dday*86400 + Durasi(Time(DAw), Time(DAkh)));
}