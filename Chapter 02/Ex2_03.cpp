// EX2_03.CPP
// Exercising output
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   int num1 = 1234, num2 = 5678;
   cout << endl;                                //Start on a new line
   cout << setw(6) << num1 << setw(6) << num2;  //Output two values
   cout << endl;                                //Start on a new line
   return 0;                                    //Exit program
}
