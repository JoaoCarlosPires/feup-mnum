#include <stdio.h>
#include <math.h> 

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
  
int main() 
{ 
    float x0 = -2, y = -5.0/3, x = 25;
    float h = 0.001;

    printf("\nFor h = %f, the value of y at x is : %f", h, rungeKutta(x0, y, x, h));

    printf("\nFor h = %f, the value of y at x is : %f", h/2, rungeKutta(x0, y, x, h/2));
    
    printf("\nFor h = %f, the value of y at x is : %f", h/4, rungeKutta(x0, y, x, h/4));

    printf("\n\nThe error is : %f", (rungeKutta(x0, y, x, h/2)-rungeKutta(x0, y, x, h))/(rungeKutta(x0, y, x, h/4)-rungeKutta(x0, y, x, h/2)));

    return 0; 
}