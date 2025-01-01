// EX3_11.CPP
// Display ASCII codes for alphabetic characters
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   for(char capital='A', small='a'; capital<='Z'; capital++, small++)
      cout << endl
           << "\t" << capital                              // Output capital as character
           << hex << setw(10) << static_cast<int>(capital) // Output capital as hex
           << dec << setw(10) << static_cast<int>(capital) // Output capital as decimal
           << "    " << small                              // Output small as character
           << hex << setw(10) << static_cast<int>(small)   // Output small as hex
           << dec << setw(10) << static_cast<int>(small);  // Output small as decimal

   cout << endl;
   return 0;
}
