// EX2_05.CPP
// Exercising the comma operator
#include <iostream>
 
using namespace std;

int main()
{
   long num1 = 0, num2 = 0, num3 = 0, num4 = 0;

   num4 = (num1 = 10, num2 = 20, num3 = 30);
   cout << endl
        << "The value of a series of expressions "
        << "is the value of the right most: "
        << num4;
   cout << endl;

   return 0;
}
