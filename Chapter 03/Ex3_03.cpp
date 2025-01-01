// EX3_03.CPP
// Testing for a letter using logical operators
#include <iostream>

using namespace std;

int main()
{
   char letter = 0;                              // Store input in here

   cout << endl
        << "Enter a character: ";
   cin >> letter;

   if(((letter>='A')&&(letter<='Z')) ||
      ((letter>='a')&&(letter<='z')))            // Test for alphabetic
      cout << endl
           << "You entered a letter." << endl;
   else
      cout << endl
           << "You didn't enter a letter." << endl;
   return 0;
}

