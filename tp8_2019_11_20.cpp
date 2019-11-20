#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

/* Calculation of Double Integrals using the Simpson's Method */

float ff(float x, float y) {
    return (x*y)+sin(x);
}

float s(float e, float f, float g, float h) {
    float st_int = 0;
    float x = e;
    float y = g;
    float hx = (f-e)/2;
    float hy = (h-g)/2;

    st_int += ff(x, y) + 4*ff(x+hx, y) + ff(x+2*hx, y);
    st_int += 4*(ff(x, y+hy) + 4*ff(x+hx, y+hy) + ff(x+2*hx, y+hy));
    st_int += ff(x, y+2*hy) + 4*ff(x+hx, y+2*hy) + ff(x+2*hx, y+2*hy); 
    
    return ((hx*hy)/9)*(st_int);
}

float f(float x, float y) {
    return 2;
}

float ss(float a, float b, float c, float d) {
    float st_int = 0;
    float x = a;
    float y = c;
    float hx = (b-a)/2;
    float hy = (d-c)/2;

    st_int += f(x, y) + 4*f(x+hx, y) + f(x+2*hx, y);
    st_int += 4*( f(x, y+hy) + 4*f(x+hx, y+hy) + f(x+2*hx, y+hy) );
    st_int += f(x, y+2*hy) + 4*f(x+hx, y+2*hy) + f(x+2*hx, y+2*hy); 
    
    return ((hx*hy)/9)*(st_int);
}

int main() {
    cout << "\n1) The double integral of 2" << endl;
    cout << "\nThe result of the double integration is 8" << endl;
    cout << "The result of the double integration using the Simpson's Method is: " << ss(0,2,0,2) << endl;
    cout << "Difference: " << abs(ss(0,2,0,2)-8) << endl;

    cout << "\n2) The double integral of x*y+sin(x)" << endl;
    cout << setprecision(10) << "\nThe result of the double integration is " << -2*cos(2)+6 <<  endl;
    cout << setprecision(10) << "The result of the double integration using the Simpson's Method is: " << s(0,2,0,2) << endl;
    cout << setprecision(10) << "Difference: " << abs(s(0,2,0,2)-(-2*cos(2)+6)) << endl;
    return 0;
}
