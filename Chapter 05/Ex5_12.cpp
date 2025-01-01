// EX5_12.CPP (based on EX5_01.CPP)
// A recursive version of x to the power n
#include <iostream>
#include <cstdlib>                   // This is for the exit() function
using namespace std;

double power(double x, int n);      // Function prototype

int main(void)
{
   int index = 3;           // Raise to this power
   double x = 3.0;          // Different x from that in function power
   double y = 0.0;

   y = power(5.0, 3);           // Passing constants as arguments
   cout << endl
        << "5.0 cubed = " << y;

   cout << endl
        << "3.0 cubed = "
        << power(3.0, index);     // Outputting return value

   x = power(x, power(2.0, 2.0)); // Using a function as an argument
   cout << endl                   // with auto conversion of 2nd parameter
        << "x = " << x;

   cout << endl;
   return 0;
}
// Recursive function to compute integral powers of a double value
// First argument is value, second argument is power index
double power(double x, int n)
{
   if(n<0)
   {
      cout << endl
           << "Negative index, program terminated.";
      exit(1);
   }
   if(n)
      return x*power(x, n-1);
   else
      return 1.0;
}
