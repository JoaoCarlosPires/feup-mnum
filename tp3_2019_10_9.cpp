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

void solving_formula() {
	/* Finding the roots using the solving formula */
	double x1, x2 = 0;
	x1 = (3 + sqrt(9 + 20)) / 2;
	x2 = (3 - sqrt(9 + 20)) / 2;
	cout << "The result, using the Solving Formula is:" <<endl;
	cout << setprecision(15) << "x1 = " << x1 << ", x2 = " << x2 << endl;
}

void bissection() {
	cout << "\nThe result using the Bisection Method is:" << endl;
	
	/* Finding the 1st root */
	double a1 = 5;
	double b1 = 0;
	double c1;
	while (abs(a1-b1) >= 0.001) { // while the interval is bigger or equal than 0.001, the bissection method is applied
		c1 = (a1 + b1) / 2;
		if (f(a1) * f(c1) < 0) { // the interval changes from [a,b] to [a,c]
			b1 = c1;
		} else { a1 = c1; } // the interval changes from [a,b] to [c,b]
	}
	cout << setprecision(15) << "x1 = " << c1;

	/* Finding the 2nd root using the same technique but different values for a(a2) and b(b2) */
	double a2 = 0;
	double b2 = -2;
	double c2;
	while (abs(a2 - b2) >= 0.001) { // while the interval is bigger or equal than 0.001, the bissection method is applied
		c2 = (a2 + b2) / 2;
		if (f(a2) * f(c2) < 0) { // the interval changes from [a,b] to [a,c]
			b2 = c2;
		}
		else { a2 = c2; } // the interval changes from [a,b] to [c,b]
	}
	cout << setprecision(15) << ", x2 = " << c2 << endl;
}

void false_position() {

	double c1, a1 = 5, b1 = 0;
	double c2, a2 = 0, b2 = 2;

	/* 1st solution */
	for (int i = 0; i < 1000000; i++) {
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
	
	/* 2nd solution */
	for (int i = 0; i < 1000000; i++) {
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

	/* Receiving two initial values (guesses), uses the Newton's Method to get the two roots */
	
	double e = 0.1;
	
	double h1 = f(x1) / dF(x1);
	
	while(abs(h1) >= e) { // stops when the h1 value is less than the error
		h1 = f(x1) / dF(x1);
		x1 -= h1;
	}

	double h2 = f(x2) / dF(x2);
	
	while (abs(h2) >= e) { // stops when the h2 value is less than the error
		h2 = f(x2) / dF(x2);
		x2 -= h2;
	}
	
	cout << "\nThe result using the Netwon's Method is:" << endl;
	cout << setprecision(15) << "x1 = " << x1 << ", x2 = " << x2 << endl;

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

	/* Note that an incorrect initial guess can lead to an indetermination or to a wrong value, 
	in this case, of the root that results of g() */

	for (int i = 0; i <= 50; i++) { // during this for loop, the xn value is the g(x(n-1))
		x = g(x);
	}

	for (int i = 0; i <= 50; i++) { // during this for loop, the xn value is the g(x(n-1))
		x_1 = g1(x_1);
	}
	cout << "\nThe result using the Picard-Peano's Method is:" << endl;
	cout << setprecision(15) << "x1 = " << x_1 << ", x2 = " << x << endl;
}

//2 * x * x - x * y - 5 * x + 1 = 0;
//x + 3*log10(x) - y*y = 0;

int main() { 

	solving_formula();
	bissection();
	false_position();
	newton(20, -10);
	picard_peano();
	
	return 0;
}