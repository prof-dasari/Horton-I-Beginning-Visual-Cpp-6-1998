// EX8_10.CPP
// Using an array of class objects
#include <iostream>
using namespace std;

class CBox                             // Class definition at global scope
{
   public:
      // Constructor definition
      CBox(double lv, double bv = 1.0, double hv = 1.0): m_Length(lv),
                                                         m_Breadth(bv),
                                                         m_Height(hv)
      { 
         cout << endl << "Constructor called.";
      }

      CBox()                                 // Default constructor
      {
         cout << endl
              << "Default constructor called.";
         m_Length = m_Breadth = m_Height = 1.0;
      }

      // Function to calculate the volume of a box
      double Volume() const
      {
         return m_Length*m_Breadth*m_Height;
      }

   private:
      double m_Length;                       // Length of a box in inches
      double m_Breadth;                      // Breadth of a box in inches
      double m_Height;                       // Height of a box in inches

};

int main()
{
   CBox boxes[5];                           // Array of CBox objects declared
   CBox cigar(8.0, 5.0, 1.0);                // Declare cigar box

   cout << endl
        << "Volume of boxes[3] = " << boxes[3].Volume()
        << endl
        << "Volume of cigar = " << cigar.Volume();

   cout << endl;
   return 0;
}
