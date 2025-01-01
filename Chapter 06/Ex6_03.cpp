//EX6_03.CPP
// Omitting function arguments
#include <iostream>
using namespace std;

void showit(char* = "Something is wrong.");

int main(void)
{
   char* mymess = "The end of the world is nigh.";

   showit();                               // Display the basic message
   showit("Something is terribly wrong!"); // Display an alternative
   showit();                               // Display the default again
   showit(mymess);                         // Display a predefined message

   cout << endl;
   return 0;
}

void showit(char* message)
{
   cout << endl
        << message;
   return;
}
