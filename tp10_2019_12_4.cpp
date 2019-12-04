#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

/* RK2 Method to solve the equation x^2 for a given value of x
Program based on http://www.cplusplus.com/forum/beginner/56379/ */

double f(double x) {
	return x * x;
}

void RK(double X, double h, double x0, double y0) {
	vector<double> x, y;
	double k[4];

	x.push_back(x0);
	y.push_back(y0);

	for (int i = 1; i <= X / h; i++) {
		x.push_back((i-1) * h);
	}

	for (int i = 1; i <= X / h; i++) {
		k[1] = h * f(x[i-1]);
		k[2] = h * f(x[i-1] + 0.5 * h);
		k[3] = h * f(x[i-1] + 0.5 * h);
		k[4] = h * f(x[i-1] + h);
		y.push_back(y[i-1] + (1.0 / 6) * (k[1] + 2 * k[2] + 2 * k[3] + k[4]));
		if (i == (X / h)) { cout << y[i]; }
	}

}

int main() {

	double x0 = -2;
	double y0 = -5.0 / 3;
	double X = 25;
	double h = 0.01;

    RK(X, h, x0, y0);
	return 0;
}