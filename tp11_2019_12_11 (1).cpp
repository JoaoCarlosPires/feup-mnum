#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
Program to calculate the minimum of a function using Gradient's Method 
Program based on other's creation
Credits to MIEIC Google Drive program
*/ 

double f(double x, double y)
{
	return x*x + y*y;
}

double fderx(double x, double y)
{
	return 2 * x;
}

double fdery(double x, double y)
{
	return 2 * y;
}

void gradient(double f(double, double), double x, double y, double h, int numIt)
{
	double xn, yn;

	cout << "f(x0, y0): " << f(x, y) << endl;

	for (int i = 0; i < numIt; ++i)
	{
		xn = x - h * fderx(x, y);
		yn = y - h * fdery(x, y);

		if (!(f(xn, yn) < f(x, y)))
			h /= 2;
		else
		{
			x = xn;
			y = yn;
			h *= 2;
		}

		cout << "fderx(xn,yn): " << fderx(xn, yn) << endl;
		cout << "fdery(xn, yn): " << fdery(xn, yn) << endl;
		cout << "xn: " << xn << endl;
		cout << "yn: " << yn << endl;
		cout << "f(xn, yn): " << f(xn, yn) << endl;
	}
}

int main()
{
	cout << fixed << setprecision(10);

	gradient(f, 1.0, 1.0, 0.5, 1);

	return 0;
}