// EX3_09.CPP
// Using multiple counters to show powers of 2
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   long i = 0, power = 0;
   const int max = 10;

   for(i = 0, power = 1; i <= max; i++, power += power)
      cout << endl
           << setw(10) << i << setw(10) << power;     // Loop statement

   cout << endl;
   return 0;
}

