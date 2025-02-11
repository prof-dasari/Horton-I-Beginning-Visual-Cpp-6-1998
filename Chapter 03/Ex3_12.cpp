// EX3_12.CPP
// Using a while loop to compute an average
#include <iostream>

using namespace std;

int main()
{
   double value = 0.0;              // Value entered stored here
   double sum = 0.0;                // Total of values accumulated here
   int i = 0;                       // Count of number of values
   char indicator = 'y';            // Continue or not?

   while(indicator == 'y')          // Loop as long as y is entered
   {
      cout << endl
           << "Enter a value: ";
      cin >> value;                 // Read a value
      ++i;                          // Increment count
      sum += value;                 // Add current input to total

      cout << endl
           << "Do you want to enter another value (enter n to end)? ";
      cin >> indicator;             // Read indicator
   }

   cout << endl
        << "The average of the " << i
        << " values you entered is " << sum/i << "."
        << endl;
   return 0;
}

