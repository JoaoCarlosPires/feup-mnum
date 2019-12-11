#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double f(double x) {
    return sin(x)*sin(x);
}

int main() {
    double a = 0;
    double b = 2*M_PI;
    double B = (sqrt(5)-1)/2;
    double c = b - B*(b-a);
    double fc = f(c);
    double d = a + B*(b-a);
    double fd = f(d);
    double prec = 0.01;

    while (abs(b-a) > prec) {
        if (fc > fd) {
            a = c;
            c = d;
            fc = fd;
            d = a + B*(b-a);
            fd = f(d);
        } else {
            b = d;
            d = c;
            fd = fc;
            c = b - B*(b-a);
            fc = f(c);
        }
    }

    cout << setprecision(10) << "c = " << c << "; f(c) = " << fc << endl;
    cout << setprecision(10) << "d = " << d << "; f(d) = " << fd << endl;


    return 0;
}