// EX10_08.CPP
// Using a base class pointer to call a virtual function
#include <iostream>
using namespace std;

class CBox                               // Base class
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

class CGlassBox: public CBox             // Derived class
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
   CBox myBox(2.0, 3.0, 4.0);            // Declare a base box
   CGlassBox myGlassBox(2.0, 3.0, 4.0);  // Declare derived box of same size
   CBox* pBox = 0;                       // Declare a pointer to base class objects

   pBox = &myBox;                        // Set pointer to address of base object
   pBox->ShowVolume();                   // Display volume of base box
   pBox = &myGlassBox;                   // Set pointer to derived class object
   pBox->ShowVolume();                   // Display volume of derived box

   cout << endl;
   return 0;
}
