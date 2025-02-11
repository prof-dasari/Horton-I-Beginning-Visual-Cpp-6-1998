// EX5_02.CPP
// A futile attempt to modify caller arguments
#include <iostream>
using namespace std;

int incr10(int num);             // Function prototype

int main(void)
{
   int num = 3;

   cout << endl
           << "incr10(num) = " << incr10(num)
           << endl
           << "num = " << num;

   cout << endl;
   return 0;
}

// Function to increment a variable by 10
int incr10(int num)        // Using the same name might help...
{
   num += 10;              // Increment the caller argument - hopefully
   return num;             // Return the incremented value
}
