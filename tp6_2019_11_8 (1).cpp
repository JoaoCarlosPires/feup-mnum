#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

/* Trapezoids's Method and Simpson's Method */

/*
float f(float a, float b, float i, float n) {
    return sin(a+i*((((b-a)/n)/3)))/((a+i*((((b-a)/n)/3)))*(a+i*((((b-a)/n)/3))));
}
*/

float fx(float x) {
    return sin(x)/(x*x);
}

float st(float a, float b, int n) {
    float st_int = 0;
    float x = a;
    float h = (b-a)/n;
    for (int i = 0; i <= n; i++) {
        if (i==0 || i == n) {
        st_int += fx(x);
        } else {
            st_int += 2*fx(x);
        }
        x += h;
    }

    return (h/2)*(st_int);
}

float ss(float a, float b, int n) {
    float st_int;
    float x = a;
    float h = (b-a)/n;
    for (int i = 0; i <= n; i++) {
        if (i==0 || i == n) {
            st_int += fx(x);
        } else if (i%2==0) {
            st_int += 2*fx(x);
        } else {
            st_int += 4*fx(x);
        }
        x+=h;
    } 
    
    return (h/3)*(st_int);
}

int main() {

    const double PI = atan(1.0)*4;

    float a = PI/2;
    float b = PI;

    float real_value = 0.2382870329744382;

    cout << "To n=4:" << endl;
    cout << "Trapezoids's Method: " << setprecision(17) << st(a, b, 4) << endl;
    cout << "Simpson's Method: " << setprecision(17) << ss(a, b, 4) << endl;
    cout << "Error TM: " << setprecision(17) << abs(real_value-st(a, b, 4)) << endl;
    cout << "Error SM: " << setprecision(17) << abs(real_value-ss(a, b, 4)) << endl;

    cout << "\nTo n=8:" << endl;
    cout << "Trapezoids's Method: " << setprecision(17) << st(a, b, 8) << endl;
    cout << "Simpson's Method: " << setprecision(17) << ss(a, b, 8) << endl;
    cout << "Error TM: " << setprecision(17) << abs(real_value - st(a, b, 8)) << endl;
    cout << "Error SM: " << setprecision(17) << abs(real_value - ss(a, b, 8)) << endl;

    cout << "\nTo n=16:" << endl;
    cout << "Trapezoids's Method: " << setprecision(17) << st(a, b, 16) << endl;
    cout << "Simpson's Method: " << setprecision(17) << ss(a, b, 16) << endl;
    cout << "Error TM: " << setprecision(17) << abs(real_value - st(a, b, 16)) << endl;
    cout << "Error SM: " << setprecision(17) << abs(real_value - ss(a, b, 16)) << endl;

    return 0;
}