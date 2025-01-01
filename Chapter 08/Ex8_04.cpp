// EX8_04.CPP
// Supplying and using a default constructor
#include <iostream>
using namespace std;

class CBox                                     // Class definition at global scope
{
   public:
      double m_Length;                         // Length of a box in inches
      double m_Breadth;                        // Breadth of a box in inches
      double m_Height;                         // Height of a box in inches

      CBox(double lv, double bv, double hv)    // Constructor definition
      {
         cout << endl << "Constructor called.";
         m_Length = lv;                        // Set values of
         m_Breadth = bv;                       // data members
         m_Height = hv;
      }

      // Default constructor definition
      CBox()
      { cout << endl << "Default constructor called."; }

      // Function to calculate the volume of a box
      double Volume()
      {
         return m_Length*m_Breadth*m_Height;
      }
};

int main()
{
   CBox box1(78.0,24.0,18.0);                // Declare and initialize box1
   CBox box2;                                // Declare box2 - no initial values
   CBox cigarBox(8.0, 5.0, 1.0);             // Declare and initialize cigarBox

   double boxVolume = 0.0;                   // Store the volume of a box here

   boxVolume = box1.Volume();                // Calculate volume of box1
   cout << endl
        << "Volume of box1 = " << boxVolume;

   box2.m_Height = box1.m_Height - 10;    // Define box2
   box2.m_Length = box1.m_Length / 2.0; // members in
   box2.m_Breadth = 0.25*box1.m_Length;   // terms of box1

   cout << endl
        << "Volume of box2 = "
        << box2.Volume();

   cout << endl
        << "Volume of cigarBox = "
        << cigarBox.Volume();

   cout << endl;
   return 0;
}
