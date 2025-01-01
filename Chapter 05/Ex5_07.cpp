// EX5_07.CPP
// Using a reference to modify caller arguments
#include <iostream>
using namespace std;

int incr10(int& num);             // Function prototype

int main(void)
{
   int num = 3;
   int value = 6;

   cout << endl
        << "incr10(num) = " << incr10(num);

   cout << endl
        << "num = " << num;

   cout << endl
        << "incr10(value) = " << incr10(value);

   cout << endl
        << "value = " << value;

   cout << endl;
   return 0;
}

// Function to increment a variable by 10
int incr10(int& num)     // Function with reference argument
{
   cout << endl
        << "Value received = " << num;

   num += 10;            // Increment the caller argument - confidently
   return num;           // Return the incremented value
}
