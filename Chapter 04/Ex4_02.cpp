// EX4_02.CPP
// Demonstrating array initialization
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   int value[5] = { 1, 2, 3 };
   int Junk [5];

   cout << endl;
   for(int i=0; i<5; i++)
      cout << setw(12) << value[i];

   cout << endl;
   for(i=0; i<5; i++)
      cout << setw(12) << Junk[i];

   cout << endl;
   return 0;
}
