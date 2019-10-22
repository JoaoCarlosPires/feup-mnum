#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// f1: 2*x*x - x*y - 5*x + 1
// f2: x + 3log10(x) - y*y 

float kn(float x, float y) {
    return ((-y + 4*x - 5) * (-y*y + 3*log(x) + x) - ((1.304347826086957/x)+1) * (-x*y + 2*x*x - 5*x +1))/(((1.304347826086957/x)+1)*x - 2*(-y + 4*x-5)*y);
}

float hn(float x, float y) {
    return (x*(-y*y + 3*log(x) + x) - 2*y*(-x*y + 2*x*x - 5*x + 1))/(((1.304347826086957/x)+1)*x - 2*(-y + 4*x-5)*y);
}

int main() { 

    /* Program to calculate de solutions of a non-linear system using the Newton's Method 
       The kn and hn functions were previously calculated using Maxima software */

    float x, y;

    x=4.0; 
    y=4.0;

    for (int i = 0; i <= 2; i++) {
        x -= hn(x, y);
        y -= kn(x, y);
    }
    cout << setprecision(12) << "Solution 1:\nx = " << x << ", y = " << y << endl;

    x=1.0;
    y=1.0;

    for (int i = 0; i <= 6; i++) {
        x -= hn(x, y);
        y -= kn(x, y);
    }
    cout << setprecision(12) << "Solution 2:\nx = " << x << ", y = " << y << endl;
    
    return 0;
}