#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

// x^2 - 3*x - 5 = 0

double f(double x) {
	return (x * x - 3 * x - 5);
}

double dF(double x) {
	return (2 * x - 3);
}

void formula_resolvente() {
	double x1, x2 = 0;
	x1 = (3 + sqrt(9 + 20)) / 2;
	x2 = (3 - sqrt(9 + 20)) / 2;
	cout << "The result, using the Solving Formula is:" <<endl;
	cout << setprecision(15) << "x1 = " << x1 << ", x2 = " << x2 << endl;
}

void bissection() {
	cout << "\nThe result using the Bisection Method is:" << endl;
	
	double a1 = 5;
	double b1 = 0;
	double c1;
	while (abs(a1-b1) >= 0.001) {
		c1 = (a1 + b1) / 2;
		if (f(a1) * f(c1) < 0) {
			b1 = c1;
		} else { a1 = c1; }
	}
	cout << setprecision(15) << "x1 = " << c1;

	double a2 = 0;
	double b2 = -2;
	double c2;
	while (abs(a2 - b2) >= 0.001) {
		c2 = (a2 + b2) / 2;
		if (f(a2) * f(c2) < 0) {
			b2 = c2;
		}
		else { a2 = c2; }
	}
	cout << setprecision(15) << ", x2 = " << c2 << endl;
}

void false_position() {
	int max = 1000000;
	double c1, a1 = 5, b1 = 0;
	double c2, a2 = 0, b2 = 2;
	for (int i = 0; i < max; i++) {
		// Find the point that touches x axis 
		c1 = (a1 * f(b1) - b1 * f(a1)) / (f(b1) - f(a1));

		// Check if the above found point is root 
		if (f(c1) == 0)
			break;

		// Decide the side to repeat the steps 
		else if (f(c1) * f(a1) < 0)
			b1 = c1;
		else
			a1 = c1;
	}
	for (int i = 0; i < max; i++) {
		// Find the point that touches x axis 
		c2 = (a2 * f(b2) - b2 * f(a2)) / (f(b2) - f(a2));

		// Check if the above found point is root 
		if (f(c2) == 0)
			break;

		// Decide the side to repeat the steps 
		else if (f(c2) * f(a2) < 0)
			b2 = c2;
		else
			a2 = c2;
	}
	cout << "\nThe result using the False Position Method is:" << endl;
	cout << setprecision(15) << "x1 = " << c1 << ", x2 = " << c2 << endl;
}

void newton(double x1, double x2) {
	double e = 0.1;
	double h1 = f(x1) / dF(x1);
	while(abs(h1) >= e) {
		h1 = f(x1) / dF(x1);
		x1 = x1 - h1;
	}

	double h2 = f(x2) / dF(x2);
	while (abs(h2) >= e) {
		h2 = f(x2) / dF(x2);
		x2 = x2 - h2;
	}
	
	double c1 = x1;
	double c2 = x2;
	
	cout << "\nThe result using the Netwon's Method is:" << endl;
	cout << setprecision(15) << "x1 = " << c1 << ", x2 = " << c2 << endl;

}

double g(double x) {
	return (((x * x) - 5) / 3.0);
}

double g1(double x) {
	return (((3 * x) + 5) / x);
}

void picard_peano() {

	double x = 0.0, guess = 0.0;
	cout << "\nWhat is your guess? ";
	cin >> guess;
	x = guess;

	double x_1 = 0.0;
	x_1 = guess;

	for (int i = 0; i <= 50; i++) {
		x = g(x);
	}

	for (int i = 0; i <= 50; i++) {
		x_1 = g1(x_1);
	}
	cout << "\nThe result using the Picard-Peano's Method is:" << endl;
	cout << setprecision(15) << "x1 = " << x_1 << ", x2 = " << x << endl;
}

//2 * x * x - x * y - 5 * x + 1 = 0;
//x + 3*log10(x) - y*y = 0;

int main() { 
	formula_resolvente();
	bissection();
	false_position();
	newton(20, -10);
	picard_peano();
	return 0;
}