// EX10_07.CPP (based on Ex10_06.cpp)
// Using a virtual function 
#include <iostream>
using namespace std;

// Listing 10_06-01
class CBox               // Base class
{
   public:

      // Function to show the volume of an object
      void ShowVolume() const
      {
         cout << endl
              << "CBox usable volume is " << Volume(); 
      }

      // Function to calculate the volume of a CBox object
      virtual double Volume() const
      { return m_Length*m_Breadth*m_Height; }

      // Constructor
      CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0)
                            :m_Length(lv), m_Breadth(bv), m_Height(hv) {}

   protected:
      double m_Length;
      double m_Breadth;
      double m_Height;
};


// Listing 10_06-02
class CGlassBox: public CBox       // Derived class
{
   public:

      // Function to calculate volume of a CGlassBox
      // allowing 15% for packing
      virtual double Volume() const
      { return 0.85*m_Length*m_Breadth*m_Height; }

      // Constructor
      CGlassBox(double lv, double bv, double hv): CBox(lv, bv, hv){}
};


int main()
{
   CBox myBox(2.0, 3.0, 4.0);              // Declare a base box
   CGlassBox myGlassBox(2.0, 3.0, 4.0);    // Declare derived box - same size

   myBox.ShowVolume();                     // Display volume of base box
   myGlassBox.ShowVolume();                // Display volume of derived box

   cout << endl;
   return 0;
}
