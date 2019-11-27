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
void euler(float x0, float y, float h, float x)
{
    float temp = 0;

    // Iterating till the point at which we need approximation
    while (x0 < x)
    {
        temp = y;
        y += h * func(x0);
        x0 += h;

        // Printing approximation
        cout << "Approximate solution at x = " << x0 << " is " << y << endl;
    }
}

int main()
{
    // Initial Values
    float x0 = -2;
    float y0 = -5.0 / 3;
    float h = 0.001;

    // Value of x at which we need approximation
    float x = 25;

    euler(x0, y0, h, x);
    return 0;
}