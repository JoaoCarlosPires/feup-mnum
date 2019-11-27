#include<stdio.h> 

/* Program to implement Runge Kutta method 
Based on https://www.geeksforgeeks.org/runge-kutta-4th-order-method-solve-differential-equation/ */

// A sample differential equation "dy/dx = (x*x)" 
float dydx(float x) 
{ 
    return (x*x); 
} 
  
// Finds value of y for a given x using step size h and initial value y0 at x0. 
float rungeKutta(float x0, float y0, float x, float h) 
{ 
    // Count number of iterations using step size or step height h 
    int n = (int)((x - x0) / h); 
  
    float k1, k2, k3, k4, k5; 
  
    // Iterate for number of iterations 
    float y = y0; 

    for (int i=1; i<=n; i++) 
    { 
        // Apply Runge Kutta Formulas to find next value of y 
        k1 = h*dydx(x0); 
        k2 = h*dydx(x0 + 0.5*h); 
        k3 = h*dydx(x0 + 0.5*h); 
        k4 = h*dydx(x0 + h); 
  
        // Update next value of y 
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);; 
  
        // Update next value of x 
        x0 = x0 + h; 
    } 
  
    return y; 
} 
  
// Driver method 
int main() 
{ 
    float x0 = 0, y = 1, x = 25, h = 0.001;

    printf("\nThe value of y at x is : %f", rungeKutta(x0, y, x, h));

    return 0; 
}