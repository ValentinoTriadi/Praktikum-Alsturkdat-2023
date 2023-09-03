#include <stdio.h>
#include <math.h>
#include "garis.h"


void CreateGaris (GARIS * L, POINT P1, POINT P2) {
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}
void BacaGARIS (GARIS * L) {
    POINT P1, P2;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    while (EQ(P1, P2)) {
        printf("Garis tidak valid\n");
        BacaPOINT(&P1);
        BacaPOINT(&P2);
    }
    CreateGaris(L, P1, P2);
}
void TulisGARIS (GARIS L) {
    printf("((%.2f,%.2f),(%.2f,%.2f))", Absis(PAwal(L)), Ordinat(PAwal(L)), Absis(PAkhir(L)) ,Ordinat(PAkhir(L)));
}
float PanjangGARIS (GARIS L) {
    return sqrt(pow(Absis(PAwal(L)) - Absis(PAkhir(L)),2) + pow(Ordinat(PAwal(L)) - Ordinat(PAkhir(L)),2));
    // Rumus: ((Y2-Y1)^2 + (X2-X1)^2)^(0.5)
}
float Gradien (GARIS L) {
    return ((Ordinat(PAkhir(L)) - Ordinat(PAwal(L))) / (float)(Absis(PAkhir(L)) - Absis(PAwal(L))));
}
void GeserGARIS (GARIS * L, float deltaX, float deltaY) {
    Absis(PAwal(*L)) += deltaX;
    Absis(PAkhir(*L)) += deltaX;
    Ordinat(PAwal(*L)) += deltaY;
    Ordinat(PAkhir(*L)) += deltaY;
}
boolean IsTegakLurus (GARIS L1, GARIS L2) {
    return (Gradien(L1) == ((-1)/Gradien(L2)));
}
boolean IsSejajar (GARIS L1, GARIS L2) {
    return (Gradien(L1) == Gradien(L2));
}
float JarakGARIS (GARIS L, POINT P) {
    return (sqrt(pow( Gradien(L)*Absis(P) + (-1)*Ordinat(P) + (Ordinat(PAwal(L))-Gradien(L)*Absis(PAwal(L))) ,2)) / sqrt(pow(Gradien(L) ,2) + 1));
}
boolean IsPointMemenuhiGaris (GARIS L, POINT P) {
    int i,j;
    for (i=Absis(PAwal(L)); i<=Absis(PAkhir(L)); i++){
        for (j=Ordinat(PAwal(L)); j<=Ordinat(PAkhir(L)); j++){
            if (Gradien(L)*i - j + (Ordinat(PAwal(L)) - Gradien(L)*Absis(PAwal(L))) == 0) {
                return true;
            }
        }
    }
    return false;
}