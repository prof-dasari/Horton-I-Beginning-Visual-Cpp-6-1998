// EX3_07.CPP
// Creating a loop with an if and a goto
#include <iostream>

using namespace std;

int main()
{
   int i = 0, sum = 0;
   const int max = 10;

   i = 1;
loop:
   sum += i;             // Add current value of i to sum
   if(++i <= max)
      goto loop;         // Go back to loop until i = 11

   cout << endl
        << "sum = " << sum
        << endl
        << "i = " << i
        << endl;
   return 0;
}
