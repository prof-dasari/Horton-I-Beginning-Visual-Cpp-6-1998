// EX4_03.CPP
// Counting string characters
#include <iostream>
using namespace std;

int main()
{
   const int MAX = 80;                // Maximum array dimension
   char buffer[MAX];                  // Input buffer
   int count = 0;                     // Character count

   cout << "Enter a string of less than 80 characters:\n";
   cin.getline(buffer, MAX, '\n');    // Read a string until \n

   while(buffer[count]!= '\0')   // Increment count as long as
      count++;                    // the current character is not null

   cout << endl
        << "The string \"" << buffer
        << "\" has " << count << " characters.";
   
   cout << endl;
   return 0;
}
