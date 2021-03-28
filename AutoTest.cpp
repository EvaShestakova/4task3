#include "CVector.h"
#include "CVectorHori.h"
void AutoTest() {
    vector<double>a(1);
    vector<double>b(1);
    a[0] = 0;
    b[0] = 1;
    CVectorHori A(a, 1);
    CVectorHori B(b, 1);
    CVectorHori C;
    C = A + B;
    if (C.Vector()[0] == 1) {
        printf("Autotest passed.\n");
    }
    else {
        printf("Autotest failed.\n");
    }
}