#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

/* Program to find the minimum of a function, using an initial guess interval */

double f(double x) {
	return sin(x)*sin(x);
}

int main() {

    double a = -3.14/2;
    double b = 3.14/2;
    double h = 0.0001;
    
    while (abs(a-b)>h) {
        double c = a + abs(a-b)/3.0;
        double d = b - abs(a-b)/3.0;
        if (f(c) > f(d)) {
            a = c;
        } else {
            b = d;
        }
    }

    cout << setprecision(20) << "The final interval is [" << a << ", " << b << "]" << endl;
    cout << setprecision(20) << "The final interval width is " << abs(a-b) << endl;

    return 0;
}
