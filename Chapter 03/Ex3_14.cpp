// EX3_14.CPP
// Using nested loops to generate a multiplcation table
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   const int size = 12;                  // Size of table
   int i = 0, j = 0;                     // Loop counters

   cout << endl                          // Output table title
        << size << " by " << size
        << " Multiplication Table" << endl << endl;

   cout << endl << "    |";
   for(i=1; i<=size; i++)                // Loop to output column headings
      cout << setw(3) << i << "  ";      

   cout << endl;                         // Newline for underlines
   for(i=0; i<=size; i++)
      cout << "_____";                   // Underline each heading

   for(i=1; i<=size; i++)                // Outer loop for rows
   {
      cout << endl
           << setw(3) << i << " |";      // Output row label

      for(j=1; j<=size; j++)                // Inner loop to output the rest of the row
         cout << setw(3) << i*j << "  ";    // End of inner loop

   }                                     // End of outer loop
   cout << endl;
   return 0;
}
