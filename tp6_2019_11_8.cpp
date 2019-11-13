#include <iostream>
#include <math.h>

using namespace std;

/* Gauss-Jacobi Method */

// This program calculates the solution of a linear system of linear equations using the Gauss-Jacobi Method

float x1(float x2, float x3) {
    return (7 - x2 - x3)/3;
}

float x2(float x1, float x3) {
    return (4 - x1 - 2*x3)/4;
}

float x3(float x2) {
    return (5 - 2*x2)/5;
}

int main() {
    float ver = 0.00000001;
    
    float x1_k1, x1_k;
    float x2_k1, x2_k;
    float x3_k1, x3_k;

    x1_k = x1(0, 0);
    x2_k = x2(0, 0);
    x3_k = x3(0);
    
    x1_k1 = x1(x2_k, x3_k);
    x2_k1 = x2(x1_k, x3_k);
    x3_k1 = x3(x2_k);

    while ((abs(x1_k1 - x1_k) > ver) && (abs(x2_k1 - x2_k) > ver) && (abs(x2_k1 - x2_k) > ver)) {

        x1_k = x1_k1;
        x2_k = x2_k1;
        x3_k = x3_k1;

        x1_k1 = x1(x2_k, x3_k);
        x2_k1 = x2(x1_k, x3_k);
        x3_k1 = x3(x2_k);
    
    }

    cout << "x1_k1 - x1_k = " << (x1_k1 - x1_k) << endl;
    cout << "x2_k1 - x2_k = " << (x2_k1 - x2_k) << endl;
    cout << "x3_k1 - x3_k = " << (x3_k1 - x3_k) << "\n" << endl;

    cout << "x1_k1 = " << x1_k1 << endl;
    cout << "x2_k1 = " << x2_k1 << endl;
    cout << "x3_k1 = " << x3_k1 << endl; 

    return 0;
}