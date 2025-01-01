// EX3_06.CPP
// Multiple case actions
#include <iostream>

using namespace std;

int main()
{
   char letter = 0;
   cout << endl
        << "Enter a small letter: ";
   cin >> letter;

   switch(letter*(letter>='a' && letter <='z'))
   {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u': cout << endl << "You entered a vowel.";
                break;

      case 0: cout << endl << "It is not a small letter.";
              break;

      default: cout << endl << "You entered a consonant.";
   }
   cout << endl;
   return 0;
}
