#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
  double n = -1;
  
  while (n < 0) { // while loop to check if the number is positive
    cout << "What is your number? ";
    cin >> n;
  }

  for (double i = -n; i <= n; i += 0.000001) { // this for loop calculates the square root using an iterative formula
    if ((i * i) - n <= 0.0000001) {
      cout << "Alternative calc: " << "\t" << setprecision(30) << i << " and " << -i << endl;
      cout << "Using sqrt:       " << "\t" << setprecision(30) << -sqrt(n) << " and " << sqrt(n) << endl;
      // prints the difference between both calc methods
      cout << "Difference:       " << "\t" << setprecision(30) << fabs(-i - sqrt(n)); 
      return 0;
    }
  }

  return 1;
}
