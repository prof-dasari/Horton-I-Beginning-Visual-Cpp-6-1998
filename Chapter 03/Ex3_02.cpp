// EX3_02.CPP
// Using the extended if
#include <iostream>

using namespace std;

int main()
{
   long number = 0;               // Store input here
   cout << endl
        << "Enter an integer number less than 2 billion: ";
   cin >> number;

   if(number%2L)                  // Test remainder after division by 2
      cout << endl                // Here if remainder 1
           << "Your number is odd." << endl;
   else
      cout << endl                // Here if remainder 0
           << "Your number is even." << endl;
   return 0;
}
