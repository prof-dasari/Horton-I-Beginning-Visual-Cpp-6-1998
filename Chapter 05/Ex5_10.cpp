// EX5_10.CPP
// Returning a reference
#include <iostream>
#include <iomanip>
using namespace std;

double& lowest(double A[], int len);  // Prototype of function
                                      // returning a reference

int main(void)
{
   double array[] = { 3.0, 10.0, 1.5, 15.0, 2.7, 23.0,
                      4.5, 12.0, 6.8, 13.5, 2.1, 14.0 };
   int len = sizeof array/sizeof array[0]; // Initialize to number
                                           // of elements

   cout << endl;
   for(int i = 0; i<len; i++)
      cout << setw(6) << array[i];

   lowest(array, len) = 6.9;               // Change lowest to 6.9
   lowest(array, len) = 7.9;               // Change lowest to 7.9

   cout << endl;
   for(i = 0; i<len; i++)
      cout << setw(6) << array[i];

   cout << endl;
   return 0;
}

double& lowest(double A[], int len)
{
   int j=0;                       // Index of lowest element
   for(int i=1; i<len; i++)
      if(A[j]>A[i])               // Test for a lower value...
         j = i;                   // ...if so update j
   return A[j];                   // Return reference to lowest element
}
