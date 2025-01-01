// EX3_08.CPP
// Summing integers with a for loop
#include <iostream>

using namespace std;

int main()
{
   int i = 0, sum = 0;
   const int max = 10;

   for(i = 1; i <= max; i++)       // Loop specification
      sum += i;                    // Loop statement

   cout << endl
        << "sum = " << sum
        << endl
        << "i = " << i
        << endl;
   return 0;
}
