// EX8_05.CPP
// Supplying default values for constructor arguments
#include <iostream>
using namespace std;

class CBox                                   // Class definition at global scope
{
   public:
      double m_Length;                       // Length of a box in inches
      double m_Breadth;                      // Breadth of a box in inches
      double m_Height;                       // Height of a box in inches

      // Constructor definition
      CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0)
      {
         cout << endl << "Constructor called.";
         m_Length = lv;                      // Set values of
         m_Breadth = bv;                     // data members
         m_Height = hv;
      }

      // Function to calculate the volume of a box
      double Volume()
      {
         return m_Length*m_Breadth*m_Height;
      }
};

int main()
{
   CBox box2;                                // Declare box2 - no initial values

   cout << endl
        << "Volume of box2 = "
        << box2.Volume();

   cout << endl;
   return 0;
}

