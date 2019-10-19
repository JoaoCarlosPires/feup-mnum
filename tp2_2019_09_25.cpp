#include <iostream>
#include <math.h>

using namespace std;

int main ()
{
  double n = -1;
  while (n < 0)
    {
      cout << "What is your number? ";
      cin >> n;
    }
  for (double i = -n; i <= n; i += 0.000001)
    {
      if ((i * i) - n <= 0.0000001)
	{
	  cout << "Alternative calc:" << "\t" << i << " and " << -i << endl;
	  cout << "Using sqrt:      " << "\t" << -sqrt (n) << " and " <<
	    sqrt (n) << endl;
	  cout << fabs (i - sqrt (n));
	  return 1;
	}
    }

  return 0;
}
