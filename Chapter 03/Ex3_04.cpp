// EX3_04.CPP
// The conditional operator selecting output
#include <iostream>

using namespace std;

int main()
{
   int nCakes = 1;           // Count of number of cakes

   cout << endl
        << "We have " << nCakes << " cake" << ((nCakes>1) ? "s." : ".")
        << endl;

   ++nCakes;

   cout << endl
        << "We have " << nCakes << " cake" << ((nCakes>1) ? "s." : ".")
        << endl;
   return 0;
}
