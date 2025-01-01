// EX6_05.cpp
// Nested try blocks
#include <iostream>
using namespace std;

int main(void)
{
   int Height = 0;
   double InchesToMeters = 0.0254;
   char ch = 'y';

   try                       // Outer try block
   {
      while(ch == 'y'||ch =='Y')
      {
         cout << "Enter a height in inches: "; 
         cin >> Height;        // Read the height to be converted

         try                   // Defines try block in which
         {                     // exceptions may be thrown
            if(Height > 100)
               throw "Height exceeds maximum";   // Exception thrown
            if(Height < 9)
               throw Height;                     // Exception thrown

               cout << (double)Height*InchesToMeters 
                    << " meters" << endl;

               cout << "Do you want to continue(y or n)?";
               cin >> ch;
         }

         catch(char* aMessage)      // start of catch block which
         {                          // catches exceptions of type char*
            cout << aMessage << endl;
         }
      }
   }
   catch(int BadHeight)
   {
      cout << BadHeight << " inches is below minimum" << endl;
   }
   return 0;
}
