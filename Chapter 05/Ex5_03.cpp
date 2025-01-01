// EX5_03.CPP
// A successful attempt to modify caller arguments
#include <iostream>
using namespace std;

int incr10(int* num);               // Function prototype

int main(void)
{
   int num = 3;
   int* pnum = &num;                // Pointer to num

   cout << endl
        << "Address passed = " << pnum;

   cout << endl
        << "incr10(pnum) = " << incr10(pnum);

   cout << endl
        << "num = " << num;

   cout << endl;
   return 0;
}

// Function to increment a variable by 10
int incr10(int* num)        // Function with pointer argument
{
   cout << endl
        << "Address received = " << num;

   *num += 10;              // Increment the caller argument - confidently
   return *num;             // Return the incremented value
}
