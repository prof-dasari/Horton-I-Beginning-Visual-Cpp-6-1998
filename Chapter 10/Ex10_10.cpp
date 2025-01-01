// EX10_10.CPP
// Using an abstract class
#include <iostream>                    // For stream I/O
using namespace std;

const double PI= 3.14159265;           // Global definition for PI

// Listing 10_10-01
class CContainer           // Generic base class for specific containers
{
   public:

      // Function for calculating a volume - no content
      // This is defined as a 'pure' virtual function, signified by '= 0'
      virtual double Volume() const = 0;

      // Function to display a volume
      virtual void ShowVolume() const
      {
         cout << endl
              << "Volume is " << Volume();
      }
};

// Listing 10_10-02
class CBox: public CContainer          // Derived class
{
   public:

      // Function to show the volume of an object
      virtual void ShowVolume() const
      {
         cout << endl
              << "CBox usable volume is " << Volume(); 
      }

      // Function to calculate the volume of a CBox object
      virtual double Volume() const
      { return m_Length*m_Breadth*m_Height; }

      // Constructor
      CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0)
                             :m_Length(lv), m_Breadth(bv), m_Height(hv){}

   protected:
      double m_Length;
      double m_Breadth;
      double m_Height;
};

// Listing 10_10-03
class CCan: public CContainer
{
   public:

      // Function to calculate the volume of a can
      virtual double Volume() const
      { return 0.25*PI*m_Diameter*m_Diameter*m_Height; }

      // Constructor
      CCan(double hv = 4.0, double dv = 2.0): m_Height(hv), m_Diameter(dv){}

   protected:
      double m_Height;
      double m_Diameter;
};


int main(void)
{
   // Pointer to abstract base class
   // initialized with address of CBox object
   CContainer* pC1 = new CBox(2.0, 3.0, 4.0);

   // Pointer to abstract base class
   // initialized with address of CCan object
   CContainer* pC2 = new CCan(6.5, 3.0);

   pC1->ShowVolume();                  // Output the volumes of the two
   pC2->ShowVolume();                  // objects pointed to
   cout << endl;

   delete pC1;                         // Now clean up the free store
   delete pC2;                         // ....

   return 0;
}
