#include "point.h"
#include <stdio.h>
#include <math.h>

void CreatePoint (POINT * P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}
void BacaPOINT (POINT * P){
    float X,Y;
    scanf("%f %f",&X,&Y);
    CreatePoint(P,X,Y);
}
void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}
boolean EQ (POINT P1, POINT P2){
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}
boolean NEQ (POINT P1, POINT P2){
    return (Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2));
}
boolean IsOrigin (POINT P){
    return (Absis(P) == 0 && Ordinat(P) == 0);
}
boolean IsOnSbX (POINT P){
    return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P){
    return (Absis(P) == 0);
}
int Kuadran (POINT P){
    if (Ordinat(P) > 0 && Absis(P) > 0) return 1;
    if (Ordinat(P) > 0 && Absis(P) < 0) return 2;
    if (Ordinat(P) < 0 && Absis(P) < 0) return 3;
    if (Ordinat(P) < 0 && Absis(P) > 0) return 4;
    return 0;
}
POINT NextX (POINT P){
    POINT Pt;
    Absis(Pt) = Absis(P) + 1;
    Ordinat(Pt) = Ordinat(P);
    return Pt;
}
POINT NextY (POINT P){
    POINT Pt;
    Absis(Pt) = Absis(P);
    Ordinat(Pt) = Ordinat(P) + 1;
    return Pt;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
    POINT Pt;
    Absis(Pt) = Absis(P) + deltaX;
    Ordinat(Pt) = Ordinat(P) + deltaY;
    return Pt;
}
POINT MirrorOf (POINT P, boolean SbX){
    POINT Pt;
    Absis(Pt) = Absis(P);
    Ordinat(Pt) = Ordinat(P);
    if (SbX) {
        Ordinat(Pt) *= (-1);
        return Pt;
    }
    Absis(Pt) *= (-1);
    return Pt;
}
float Jarak0 (POINT P){
    return sqrt((Absis(P)*Absis(P)+Ordinat(P)*Ordinat(P)));
}
float Panjang (POINT P1, POINT P2){
    return sqrt((Absis(P1)-Absis(P2))*(Absis(P1)-Absis(P2)) + (Ordinat(P1)-Ordinat(P2))*(Ordinat(P1)-Ordinat(P2)));
}
void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}
void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX){
    if(SbX){
        P -> Y *= -1;
    } else {
        P -> X *= -1;
    }
}
void Putar (POINT *P, float Sudut){
    float rad = (-1) * Sudut * 3.14159265358979323846 / 180.0;
    float cos = cosf(rad);
    float sin = sinf(rad);
    
    float x = (Absis(*P) * cos) - (Ordinat(*P) * sin);
    float y = (Absis(*P) * sin) + (Ordinat(*P) * cos);

    Absis(*P) = x;
    Ordinat(*P) = y;
}
void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
    float a,b;
    if (Absis(P1) == Absis(P2)){
        printf("(1,%.0f)", -round(Absis(P1)));
    } else if (Ordinat(P1) == Ordinat(P2)) {
        printf("(0,%.0f)", round(Ordinat(P1)));
    } else {
        a = (Ordinat(P2)-Ordinat(P1)) / (Absis(P2)-Absis(P1));
        b = Ordinat(P1) - (a*Absis(P1));
        printf("(%.0f,%.0f)", a,b);
    }   
}

