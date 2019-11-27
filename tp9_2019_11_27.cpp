#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

/* Program to find approximation of a ordinary differential equation using euler's method.
Based on https://www.geeksforgeeks.org/euler-method-solving-differential-equation/ */

// Consider the differential equation dy/dx=(x*x)
float func(float x)
{
    return (x * x);
}

// Function for Euler formula
float euler(float x0, float y, float h, float x)
{
    float temp = 0;

    // Iterating till the point at which we need approximation
    while (x0 < x)
    {
        temp = y;
        y += h * func(x0);
        x0 += h;
    }

    return y;
}

int main()
{
    // Initial Values
    float x0 = -2;
    float y0 = -5.0 / 3;
    float h = 0.001;
    float y;

    // Value of x at which we need approximation
    float x = 25;

    y = euler(x0, y0, h, x);
    // Printing approximation
    cout << setprecision(10) << "For h = " << h << ", the approximate solution at x = " << x << " is " << y << endl;

    y = euler(x0, y0, h / 2, x);
    // Printing approximation
    cout << setprecision(10) << "For h = " << h / 2 << ", the approximate solution at x = " << x << " is " << y << endl;

    y = euler(x0, y0, h / 4, x);
    // Printing approximation
    cout << setprecision(10) << "For h = " << h / 4 << ", the approximate solution at x = " << x << " is " << y << endl;

    cout << setprecision(10) << "\nThe error is: " << (euler(x0, y0, h / 2, x) - euler(x0, y0, h, x)) / (euler(x0, y0, h / 4, x) - euler(x0, y0, h / 2, x)) << endl;

    return 0;
}