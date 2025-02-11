// EX8_08.CPP
// Initializing an object with an object of the same class
#include <iostream>
using namespace std;

class CBox                              // Class definition at global scope
{
   public:

      // Constructor definition
   CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0): m_Length(lv),
                                                            m_Breadth(bv),
                                                            m_Height(hv)
      {
         cout << endl << "Constructor called.";
      }

      // Function to calculate the volume of a box
      double Volume()
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
   CBox box1(78.0, 24.0, 18.0);
   CBox box2 = box1;                         // Initialize box2 with box1

   cout << endl
        << "box1 volume = " << box1.Volume()
        << endl
        << "box2 volume = " << box2.Volume();

   cout << endl;
   return 0;
}

